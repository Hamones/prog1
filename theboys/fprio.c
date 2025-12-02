/* TAD Fila de prioridades (FPRIO) genérica
 * Implementação com lista encadeada simples
 * fprio.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "fprio.h"

/* Função Auxiliar Interna  */

/* Verifica se um ponteiro de item já existe na fila */
int fprio_busca_item(struct fprio_t *f, void *item) {
    struct fpnodo_t *atual;
    atual = f->prim;
    while (atual) {
        if (atual->item == item)
            return 1;
        atual = atual->prox;
    }
    return 0;
}

/*  Funções Principais  */

struct fprio_t *fprio_cria ()
{
    struct fprio_t *f = malloc(sizeof(struct fprio_t));
    if (!f)
        return NULL;

    f->prim = NULL;
    f->fim  = NULL; 
    f->num  = 0;

    return f;
}

struct fprio_t *fprio_destroi (struct fprio_t *f)
{
    if (!f)
        return NULL;

    struct fpnodo_t *atual;
    atual = f->prim;
    struct fpnodo_t *prox;

    while (atual)
    {
        prox = atual->prox;
        

        /*provável violação de TAD, porém segui a especificação de fprio.h 
        "Libera todas as estruturas de dados da fila, inclusive os itens."*/
        if (atual->item)
            free(atual->item);
            
        free(atual);
        atual = prox;
    }

    free(f);
    return NULL;
}

int fprio_insere (struct fprio_t *f, void *item, int tipo, int prio)
{
    if (!f || !item)
        return -1;

    /* Evita duplicatas de ponteiros */
    if (fprio_busca_item(f, item))
        return -1;

    struct fpnodo_t *novo = malloc(sizeof(struct fpnodo_t));
    if (!novo)
        return -1;

    novo->item = item;
    novo->tipo = tipo;
    novo->prio = prio;
    novo->prox = NULL;

    /* Inserção Ordenada (Menor prioridade/tempo primeiro) */
    
    /* Caso 1: Fila vazia ou novo item vem antes do primeiro */
    if (f->prim == NULL || prio < f->prim->prio) {
        novo->prox = f->prim;
        f->prim = novo;
        /* Se era vazia, atualiza fim (se usado) */
        if (f->num == 0) 
            f->fim = novo; 
    } 
    /* Caso 2: Inserir no meio ou fim */
    else {
        struct fpnodo_t *ant;
        ant = f->prim;

        /* Avança enquanto o próximo existir E tiver prioridade MENOR ou IGUAL */
        while (ant->prox != NULL && ant->prox->prio <= prio) {
            ant = ant->prox;
        }

        novo->prox = ant->prox;
        ant->prox = novo;
        
        /* Atualiza fim se inseriu no final */
        if (novo->prox == NULL) 
            f->fim = novo;
    }

    f->num++;
    return f->num;
}

void *fprio_retira (struct fprio_t *f, int *tipo, int *prio)
{
    if (!f || f->prim == NULL || !tipo || !prio)
        return NULL;

    struct fpnodo_t *primeiro;
    void *item_retornado;
    primeiro = f->prim;
    item_retornado = primeiro->item;

    *tipo = primeiro->tipo;
    *prio = primeiro->prio;

    f->prim = primeiro->prox;
    
    if (f->prim == NULL)
        f->fim = NULL;

    /* Apenas liberamos o nodo da lista. */
    free(primeiro);

    f->num--;
    return item_retornado;
}

int fprio_tamanho (struct fprio_t *f)
{
    if (!f) 
    return -1;
    
    return f->num;
}

void fprio_imprime (struct fprio_t *f)
{
    if (!f) 
    return;

    struct fpnodo_t *atual = f->prim;
    while (atual) {
        printf("(%d %d)", atual->tipo, atual->prio);
        if (atual->prox) printf(" ");
        atual = atual->prox;
    }
}