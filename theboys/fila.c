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
    struct fila_t *f = malloc(sizeof(struct fila_t));
    if (!f)
        return NULL; // Falha na alocação

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
    struct fila_nodo_t *proximo;

    while (atual)
    {
        proximo = atual->prox;
        // CORREÇÃO: Não fazemos free(atual->item) pois item é um int (ID)
        free(atual); 
        atual = proximo;
    }

    free(f);
    return NULL;
}

// Insere um item no final da fila.
// Retorno: 1 se sucesso, 0 se erro.
int fila_insere (struct fila_t *f, int item)
{
    if (!f)
        return 0;

    struct fila_nodo_t *novo = malloc(sizeof(struct fila_nodo_t));
    if (!novo)
        return 0; // Falha na alocação do nodo

    novo->item = item;
    novo->prox = NULL;

    // Se a fila estiver vazia
    if (f->prim == NULL)
    {
        f->prim = novo;
        f->ult = novo;
    }
    else
    {
        f->ult->prox = novo; // O antigo último aponta para o novo
        f->ult = novo;       // Atualiza o ponteiro de último
    }

    f->num++;
    return 1; // Sucesso
}

// Retira o primeiro item da fila e o devolve no parâmetro *item.
// Retorno: 1 se sucesso, 0 se erro ou fila vazia.
int fila_retira (struct fila_t *f, int *item)
{
    // Verifica fila inválida, fila vazia ou ponteiro de retorno nulo
    if (!f || f->prim == NULL || !item)
        return 0;

    struct fila_nodo_t *nodo_removido = f->prim;
    
    // Salva o valor no endereço fornecido pelo usuário
    *item = nodo_removido->item;

    // Avança o ponteiro do início
    f->prim = f->prim->prox;

    // Se a fila ficou vazia, atualiza também o ponteiro 'ult'
    if (f->prim == NULL)
        f->ult = NULL;

    free(nodo_removido); // Libera apenas a estrutura do nodo
    f->num--;

    return 1; // Sucesso
}

// Informa o número de itens na fila.
// Retorno: N >= 0 ou -1 se erro.
int fila_tamanho (struct fila_t *f)
{
    if (!f)
        return -1;
    
    return f->num;
}

// Imprime o conteúdo da fila 
void fila_imprime (struct fila_t *f)
{
    if (!f)
        return;

    struct fila_nodo_t *atual = f->prim;
    
    printf("Fila: [ ");
    while (atual)
    {
        printf("%d ", atual->item); // CORREÇÃO: Imprime %d pois é int
        atual = atual->prox;
    }
    printf("]\n");
}