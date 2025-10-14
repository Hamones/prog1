#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* coloque demais includes aqui */

/* ------------------- Nao altere estas structs ------------------------- */
struct nodo {
    int chave;
    struct nodo *prox;
};

struct lista {
    struct nodo *ini;
    struct nodo *ptr; /* ponteiro para algum nodo da lista (iterador) */
    int tamanho;

};
/* ---------------------------------------------------------------------- */

struct lista *lista_cria (){

    struct lista *nova_lista = malloc (sizeof(struct lista));

    if (!nova_lista)
        return 0;

    memset (nova_lista, 0, sizeof(struct lista));

    return nova_lista;
  
}

void lista_destroi (struct lista **lista){ /*o formato inicial preve *lista*/
    if (!*lista)
        return;
    
    struct nodo * aux;

    int i = 0; 
    while (i < (*lista)->tamanho) { /* 2. Condição*/
        struct nodo *aux = (*lista)->ini;
        (*lista)->ini = aux->prox;
        free(aux);

        i++; /* 3. Incremento*/
    }

    free (lista);
    return;

}

int lista_insere_inicio (struct lista *lista, int chave){
    if (!lista)
        return -1;

    if (lista->tamanho == CAP)
        return -2;

    struct nodo *novo_nodo = malloc (sizeof(struct nodo));

    if (!novo_nodo)
        return -3;

    memset (novo_nodo, 0, sizeof(struct nodo));
}

int lista_insere_fim (struct lista *lista, int chave){
        if (!lista)
        return -1;

    if (lista->tamanho == CAP)
        return -2;

    struct nodo *novo_nodo = malloc (sizeof(struct nodo));

    if (!novo_nodo)
        return -3;

    memset (novo_nodo, 0, sizeof(struct nodo));
}

int lista_insere_ordenado (struct lista *lista, int chave){
}

int lista_remove_inicio (struct lista *lista, int *chave){
    if (! lista || !dado)
        return -1;

    if (!lista -> tamanho)
        return -2;

    struct nodo *aux = lista->inicio;
    *dado = aux->valor;
    lista->inicio = aux->prox;

    lista->tamanho--;

    if (!lista-tamanho)
        lista-fim = 0;

    free (aux);
    return 0;
}

int lista_remove_fim (struct lista *lista, int *chave){
    if (! lista || !dado)
        return -1;

    if (!lista -> tamanho)
        return -2;

    struct nodo *aux = lista->inicio;
    *dado = aux->valor;
    lista->inicio = aux->prox;

    lista->tamanho--;

    if (!lista-tamanho)
        lista-fim = 0;

    free (aux);
    return 0;    
}

int lista_remove_ordenado (struct lista *lista, int chave){
}

int lista_vazia (struct lista *lista){
    lista-<
}

int lista_tamanho (struct lista *lista){
    if (!lista)
        return -1;

        return lista->tamanho;
}

int lista_pertence (struct lista *lista, int chave){
}

void lista_inicia_iterador (struct lista *lista){
}

int lista_incrementa_iterador (struct lista *lista, int *chave){
}
