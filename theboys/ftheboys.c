// Implementação das funções do projeto "The Boys"
// ftheboys.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "theboys.h"

// --- Funções Auxiliares Internas ---
/*função aleatória utilizada em tp1*/
int aleat(int min, int max) {
    if (min == max) return min;
    return min + (rand() % (max - min + 1));
}

/*criamos heroi aleatório*/
static struct heroi *cria_heroi_aleatorio(int id) {
    struct heroi *h = malloc(sizeof(struct heroi));
    if (!h) 
        return NULL;

    h->ID = id;
    h->experiencia = 0;
    h->Paciencia = aleat(0, 100);
    h->Velocidade = aleat(50, 5000);
    /*Evita criar o heroi em uma base*/
    h->Base = -1; 
    /*Necessário para verificações de morte*/
    h->vivo = 1;

    int n_hab = aleat(1, 3);
    h->Habilidades = cjto_aleat(n_hab, MAX_HABILIDADES);
    
    // Proteção se cjto_aleat falhar
    if (!h->Habilidades) {
        free(h);
        return NULL;
    }

    return h;
}

static struct base *cria_base_aleatoria(int id, int max_x, int max_y)
{
    struct base *b = malloc(sizeof(struct base));
    if (!b) 
        return NULL;

    b->ID = id;
    /*Escolha entre 3 a 10*/
    b->Lotacao = aleat(3, 10);
    /*Escolha do local da base*/
    b->local_x = aleat(0, max_x - 1); 
    b->local_y = aleat(0, max_y - 1);

    b->n_missoes = 0;

    /*Criamos conjunto de herois presentes*/
    b->presentes = cjto_cria(MAX_HEROIS);
    
    /*Criamos a fila de espera*/
    b->Espera = fila_cria();
    b->max_fila = 0; 

    if (!b->presentes || !b->Espera) {
        if (b->presentes) 
            cjto_destroi(b->presentes);
        if (b->Espera) 
            fila_destroi(b->Espera);
        free(b);
            return NULL;
    }

    return b;
}
static struct missao *cria_missao_aleatoria(int id, int max_x, int max_y) {
    struct missao *m = malloc(sizeof(struct missao));
    if (!m) 
        return NULL;

    m->ID = id;

    /*Definição do Local*/
    m->local_x = aleat(0, max_x - 1); /*max - 1 para garantir o intervalo 0..19*/
    m->local_y = aleat(0, max_y - 1);

    m->total_tentativas = 0;

    /*escolha aleatório das habilidades*/
    int n_hab;
        n_hab = aleat(6, 10);
    
    m->Habilidades = cjto_aleat(n_hab, MAX_HABILIDADES);
    
    /*conferimos a existência de habilidades*/
    if (!m->Habilidades) {
        free(m);
        return NULL;
    }

    return m;
}

/* Funções de Criação e Destruição */

struct mundo *cria_mundo() {
    struct mundo *w = malloc(sizeof(struct mundo));
    if (!w) 
        return NULL;

    w->NHerois = 0;
    w->NBases = 0;
    w->NMissoes = 0;
    w->relogio = T_INICIO;
    w->TamanhoMundoX = N_TAMANHO_MUNDO;
    w->TamanhoMundoY = N_TAMANHO_MUNDO;
    w->n_eventos = 0;
    w->NCompostosV = 20;

    /*Estatísticas*/
    w->missoes_cumpridas = 0;
    w->total_tentativas = 0;
    w->max_tentativas = 0;
    w->min_tentativas = 999999;

    /*Preparamos o campo para as entidades*/
    for (int i = 0; i < MAX_HEROIS; i++) 
        w->H[i] = NULL;
    for (int i = 0; i < MAX_BASES; i++)  
        w->B[i] = NULL;
    for (int i = 0; i < MAX_MISSOES; i++) 
        w->M[i] = NULL;

    return w;
}

struct heroi *adiciona_heroi(struct mundo *w) {
    if (w->NHerois >= MAX_HEROIS) 
        return NULL;

    struct heroi *h;
        h = cria_heroi_aleatorio(w->NHerois);
    if (h) 
        w->H[w->NHerois++] = h;
    return h;
}

struct base *adiciona_base(struct mundo *w)
{
    if (!w || w->NBases >= MAX_BASES) 
        return NULL;

    /*Usamos as dimensões do mundo para base*/
    struct base *nova;
        nova = cria_base_aleatoria(w->NBases, w->TamanhoMundoX, w->TamanhoMundoY);
    
    if (nova) {
        w->B[w->NBases] = nova;
        w->NBases++;
    }

    return nova;
}

struct missao *adiciona_missao(struct mundo *w) {
    if (!w || w->NMissoes >= MAX_MISSOES) 
        return NULL;
    
    /*Passa as dimensões e o ID sequencial atual*/
    struct missao *m = cria_missao_aleatoria(w->NMissoes, w->TamanhoMundoX, w->TamanhoMundoY);
    
    if (m) {
        w->M[w->NMissoes] = m;
        w->NMissoes++; // Incrementa para o próximo ID ser sequencial
    }
    return m;
}

void destroi_heroi(struct heroi *h) {
    if (h) {
        cjto_destroi(h->Habilidades);
        free(h);
    }
}

void destroi_base(struct base *b) {
    if (b) {
        cjto_destroi(b->presentes);
        fila_destroi(b->Espera);
        free(b);
    }
}

void destroi_missao(struct missao *m) {
    if (m) {
        cjto_destroi(m->Habilidades);
        free(m);
    }
}

struct mundo *destroi_mundo(struct mundo *w) {
    if (!w) return NULL;
    for (int i = 0; i < w->NHerois; i++) 
        destroi_heroi(w->H[i]);
    for (int i = 0; i < w->NBases; i++)  
        destroi_base(w->B[i]);
    for (int i = 0; i < w->NMissoes; i++) 
        destroi_missao(w->M[i]);
    free(w);
    return NULL;
}

struct evento *cria_evento(int tempo, int tipo, int dado1, int dado2) {
    struct evento *ev;
    ev = malloc(sizeof(struct evento));

    if (ev) {
        ev->tempo = tempo;
        ev->tipo = tipo;
        ev->dado1 = dado1;
        ev->dado2 = dado2;
    }
    return ev;
}

/*Implementação de Eventos*/

void chega(struct mundo *w, struct fprio_t *lef, struct evento *ev) {
    int id_heroi = ev->dado1;
    int id_base = ev->dado2;
    struct heroi *h = w->H[id_heroi];
    struct base *b = w->B[id_base]; //


    /*Evitamos EV_ESPERA ou EV_DESISTE*/ 
    if (!h->vivo) 
        return; 

    /*Atualiza base atual do herói (sem conjunto)*/
    h->Base = id_base;

    bool espera = false;
    int ocupacao = cjto_card(b->presentes);
    bool vaga = (ocupacao < b->Lotacao);
    bool fila_vazia = (fila_tamanho(b->Espera) == 0);

    /*Esperar ou Desistir*/
    if (vaga && fila_vazia) {
        espera = true;
    } 
    else {
        if (h->Paciencia > (10 * fila_tamanho(b->Espera))) /*lógica para permanência*/
            espera = true;
    }

    struct evento *novo = cria_evento(w->relogio, 0, id_heroi, id_base);
    if (!novo) 
        return;

    if (espera) {
        novo->tipo = EV_ESPERA;
        fprio_insere(lef, novo, EV_ESPERA, w->relogio);
        /*linha muito grande, foi quebrada para facilitar leitura*/
        printf("%6d: CHEGA HEROI %2d BASE %d (%2d/%2d) ESPERA\n",
               w->relogio, id_heroi, id_base, ocupacao, b->Lotacao);
    } 
    else {
        novo->tipo = EV_DESISTE;
        fprio_insere(lef, novo, EV_DESISTE, w->relogio);
        printf("%6d: CHEGA HEROI %2d BASE %d (%2d/%2d) DESISTE\n",
               w->relogio, id_heroi, id_base, ocupacao, b->Lotacao);
    }
}

void desiste(struct mundo *w, struct fprio_t *lef, struct evento *ev) {
    int id_heroi = ev->dado1;
    int id_base = ev->dado2;

    printf("%6d: DESIST HEROI %2d BASE %d\n", w->relogio, id_heroi, id_base);

    int id_destino = aleat(0, w->NBases - 1);
    struct evento *viagem = cria_evento(w->relogio, EV_VIAJA, id_heroi, id_destino);
    /*quando desistimos criamos novo evento*/
    if (viagem) 
        fprio_insere(lef, viagem, EV_VIAJA, w->relogio);
}

void espera(struct mundo *w, struct fprio_t *lef, struct evento *ev) {
    int id_heroi;
    int id_base;
    struct base *b;
    int tam;

    id_heroi= ev->dado1;
    id_base = ev->dado2;
    b = w->B[id_base];

    printf("%6d: ESPERA HEROI %2d BASE %d (%2d)\n",
           w->relogio, id_heroi, id_base, fila_tamanho(b->Espera));

    fila_insere(b->Espera, id_heroi);
    
    /*Atualiza estatística (fila máxima)*/
    tam = fila_tamanho(b->Espera);
    if (tam > b->max_fila) 
        b->max_fila = tam;

    struct evento *aviso = cria_evento(w->relogio, EV_AVISA, 0, id_base);
    if (aviso) 
        fprio_insere(lef, aviso, EV_AVISA, w->relogio);
}

void avisa(struct mundo *w, struct fprio_t *lef, struct evento *ev) {
    int id_base;
    struct base *b;
    id_base = ev->dado2;
    b = w->B[id_base];

    /*printf muito longo, por isso quebrei em duas linhas*/
    printf("%6d: AVISA PORTEIRO BASE %d (%2d/%2d) ", 
        w->relogio, id_base, cjto_card(b->presentes), b->Lotacao);

    fila_imprime(b->Espera);

    while (cjto_card(b->presentes) < b->Lotacao && fila_tamanho(b->Espera) > 0) {
        int id_adm;
        fila_retira(b->Espera, &id_adm);
        /*inserimos o heroi no conjunto de presentes*/
        cjto_insere(b->presentes, id_adm);

        printf("%6d: AVISA PORTEIRO BASE %d ADMITE %2d\n", w->relogio, id_base, id_adm);

        struct evento *entra = cria_evento(w->relogio, EV_ENTRA, id_adm, id_base);
        if (entra) 
            fprio_insere(lef, entra, EV_ENTRA, w->relogio);
    }
}

void entra(struct mundo *w, struct fprio_t *lef, struct evento *ev) {

    int id_heroi;
    int id_base;
    struct heroi *h;
    struct base *b;

    id_heroi = ev->dado1;
    id_base = ev->dado2;
    h = w->H[id_heroi];
    b = w->B[id_base];

    /*Evitamos a escolha de um heroi inexistente*/
    if (!h->vivo) 
        return;

    /*Usamos a lógica sujerida no trabalho*/
    int tpb = 15 + h->Paciencia * aleat(1, 20);
    int tempo_saida = w->relogio + tpb;

    /*printf muito longo, por isso quebrei em duas linhas*/
    printf("%6d: ENTRA HEROI %2d BASE %d (%2d/%2d) SAI %d\n",
        w->relogio, id_heroi, id_base, cjto_card(b->presentes), b->Lotacao, tempo_saida);

    struct evento *sai = cria_evento(tempo_saida, EV_SAI, id_heroi, id_base);
    if (sai) 
        fprio_insere(lef, sai, EV_SAI, tempo_saida);
}

void evento_sai(int tempo, int id_heroi, int id_base, struct mundo *w, struct fprio_t *lef) {

    struct heroi *h;

    h = w->H[id_heroi];

    if (!h->vivo) 
        return; 

    struct base *b = w->B[id_base];

    cjto_retira(b->presentes, id_heroi);
    printf("%6d: SAI HEROI %2d BASE %d (%2d/%2d)\n",
           tempo, id_heroi, id_base, cjto_card(b->presentes), b->Lotacao);

    int id_dest = aleat(0, w->NBases - 1);
    struct evento *viagem = cria_evento(tempo, EV_VIAJA, id_heroi, id_dest);
    if (viagem) 
        fprio_insere(lef, viagem, EV_VIAJA, tempo);

    /* Avisa que há vaga*/
    struct evento *aviso;
    aviso = cria_evento(tempo, EV_AVISA, 0, id_base);

    if (aviso)
        fprio_insere(lef, aviso, EV_AVISA, tempo);
}

void evento_viaja(int tempo, int id_heroi, int id_destino, struct mundo *w, struct fprio_t *lef) {
    struct heroi *h = w->H[id_heroi];

    /* viaja e evita acesso a Base -1 */
    if (!h->vivo)  
        return;

    int id_origem;
    id_origem = h->Base;
    
    
    // Verificação de segurança adicional
    if (id_origem < 0 || id_origem >= w->NBases)
        return;

    struct base *b_orig;
    struct base *b_dest;

    b_orig = w->B[id_origem];
    b_dest = w->B[id_destino];

    /*Distância Euclidiana*/
    double delta_x;
    double delta_y;
    int dist;

    delta_x = (double)(b_dest->local_x - b_orig->local_x);
    delta_y = (double)(b_dest->local_y - b_orig->local_y);
    dist = (int)sqrt(delta_x * delta_x + delta_y * delta_y);

    /*Duração*/
    int duracao;
    duracao = dist / h->Velocidade;
    
    if (duracao < 1) duracao = 1; 

    int tempo_chegada = tempo + duracao;

    printf("%6d: VIAJA HEROI %2d BASE %d BASE %d DIST %d VEL %d CHEGA %d\n",
           tempo, id_heroi, id_origem, id_destino, dist, h->Velocidade, tempo_chegada);

    struct evento *chega = cria_evento(tempo_chegada, EV_CHEGA, id_heroi, id_destino);
    if (chega) fprio_insere(lef, chega, EV_CHEGA, tempo_chegada);
}
void evento_morre(int tempo, int id_heroi, int id_base, struct mundo *w, struct fprio_t *lef) {
    struct heroi *h = w->H[id_heroi];
    struct base *b = w->B[id_base];

    cjto_retira(b->presentes, id_heroi);
    h->vivo = 0;
    h->Base = -1;

    printf("%6d: MORRE HEROI %2d BASE %d\n", tempo, id_heroi, id_base);

    // Avisa porteiro (abriu vaga por morte)
    struct evento *aviso = cria_evento(tempo, EV_AVISA, 0, id_base);
    if (aviso) fprio_insere(lef, aviso, EV_AVISA, tempo);
}

void evento_missao(int tempo, int id_missao, struct mundo *w, struct fprio_t *lef) {
    struct missao *m = w->M[id_missao];
    struct base *bmp = NULL;

    // --- Variáveis auxiliares declaradas no início para evitar erro de escopo ---
    int id_bmp = -1;
    double min_dist_apta = 1e9;
    int id_base_mais_prox_abs = -1;
    double min_dist_abs = 1e9;

    m->total_tentativas++; // Contabiliza tentativa desta missão

    printf("%6d: MISSAO %d TENT %d HAB REQ: [ ", tempo, id_missao, m->total_tentativas);
    if (m->Habilidades) cjto_imprime(m->Habilidades);
    printf("]\n");

    // 1. Encontrar bases candidatas
    for (int i = 0; i < w->NBases; i++) {
        struct base *b = w->B[i];
        if (!b) continue;

        double dx = (double)(b->local_x - m->local_x);
        double dy = (double)(b->local_y - m->local_y);
        double dist = sqrt(dx * dx + dy * dy);

        // Atualiza a base mais próxima absoluta (para uso do Composto V)
        if (dist < min_dist_abs) {
            min_dist_abs = dist;
            id_base_mais_prox_abs = i;
        }

        struct cjto_t *uniao = cjto_cria(MAX_HABILIDADES);
        if (!uniao) continue;

        // Une habilidades dos heróis VIVOS e PRESENTES na base
        for (int k = 0; k < w->NHerois; k++) {
            struct heroi *h = w->H[k];
            // --- CORREÇÃO: Usa cjto_pertence e h->vivo ---
            if (h && h->vivo && cjto_pertence(b->presentes, h->ID)) {
                
                // --- CORREÇÃO: Ordem invertida para evitar bugs de conjunto vazio ---
                struct cjto_t *aux = cjto_uniao(h->Habilidades, uniao);
                if (aux) {
                    cjto_destroi(uniao);
                    uniao = aux;
                }
            }
        }

        printf("%6d: MISSAO %d UNIAO HAB BASE %d: [ ", tempo, id_missao, b->ID);
        cjto_imprime(uniao);
        printf("]\n");

        // Verifica se a base cumpre a missão
        if (cjto_contem(uniao, m->Habilidades)) {
            if (dist < min_dist_apta) {
                min_dist_apta = dist;
                id_bmp = i;
            }
        }
        cjto_destroi(uniao);
    }

    // 2. Decisão da Missão
    if (id_bmp != -1) {
        // --- SUCESSO (Equipe) ---
        bmp = w->B[id_bmp];
        bmp->n_missoes++;
        
        printf("%6d: MISSAO %d CUMPRIDA BASE %d HABS: [ ", tempo, id_missao, bmp->ID);
        if (m->Habilidades) cjto_imprime(m->Habilidades);
        printf("]\n");

        // XP para os participantes
        for (int k = 0; k < w->NHerois; k++) {
            struct heroi *h = w->H[k];
            if (h && h->vivo && cjto_pertence(bmp->presentes, h->ID)) {
                h->experiencia++;
            }
        }

        // Estatísticas Globais
        w->missoes_cumpridas++;
        w->total_tentativas += m->total_tentativas;
        if (m->total_tentativas > w->max_tentativas) w->max_tentativas = m->total_tentativas;
        if (m->total_tentativas < w->min_tentativas) w->min_tentativas = m->total_tentativas;

    } else {
        // --- FALHA (Verifica Composto V) ---
        int usar_v = (w->NCompostosV > 0) && (tempo % 2500 == 0) && (id_base_mais_prox_abs != -1);

        if (usar_v) {
            struct base *b_prox = w->B[id_base_mais_prox_abs];
            w->NCompostosV--;
            b_prox->n_missoes++;

            printf("%6d: MISSAO %d CUMPRIDA BASE %d (COMPOSTO V)\n", tempo, id_missao, id_base_mais_prox_abs);
            
            w->missoes_cumpridas++;
            w->total_tentativas += m->total_tentativas;
            if (m->total_tentativas > w->max_tentativas) w->max_tentativas = m->total_tentativas;
            if (m->total_tentativas < w->min_tentativas) w->min_tentativas = m->total_tentativas;

            // Escolhe sacrifício (maior XP)
            struct heroi *h_max = NULL;
            int max_xp = -1;

            for (int k = 0; k < w->NHerois; k++) {
                struct heroi *h = w->H[k];
                if (h && h->vivo && cjto_pertence(b_prox->presentes, h->ID)) {
                    if (h->experiencia > max_xp) {
                        max_xp = h->experiencia;
                        h_max = h;
                    }
                }
            }

            // Agendar morte (Usa LEF - Corrige erro de unused parameter)
            if (h_max) {
                struct evento *morre = cria_evento(tempo, EV_MORRE, h_max->ID, b_prox->ID);
                if (morre) fprio_insere(lef, morre, EV_MORRE, tempo);
            }

            // XP para os outros
            for (int k = 0; k < w->NHerois; k++) {
                struct heroi *h = w->H[k];
                if (h && h->vivo && cjto_pertence(b_prox->presentes, h->ID) && h != h_max) {
                    h->experiencia++;
                }
            }

        } else {
            // --- IMPOSSÍVEL (Reagendar) ---
            printf("%6d: MISSAO %d IMPOSSIVEL\n", tempo, id_missao);

            struct evento *nova = cria_evento(tempo + 24 * 60, EV_MISSAO, id_missao, 0);
            
            // Reagenda (Usa LEF - Corrige erro de unused parameter)
            if (nova) {
                fprio_insere(lef, nova, EV_MISSAO, nova->tempo);
            }
        }
    }
}

void evento_fim(int tempo, struct mundo *w) {
    printf("%d: FIM\n\n", tempo);

    int mortos = 0;
    for (int i = 0; i < w->NHerois; i++) {
        struct heroi *h = w->H[i];
        if (!h->vivo) mortos++;

        printf("HEROI %2d %s  PAC %3d VEL %4d EXP %4d HABS [ ",
               h->ID, (h->vivo ? "VIVO" : "MORTO"), h->Paciencia, h->Velocidade, h->experiencia);
        cjto_imprime(h->Habilidades);
        printf("]\n");
    }
    printf("\n");

    for (int i = 0; i < w->NBases; i++) {
        struct base *b = w->B[i];
        printf("BASE %2d LOT %2d FILA MAX %2d MISSOES %d\n",
               b->ID, b->Lotacao, b->max_fila, b->n_missoes);
    }
    printf("\n");

    printf("EVENTOS TRATADOS: %d\n", w->n_eventos);
    
    double perc = (w->NMissoes > 0) ? (double)w->missoes_cumpridas / w->NMissoes * 100.0 : 0.0;
    printf("MISSOES CUMPRIDAS: %d/%d (%.1f%%)\n", w->missoes_cumpridas, w->NMissoes, perc);

    double media = (w->missoes_cumpridas > 0) ? (double)w->total_tentativas / w->missoes_cumpridas : 0.0;
    int min_t = (w->min_tentativas == 999999) ? 0 : w->min_tentativas;
    
    printf("TENTATIVAS/MISSAO: MIN %d, MAX %d, MEDIA %.1f\n", min_t, w->max_tentativas, media);

    double taxa = (w->NHerois > 0) ? (double)mortos / w->NHerois * 100.0 : 0.0;
    printf("TAXA MORTALIDADE: %.1f%%\n", taxa);
}