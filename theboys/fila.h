#ifndef FILA
#define FILA

// TAD Fila (fila.h)
// Alinhado para armazenar inteiros (IDs dos heróis)

// Descreve um nodo da fila 
struct fila_nodo_t
{
    int item;                   // O item aqui é o ID (int), não void*
    struct fila_nodo_t *prox;   // Próximo nodo
};

// Descreve a estrutura da fila 
struct fila_t
{
    struct fila_nodo_t *prim;   // Primeiro nodo
    struct fila_nodo_t *ult;    // Último nodo
    int num;                    // Número de itens
};

// Cria uma fila vazia.
// Retorno: ponteiro para a fila criada ou NULL se erro.
struct fila_t *fila_cria ();

// Libera todas as estruturas de dados da fila.
// Retorno: NULL.
struct fila_t *fila_destroi (struct fila_t *f);

// Insere um item (ID) no final da fila.
// Retorno: 1 se sucesso, 0 se erro.
int fila_insere (struct fila_t *f, int item);

// Retira o primeiro item da fila e o devolve no ponteiro *item.
// Retorno: 1 se sucesso (item retirado), 0 se erro ou fila vazia.
int fila_retira (struct fila_t *f, int *item);

// Informa o número de itens na fila.
// Retorno: N >= 0 ou -1 se erro.
int fila_tamanho (struct fila_t *f);

// Imprime o conteúdo da fila no formato "Fila: [ 1 2 3 ]"
void fila_imprime (struct fila_t *f);

#endif