// programa principal do projeto "The Boys - 2024/2"
// Autor: Ramon Cesar Santos Alves, GRR 20204080

// seus #includes vão aqui
#include <stdio.h>
#include <stdlib.h> // Para malloc, free, rand, srand
#include <string.h> // Para memset
#include <time.h>   // Para time (usado no srand)

#include "theboys.h"
#include "conjunto.h" // Presume que inclui "fila.h" e "fprio.h" se necessario
#include "fila.h"     // Incluido para struct fila_t

//
// NOTA: Estas structs deveriam estar em "theboys.h"
// Elas estao corrigidas aqui.
//

// MAX_HABILIDADES e MAX_HEROIS precisam ser definidos
// (provavelmente em theboys.h)
#define MAX_HABILIDADES 20
#define MAX_HEROIS 100

struct heroi
{
    int ID;                // numero inteiro >= 0 que identifica unicamente o heroi;
    struct cjto_t *Habilidades; // CORRIGIDO: Deve ser um ponteiro para o TAD
    int Paciencia;         // numero inteiro >= 0
    int Velocidade;        // numero inteiro >= 0
    int experiencia;       // numero inteiro >= 0
    int Base;              // ID da base onde o heroi se encontra (-1 se nenhuma)
};

struct base
{
    int ID;                // numero inteiro >= 0 que identifica cada base;
    int Lotacao;           // numero maximo de herois naquela base;
    struct cjto_t *presentes; // CORRIGIDO: Deve ser um ponteiro para o TAD
    struct fila_t *Espera; // CORRIGIDO: Deve ser uma fila_t*
    int local_x;           // CORRIGIDO: Coordenada X
    int local_y;           // CORRIGIDO: Coordenada Y
};

struct missao
{
    int ID;                // numero inteiro >= 0 que identifica a missao;
    struct cjto_t *Habilidades; // CORRIGIDO: Deve ser um ponteiro para o TAD
    int local_x;           // CORRIGIDO: Coordenada X
    int local_y;           // CORRIGIDO: Coordenada Y
};

struct mundo
{
    int NHerois;       // numero total de herois no mundo;
    struct heroi *H[MAX]; // CORRIGIDO: Array de ponteiros para herois
    int NBases;        // numero total de bases no mundo;
    struct base *B[MAX]; // CORRIGIDO: Array de ponteiros para bases
    int NMissoes;      // numero total de missoes a cumprir;
    struct missao *M[MAX]; // CORRIGIDO: Array de ponteiros para missoes
};

/* --- Funcoes auxiliares --- */

// Gera um inteiro aleatorio entre min e max (inclusivo)
int aleat(int min, int max)
{
    // Adicione srand(time(NULL)) no inicio da sua main()
    return (rand() % (max - min + 1)) + min;
}

/* --- Principais funções --- */

// Cria o mundo
struct mundo *cria_mundo(int tam) // "tam" parece ser o MAX
{
    struct mundo *world;

    // Aloca memoria para UMA estrutura de mundo
    world = malloc(sizeof(struct mundo));
    if (!world)
        return NULL; // Falha na alocacao

    world->NHerois = 0;
    world->NBases = 0;
    world->NMissoes = 0;

    // Inicializa os arrays de ponteiros como NULL
    // (precisa de #include <string.h>)
    memset(world->H, 0, sizeof(world->H));
    memset(world->B, 0, sizeof(world->B));
    memset(world->M, 0, sizeof(world->M));
    
    return world;
}

// Cria UM heroi (funcao auxiliar)
struct heroi *cria_heroi_aleatorio(int id)
{
    struct heroi *h = malloc(sizeof(struct heroi));
    if (!h)
        return NULL; // Falha na alocacao

    h->ID = id;
    h->Paciencia = aleat(1, 10);
    h->Velocidade = aleat(1, 10);
    h->experiencia = 0;
    h->Base = -1; // -1 significa "nenhuma base"

    // Inicializa o TAD Habilidades
    h->Habilidades = cjto_cria(MAX_HABILIDADES);
    if (!h->Habilidades) {
        free(h);
        return NULL;
    }
    
    // Adiciona 3 habilidades aleatorias
    cjto_insere(h->Habilidades, aleat(0, MAX_HABILIDADES - 1));
    cjto_insere(h->Habilidades, aleat(0, MAX_HABILIDADES - 1));
    cjto_insere(h->Habilidades, aleat(0, MAX_HABILIDADES - 1));

    return h;
}

// Adiciona um novo heroi ao mundo
// (Implementando a funcao de theboys.h)
struct heroi *adiciona_heroi(struct mundo *world)
{
    if (!world || world->NHerois >= MAX)
        return NULL; // Mundo nao existe ou esta cheio

    // Cria um novo heroi com o proximo ID disponivel
    struct heroi *novo_heroi = cria_heroi_aleatorio(world->NHerois);
    if (!novo_heroi)
        return NULL; // Falha ao criar heroi

    // Adiciona o heroi ao array do mundo
    world->H[world->NHerois] = novo_heroi;
    world->NHerois++;

    return novo_heroi;
}


// Cria UMA base (funcao auxiliar)
struct base *cria_base_aleatoria(int id, int mundo_tam_x, int mundo_tam_y)
{
    struct base *b = malloc(sizeof(struct base));
    if (!b)
        return NULL;

    b->ID = id;
    b->Lotacao = aleat(5, 20);
    b->local_x = aleat(0, mundo_tam_x);
    b->local_y = aleat(0, mundo_tam_y);

    // Inicializa o TAD presentes
    b->presentes = cjto_cria(MAX_HEROIS); // Pode guardar ate MAX_HEROIS IDs
    if (!b->presentes) {
        free(b);
        return NULL;
    }

    // Inicializa o TAD fila
    b->Espera = fila_cria();
    if (!b->Espera) {
        cjto_destroi(b->presentes);
        free(b);
        return NULL;
    }

    return b;
}

// Adiciona uma nova base ao mundo
struct base *adiciona_base(struct mundo *world, int mundo_tam_x, int mundo_tam_y)
{
    if (!world || world->NBases >= MAX)
        return NULL; // Mundo nao existe ou esta cheio

    struct base *nova_base = cria_base_aleatoria(world->NBases, mundo_tam_x, mundo_tam_y);
    if (!nova_base)
        return NULL;

    world->B[world->NBases] = nova_base;
    world->NBases++;

    return nova_base;
}


// Cria UMA missao (funcao auxiliar)
struct missao *cria_missao_aleatoria(int id, int mundo_tam_x, int mundo_tam_y)
{
    struct missao *m = malloc(sizeof(struct missao));
    if (!m)
        return NULL;

    m->ID = id;
    m->local_x = aleat(0, mundo_tam_x);
    m->local_y = aleat(0, mundo_tam_y);

    m->Habilidades = cjto_cria(MAX_HABILIDADES);
    if (!m->Habilidades) {
        free(m);
        return NULL;
    }

    // Adiciona 1 a 3 habilidades necessarias
    int num_hab = aleat(1, 3);
    for (int i = 0; i < num_hab; i++) {
        cjto_insere(m->Habilidades, aleat(0, MAX_HABILIDADES - 1));
    }

    return m;
}

// Adiciona uma nova missao ao mundo
struct missao *adiciona_missao(struct mundo *world, int mundo_tam_x, int mundo_tam_y)
{
    if (!world || world->NMissoes >= MAX)
        return NULL;

    struct missao *nova_missao = cria_missao_aleatoria(world->NMissoes, mundo_tam_x, mundo_tam_y);
    if (!nova_missao)
        return NULL;

    world->M[world->NMissoes] = nova_missao;
    world->NMissoes++;

    return nova_missao;
}

//
// --- Funcoes de destruicao (Exemplo) ---
//
// Voce precisa criar funcoes para destruir tudo que foi alocado

void destroi_heroi(struct heroi *h) {
    if (!h) return;
    cjto_destroi(h->Habilidades); // Destroi o TAD
    free(h);                      // Libera o heroi
}

void destroi_base(struct base *b) {
    if (!b) return;
    cjto_destroi(b->presentes);   // Destroi o TAD
    fila_destroi(b->Espera);      // Destroi o TAD
    free(b);
}

void destroi_missao(struct missao *m) {
    if (!m) return;
    cjto_destroi(m->Habilidades);
    free(m);
}

struct mundo *destroi_mundo(struct mundo *world) {
    if (!world) return NULL;

    // Libera todos os herois
    for (int i = 0; i < world->NHerois; i++)
        destroi_heroi(world->H[i]);
