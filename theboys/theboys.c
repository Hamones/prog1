#ifndef THEBOYS
#define THEBOYS

// Includes necessarios para os TADs
#include "fila.h"
#include "fprio.h"
#include "conjunto.h"

// Defines globais para o projeto
#define MAX 10000       // Limite maximo de herois/bases/missoes
#define MAX_HABILIDADES 20  // Exemplo: O numero maximo de habilidades possiveis (0 a 19)
#define MAX_HEROIS 100      // Exemplo: O numero maximo de herois que uma base pode rastrear

// --- DEFINICOES DAS ESTRUTURAS ---
// (Estas definicoes devem estar no .h para que o main e ftheboys saibam como sao)

struct heroi
{
    int ID;                // numero inteiro >= 0 que identifica unicamente o heroi;
    struct cjto_t *Habilidades; // Conjunto de habilidades (TAD conjunto)
    int Paciencia;         // numero inteiro >= 0
    int Velocidade;        // numero inteiro >= 0
    int experiencia;       // numero inteiro >= 0
    int Base;              // ID da base onde o heroi se encontra (-1 se nenhuma)
};

struct base
{
    int ID;                // numero inteiro >= 0 que identifica cada base;
    int Lotacao;           // numero maximo de herois naquela base;
    struct cjto_t *presentes; // Conjunto de IDs dos herois presentes (TAD conjunto)
    struct fila_t *Espera; // Fila de herois esperando (TAD fila)
    int local_x;           // Coordenada X
    int local_y;           // Coordenada Y
};

struct missao
{
    int ID;                // numero inteiro >= 0 que identifica a missao;
    struct cjto_t *Habilidades; // Conjunto de habilidades necessarias (TAD conjunto)
    int local_x;           // Coordenada X
    int local_y;           // Coordenada Y
};

struct mundo
{
    int NHerois;       // numero total de herois no mundo;
    struct heroi *H[MAX]; // Array de ponteiros para herois
    int NBases;        // numero total de bases no mundo;
    struct base *B[MAX]; // Array de ponteiros para bases
    int NMissoes;      // numero total de missoes a cumprir;
    struct missao *M[MAX]; // Array de ponteiros para missoes
};


/* --- PROTOTIPOS DAS FUNCOES (de ftheboys.c) --- */

/**
 * Cria e inicializa uma estrutura 'mundo' vazia.
 * Retorna: ponteiro para o mundo criado ou NULL se falhar.
 */
struct mundo *cria_mundo(int tam);

/**
 * Adiciona um novo heroi aleatorio ao mundo.
 * Retorna: ponteiro para o heroi adicionado ou NULL se falhar (ex: mundo cheio).
 */
struct heroi *adiciona_heroi(struct mundo *world);

/**
 * Adiciona uma nova base aleatoria ao mundo.
 * Retorna: ponteiro para a base adicionada ou NULL se falhar.
 */
struct base *adiciona_base(struct mundo *world, int mundo_tam_x, int mundo_tam_y);

/**
 * Adiciona uma nova missao aleatoria ao mundo.
 * Retorna: ponteiro para a missao adicionada ou NULL se falhar.
 */
struct missao *adiciona_missao(struct mundo *world, int mundo_tam_x, int mundo_tam_y);

/**
 * Libera toda a memoria alocada pelo mundo e seus componentes
 * (herois, bases, missoes e seus TADs internos).
 * Retorna: NULL.
 */
struct mundo *destroi_mundo(struct mundo *world);

// (Voce deve adicionar aqui os prototipos de todas as outras
// funcoes de ftheboys.c que a main (theboys.c) precisa chamar)

#endif
