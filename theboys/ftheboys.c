// Implementação das funções auxiliares do projeto "The Boys"
// ftheboys.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "theboys.h" // Inclui todas as definições de structs e TADs

// Gera um inteiro aleatorio entre min e max (inclusivo)
int aleat(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// --- Funções de Criação (Auxiliares internas) ---

// Cria UM heroi (função estática, usada apenas internamente aqui)
static struct heroi *cria_heroi_aleatorio(int id)
{
    struct heroi *h = malloc(sizeof(struct heroi));
    if (!h) return NULL;

    h->ID = id;
    h->Paciencia = aleat(0, 100);  // Exemplo de paciência 0-100
    h->Velocidade = aleat(50, 5000); // Exemplo de velocidade
    h->experiencia = 0;
    h->Base = -1; // Começa no "limbo"

    // Cria conjunto de habilidades (capacidade máxima definida no .h)
    h->Habilidades = cjto_cria(MAX_HABILIDADES);
    
    // Adiciona 2 a 5 habilidades aleatórias
    int n_hab = aleat(2, 5);
    for (int i=0; i < n_hab; i++) {
        cjto_insere(h->Habilidades, aleat(0, MAX_HABILIDADES-1));
    }

    return h;
}

static struct base *cria_base_aleatoria(int id, int max_x, int max_y)
{
    struct base *b = malloc(sizeof(struct base));
    if (!b) return NULL;

    b->ID = id;
    b->Lotacao = aleat(3, 10); // Capacidade da base
    b->local_x = aleat(0, max_x);
    b->local_y = aleat(0, max_y);

    // Cria o conjunto de herois presentes (capacidade = total de herois possiveis)
    b->presentes = cjto_cria(MAX_HEROIS);
    
    // Cria a fila de espera
    b->Espera = fila_cria();

    if (!b->presentes || !b->Espera) {
        // Se falhar alocação de TAD, limpa e retorna erro
        cjto_destroi(b->presentes);
        fila_destroi(b->Espera);
        free(b);
        return NULL;
    }

    return b;
}

static struct missao *cria_missao_aleatoria(int id, int max_x, int max_y)
{
    struct missao *m = malloc(sizeof(struct missao));
    if (!m) return NULL;

    m->ID = id;
    m->local_x = aleat(0, max_x);
    m->local_y = aleat(0, max_y);

    // Habilidades requeridas pela missão
    m->Habilidades = cjto_cria(MAX_HABILIDADES);
    
    // 6 a 10 habilidades necessárias
    int n_hab = aleat(6, 10);
    for (int i=0; i < n_hab; i++) {
        cjto_insere(m->Habilidades, aleat(0, MAX_HABILIDADES-1));
    }

    return m;
}

// --- Funções Principais (Interface Pública) ---

struct mundo *cria_mundo()
{
    struct mundo *w = malloc(sizeof(struct mundo));
    if (!w) return NULL;

    w->NHerois = 0;
    w->NBases = 0;
    w->NMissoes = 0;
    w->relogio = T_INICIO;
    w->TamanhoMundoX = N_TAMANHO_MUNDO;
    w->TamanhoMundoY = N_TAMANHO_MUNDO;

    // Inicializa os vetores com NULL
    for(int i=0; i<MAX_HEROIS; i++) w->H[i] = NULL;
    for(int i=0; i<MAX_BASES; i++)  w->B[i] = NULL;
    for(int i=0; i<MAX_MISSOES; i++) w->M[i] = NULL;

    return w;
}

struct heroi *adiciona_heroi(struct mundo *w)
{
    if (!w || w->NHerois >= MAX_HEROIS) return NULL;

    struct heroi *novo = cria_heroi_aleatorio(w->NHerois);
    if (novo) {
        w->H[w->NHerois] = novo;
        w->NHerois++;
    }
    return novo;
}

struct base *adiciona_base(struct mundo *w)
{
    if (!w || w->NBases >= MAX_BASES) return NULL;

    struct base *nova = cria_base_aleatoria(w->NBases, w->TamanhoMundoX, w->TamanhoMundoY);
    if (nova) {
        w->B[w->NBases] = nova;
        w->NBases++;
    }
    return nova;
}

struct missao *adiciona_missao(struct mundo *w)
{
    if (!w || w->NMissoes >= MAX_MISSOES) return NULL;

    struct missao *nova = cria_missao_aleatoria(w->NMissoes, w->TamanhoMundoX, w->TamanhoMundoY);
    if (nova) {
        w->M[w->NMissoes] = nova;
        w->NMissoes++;
    }
    return nova;
}

// --- Funções de Destruição ---

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

    // Libera herois
    for (int i = 0; i < w->NHerois; i++)
        destroi_heroi(w->H[i]);

    // Libera bases
    for (int i = 0; i < w->NBases; i++)
        destroi_base(w->B[i]);

    // Libera missoes
    for (int i = 0; i < w->NMissoes; i++)
        destroi_missao(w->M[i]);

    free(w);
    return NULL;
}

//Eventos
/*devem ser adicionaod à LEF*/

viaja(heroi){

    heroi-> posicao
    //procurar a base mais próxima
}

chega{

}


espera{

}

desiste{

}

