#ifndef THEBOYS_H
#define THEBOYS_H

// Bibliotecas necessárias para os tipos de dados
#include "conjunto.h"
#include "fila.h"
#include "fprio.h"

// --- 1. Definições e Constantes (Atualizado) ---

// Tempo
#define T_INICIO        0
#define T_FIM_DO_MUNDO  525600

// Dimensões
#define N_TAMANHO_MUNDO 20000

// Quantidades Base
#define N_HABILIDADES   10

// Fórmulas Calculadas
#define N_HEROIS        (N_HABILIDADES * 5)      // = 50
#define N_BASES         (N_HEROIS / 5)           // = 10
#define N_MISSOES       (T_FIM_DO_MUNDO / 100)   // = 5256
#define N_COMPOSTOS_V   (N_HABILIDADES * 3)      // = 30

// --- Mapeamento de Compatibilidade ---
// As structs abaixo usam "MAX_" para definir o tamanho dos vetores.
// Redirecionamos para os novos valores "N_".
#define MAX_HEROIS      N_HEROIS
#define MAX_BASES       N_BASES
#define MAX_MISSOES     N_MISSOES
#define MAX_HABILIDADES N_HABILIDADES

// --- 2. Códigos dos Eventos ---
#define EV_CHEGA   1
#define EV_ESPERA  2
#define EV_DESISTE 3
#define EV_AVISA   4
#define EV_ENTRA   5
#define EV_SAI     6
#define EV_VIAJA   7
#define EV_MORRE   8 // Ocupa lugar, aviso
#define EV_MISSAO  9
#define EV_FIM     10

// --- 3. Estruturas de Dados ---

struct heroi {
    int ID;
    struct cjto_t *Habilidades; // Conjunto de habilidades
    int Paciencia;
    int Velocidade;
    int experiencia;
    int Base; // ID da base onde está (-1 se viajando/fora)
    int vivo; // 1 = vivo, 0 = morto
};

struct base {
    int ID;
    int Lotacao;
    struct cjto_t *presentes; // IDs dos herois presentes
    struct fila_t *Espera;    // Fila de espera (IDs)
    int local_x;
    int local_y;
    
    // Estatísticas
    int n_missoes; // Quantas missões cumpriu
    int max_fila;  // Tamanho máximo da fila registrado
};

struct missao {
    int ID;
    struct cjto_t *Habilidades; // Habilidades requeridas
    int local_x;
    int local_y;
    int total_tentativas; // Quantas vezes foi tentada
};

struct mundo {
    int NHerois;
    struct heroi *H[MAX_HEROIS]; // Vetor de ponteiros para herois

    int NBases;
    struct base *B[MAX_BASES];   // Vetor de ponteiros para bases

    int NMissoes;
    struct missao *M[MAX_MISSOES]; // Vetor de ponteiros para missoes

    int NCompostosV; // Estoque global de Composto V

    int relogio; // Tempo atual do mundo
    int TamanhoMundoX;
    int TamanhoMundoY;
    int n_eventos; // Contador total de eventos tratados

    // Estatísticas Globais
    int missoes_cumpridas;
    int total_tentativas; // Soma de todas as tentativas de todas as missões
    int max_tentativas;
    int min_tentativas;
};

// Estrutura genérica para eventos na FPRIO
struct evento {
    int tempo; // Chave de prioridade
    int tipo;  // EV_CHEGA, EV_SAI, etc.
    int dado1; // Ex: ID do herói ou da missão
    int dado2; // Ex: ID da base destino
};

// --- 4. Protótipos das Funções (Interface) ---

// Criação e Destruição
struct mundo *cria_mundo();
struct mundo *destroi_mundo(struct mundo *w);

struct heroi *adiciona_heroi(struct mundo *w);
struct base *adiciona_base(struct mundo *w);
struct missao *adiciona_missao(struct mundo *w);

// Funções Auxiliares
int aleat(int min, int max);
struct evento *cria_evento(int tempo, int tipo, int dado1, int dado2);

// Tratadores de Eventos
void chega(struct mundo *w, struct fprio_t *lef, struct evento *ev);
void espera(struct mundo *w, struct fprio_t *lef, struct evento *ev);
void desiste(struct mundo *w, struct fprio_t *lef, struct evento *ev);
void avisa(struct mundo *w, struct fprio_t *lef, struct evento *ev);
void entra(struct mundo *w, struct fprio_t *lef, struct evento *ev);
void evento_sai(int tempo, int id_heroi, int id_base, struct mundo *w, struct fprio_t *lef);
void evento_viaja(int tempo, int id_heroi, int id_destino, struct mundo *w, struct fprio_t *lef);
void evento_morre(int tempo, int id_heroi, int id_base, struct mundo *w, struct fprio_t *lef);
void evento_missao(int tempo, int id_missao, struct mundo *w, struct fprio_t *lef);
void evento_fim(int tempo, struct mundo *w);

#endif