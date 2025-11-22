#ifndef THEBOYS
#define THEBOYS

// Includes dos TADs
#include "fila.h"
#include "fprio.h"
#include "conjunto.h"

// --- Constantes Globais ---
#define MAX_HEROIS      100   // Limite exemplo
#define MAX_BASES       20    // Limite exemplo
#define MAX_MISSOES     50    // Limite exemplo
#define MAX_HABILIDADES 10    // Habilidades de 0 a 9
#define T_INICIO        0
#define T_FIM_DO_MUNDO  525600 // Exemplo: 1 ano em minutos

// Dimensões do mundo (usado para gerar coordenadas aleatórias)
#define N_TAMANHO_MUNDO 20000 

// --- Códigos dos Eventos (para a FPRIO) ---
#define EV_CHEGA   1
#define EV_ESPERA  2
#define EV_DESISTE 3
#define EV_AVISA   4
#define EV_ENTRA   5
#define EV_SAI     6
#define EV_VIAJA   7
#define EV_MISSAO  8
#define EV_FIM     9

// --- Estrutura do Evento ---
// Esta estrutura será o "void *item" armazenado na FPRIO
struct evento {
    int tempo;      // Momento em que ocorre
    int tipo;       // EV_CHEGA, EV_SAI, etc.
    int dado1;      // Geralmente ID do herói ou da missão
    int dado2;      // Geralmente ID da base (destino ou origem)
};

// --- Estruturas do Mundo ---

struct heroi
{
    int ID;                // Identificador único
    struct cjto_t *Habilidades; // Conjunto de habilidades
    int Paciencia;         // Quão disposto está a esperar
    int Velocidade;        // Velocidade de deslocamento
    int experiencia;       // XP acumulado
    int Base;              // ID da base atual (-1 se nenhuma)
};

struct base
{
    int ID;                // Identificador único
    int Lotacao;           // Capacidade máxima
    struct cjto_t *presentes; // Conjunto de IDs dos heróis dentro da base
    struct fila_t *Espera; // Fila de IDs dos heróis esperando
    int local_x;           // Coordenada X
    int local_y;           // Coordenada Y
};

struct missao
{
    int ID;                // Identificador único
    struct cjto_t *Habilidades; // Habilidades requeridas
    int local_x;           // Coordenada X
    int local_y;           // Coordenada Y
};

struct mundo
{
    int NHerois;           // Quantidade atual
    struct heroi *H[MAX_HEROIS]; // Vetor de ponteiros
    
    int NBases;
    struct base *B[MAX_BASES];
    
    int NMissoes;
    struct missao *M[MAX_MISSOES];
    
    int TamanhoMundoX;
    int TamanhoMundoY;
    int relogio;           // Tempo atual da simulação
};

// --- Protótipos das Funções (implementadas em ftheboys.c) ---

// Criação e inicialização
struct mundo *cria_mundo();
struct heroi *adiciona_heroi(struct mundo *world);
struct base *adiciona_base(struct mundo *world);
struct missao *adiciona_missao(struct mundo *world);

// Destruição
void destroi_heroi(struct heroi *h);
void destroi_base(struct base *b);
void destroi_missao(struct missao *m);
struct mundo *destroi_mundo(struct mundo *world);

// Função auxiliar de aleatoriedade (útil para o main também)
int aleat(int min, int max);

#endif