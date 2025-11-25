// programa principal do projeto "The Boys - 2024/2"
// Autor: Ramon Cesar Santos Alves, GRR 20204080

// seus #includes vão aqui
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "theboys.h" /*defines adicionados aqui*/
/
// seus #defines vão aqui
/* defines adicionados em theboys.h*/
// minimize o uso de variáveis globais


// programa principal
int main ()
{
    // iniciar o mundo
    srand(0);

    // 1. Cria o mundo
    struct mundo *world = cria_mundo();
    if (!world) {
        fprintf(stderr, "Erro ao criar o mundo.\n");
        return 1;
    }

    // Cria a fila de prioridades (LEF)
    struct fprio_t *fila_eventos = fprio_cria();
    if (!fila_eventos) {
        fprintf(stderr, "Erro ao criar fila de prioridades.\n");
        return 1;
    }

    // --- 2. Popular o mundo e Eventos Iniciais ---

    // A. Criar Heróis e agendar chegada (EV_CHEGA)
    // Especificação: Base aleatória [0...N_BASES-1], Tempo aleatório [0...4320]
    for (int i = 0; i < N_HEROIS; i++) {
        struct heroi *h = adiciona_heroi(world);
        if (!h) continue;

        struct evento *ev = malloc(sizeof(struct evento));
        if (ev) {
            ev->tipo = EV_CHEGA;
            
            // CORREÇÃO: Chegada nos primeiros 3 dias (3 * 24 * 60 = 4320 minutos)
            ev->tempo = aleat(0, 4320); 
            
            ev->dado1 = h->ID;
            
            // CORREÇÃO: Base aleatória válida
            ev->dado2 = aleat(0, N_BASES - 1);
            
            fprio_insere(fila_eventos, ev, EV_CHEGA, ev->tempo);
        }
    }

    // B. Criar Bases
    for (int i = 0; i < N_BASES; i++){
        adiciona_base(world);
    }

    // C. Criar Missões e agendar (EV_MISSAO)
    // Especificação: Tempo aleatório [0...T_FIM_DO_MUNDO]
    for (int i = 0; i < N_MISSOES; i++){
        struct missao *m = adiciona_missao(world);
        if (!m) continue;
        
        struct evento *ev_m = malloc(sizeof(struct evento));
        if (ev_m) {
            ev_m->tipo = EV_MISSAO;
            ev_m->tempo = aleat(0, T_FIM_DO_MUNDO); // Qualquer momento da simulação
            ev_m->dado1 = m->ID; 
            ev_m->dado2 = -1; // Missões não têm base destino fixa na criação
            
            fprio_insere(fila_eventos, ev_m, EV_MISSAO, ev_m->tempo);
        }
    }

    // D. Agendar o Fim do Mundo (EV_FIM)
    // Especificação: Tempo = T_FIM_DO_MUNDO
    struct evento *ev_fim = malloc(sizeof(struct evento));
    if (ev_fim) {
        ev_fim->tipo = EV_FIM;
        ev_fim->tempo = T_FIM_DO_MUNDO;
        ev_fim->dado1 = 0;
        ev_fim->dado2 = 0;
        fprio_insere(fila_eventos, ev_fim, EV_FIM, ev_fim->tempo);
    }

    // executar o laço de simulação

    void *item;
    int tipo, prio;

    // Processa eventos enquanto a fila não estiver vazia
    while ((item = fprio_retira(fila_eventos, &tipo, &prio)) != NULL)
    {
        struct evento *ev = (struct evento*) item;
        
        // Atualiza o relógio do mundo e contadores
        world->relogio = prio;
        world->n_eventos++;

        // Verifica se passou do tempo limite (segurança)
        if (world->relogio > T_FIM_DO_MUNDO) {
            free(ev);
            break;
        }

        switch (tipo)
        {
            case EV_CHEGA:
                chega(world, fila_eventos, ev);
                break;
            case EV_ESPERA:
                espera(world, fila_eventos, ev);
                break;
            case EV_DESISTE:
                desiste(world, fila_eventos, ev);
                break;
            case EV_AVISA:
                avisa(world, fila_eventos, ev);
                break;
            case EV_ENTRA:
                entra(world, fila_eventos, ev);
                break;
            case EV_SAI:
                evento_sai(prio, ev->dado1, ev->dado2, world, fila_eventos);
                break;
            case EV_VIAJA:
                evento_viaja(prio, ev->dado1, ev->dado2, world, fila_eventos);
                break;
            case EV_MORRE:
                evento_morre(prio, ev->dado1, ev->dado2, world, fila_eventos);
                break;
            case EV_MISSAO:
                evento_missao(prio, ev->dado1, world, fila_eventos);
                break;
            case EV_FIM:
                evento_fim(prio, world);
                free(ev); // Libera o evento FIM
                
                // Encerra o loop e o programa
                fprio_destroi(fila_eventos);
                destroi_mundo(world);
                return 0; 
            
            default:
                printf("Evento desconhecido: %d\n", tipo);
                break;
        }

        // Libera a memória do evento processado
        free(ev);
    }

    // destruir o mundo
    fprio_destroi(fila_eventos);
    destroi_mundo(world);

    return 0;
}