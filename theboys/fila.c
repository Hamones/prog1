/* Implementação do TAD Fila (fila.c)
 * Baseado na interface fila.h
 * Ajustado para trabalhar com inteiros (IDs)
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Cria uma fila vazia.
// Retorno: ponteiro para a fila criada ou NULL se erro.
struct fila_t *fila_cria ()
{
    // Aloca a estrutura da fila
    struct fila_t *f = malloc(sizeof(struct fila_t));
    if (!f)
        return NULL;

    f->prim = NULL;
    f->ult = NULL;
    f->num = 0;

    return f;
}

// Libera todas as estruturas de dados da fila.
// Retorno: NULL.
struct fila_t *fila_destroi (struct fila_t *f)
{
    if (!f)
        return NULL;

    struct fila_nodo_t *atual = f->prim;
    struct fila_nodo_t *prox;

    while (atual)
    {
        prox = atual->prox;
        
        // IMPORTANTE: Como o item é um 'int', NÃO fazemos free(atual->item).
        // Apenas liberamos o nodo da lista encadeada.
        free(atual);
        
        atual = prox;
    }

    free(f);
    return NULL;
}

// Insere um item (ID) no final da fila.
// Retorno: 1 se sucesso, 0 se erro.
int fila_insere (struct fila_t *f, int item)
{
    if (!f)
        return 0;

    struct fila_nodo_t *novo = malloc(sizeof(struct fila_nodo_t));
    if (!novo)
        return 0; // Falha na alocação

    novo->item = item;
    novo->prox = NULL;

    // Se a fila estiver vazia
    if (f->prim == NULL)
    {
        f->prim = novo;
        f->ult  = novo;
    }
    else
    {
        f->ult->prox = novo; // O antigo último aponta para o novo
        f->ult = novo;       // Atualiza o ponteiro de último
    }

    f->num++;
    return 1;
}

// Retira o primeiro item da fila e o devolve no ponteiro *item.
// Retorno: 1 se sucesso (item retirado), 0 se erro ou fila vazia.
int fila_retira (struct fila_t *f, int *item)
{
    // Validações básicas
    if (!f || f->prim == NULL || !item)
        return 0;

    struct fila_nodo_t *removido = f->prim;

    // Retorna o valor (int) para o usuário
    *item = removido->item;

    // Avança a fila
    f->prim = removido->prox;

    // Se a fila ficou vazia, ajusta o ponteiro 'ult'
    if (f->prim == NULL)
        f->ult = NULL;

    f->num--;
    free(removido); // Libera o nodo

    return 1;
}

// Informa o número de itens na fila.
// Retorno: N >= 0 ou -1 se erro.
int fila_tamanho (struct fila_t *f)
{
    if (!f)
        return -1;

    return f->num;
}

// Imprime o conteúdo da fila no formato "Fila: [ 1 2 3 ]"
void fila_imprime (struct fila_t *f)
{
    if (!f)
        return;

    struct fila_nodo_t *atual = f->prim;

    printf("Fila: [ ");
    while (atual)
    {
        printf("%d ", atual->item);
        atual = atual->prox;
    }
    printf("]\n");
}