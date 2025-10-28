// TAD Fila de prioridades (FPRIO) genérica
// Carlos Maziero, DINF/UFPR, Out 2024
// Marcos Castilho, inclui as structs no arquivo.c, Out 2025
// Implementação com lista encadeada simples

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fprio.h"

// descreve um nodo da fila de prioridades
// NAO altere estas estruturas
struct fpnodo_t
{
  void *item ;          // item associado ao nodo
  int   tipo ;          // tipo do item
  int   prio ;          // prioridade do item
  struct fpnodo_t *prox;    // próximo nodo
};

// descreve uma fila de prioridades
struct fprio_t
{
  struct fpnodo_t *prim ;   // primeiro nodo da fila
  int num ;         // número de itens na fila
} ;

// --- Funções Auxiliares (não estão no .h) ---

// Busca se um item (ponteiro) já existe na fila.
// Retorna 1 se encontrar, 0 se não encontrar.
static int busca_item(struct fprio_t *f, void *item) {
    struct fpnodo_t *atual = f->prim;
    while (atual) {
        if (atual->item == item)
            return 1; // Encontrado
        atual = atual->prox;
    }
    return 0; // Não encontrado
}

// --- Funções da Interface ---

struct fprio_t *fprio_cria (){
    // Aloca memória para a estrutura da fila
    struct fprio_t *nova_fprio = malloc (sizeof(struct fprio_t));
    if (!nova_fprio)
        return NULL; // Erro de alocação

    // Inicializa a fila como vazia
    nova_fprio->prim = NULL;
    nova_fprio->num = 0;

    return nova_fprio;
}


struct fprio_t *fprio_destroi (struct fprio_t *f)
{
    if (!f)
        return NULL;

    struct fpnodo_t *atual;
    struct fpnodo_t *prox;

    // atual recebe o endereço do primeiro da fila
    atual = f->prim;
    
    // Percorre a lista liberando os nodos e os itens
    while (atual)
    {
        prox = atual->prox;    // Salva o próximo
        if (atual->item)
            free(atual->item); // Libera o item (conforme .h)
        free(atual);           // Libera o nodo
        atual = prox;          // Avança para o próximo
    }

    // Libera a estrutura da fila
    free(f);

    return NULL;
}

// Insere o item na fila, mantendo-a ordenada por prioridades crescentes.
// Itens com a mesma prioridade devem respeitar a politica FIFO (retirar
// na ordem em que inseriu).
// Inserir duas vezes o mesmo item (o mesmo ponteiro) é um erro.
// Retorno: número de itens na fila após a operação ou -1 se erro.
int fprio_insere (struct fprio_t *f, void *item, int tipo, int prio)
{
    // Verifica parâmetros inválidos
    if (!f || !item)
        return -1;

    // Verifica se o item já existe (erro de item repetido)
    if (busca_item(f, item))
        return -1;

    // Aloca memória para o novo nodo
    struct fpnodo_t *novo = malloc(sizeof(struct fpnodo_t));
    if (!novo)
        return -1; // Erro de alocação

    // Preenche o novo nodo
    novo->item = item;
    novo->tipo = tipo;
    novo->prio = prio;
    novo->prox = NULL;

    // --- Lógica de Inserção Ordenada ---

    // Caso 1: Fila vazia ou novo item tem a menor prioridade
    if (f->prim == NULL || prio < f->prim->prio) {
        novo->prox = f->prim;
        f->prim = novo;
    } 
    // Caso 2: Inserir no meio ou no fim
    else {
        struct fpnodo_t *ant = f->prim; // Nodo anterior

        // Procura o ponto de inserção
        // Avança 'ant' enquanto o *próximo* nodo existir E
        // a prioridade do *próximo* for <= à nova prioridade.
        // Isso garante a ordem crescente e a política FIFO (insere após
        // todos os itens de prioridade igual).
        while (ant->prox != NULL && ant->prox->prio <= prio) {
            ant = ant->prox;
        }

        // Insere o 'novo' nodo após 'ant'
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    
    f->num++;
    return f->num;
}

// Retira o primeiro item da fila e o devolve; o tipo e a prioridade
// do item são devolvidos nos parâmetros "tipo" e "prio".
// Retorno: ponteiro para o item retirado ou NULL se fila vazia ou erro.
void *fprio_retira (struct fprio_t *f, int *tipo, int *prio)
{
    // Verifica parâmetros inválidos (fila ou ponteiros de retorno)
    if (!f || !tipo || !prio)
        return NULL;

    // Verifica se a fila está vazia
    if (f->prim == NULL) // ou (f->num == 0)
        return NULL;

    // Salva o primeiro nodo
    struct fpnodo_t *primeiro = f->prim;
    void *item_retirado = primeiro->item;

    // Copia os dados de tipo e prioridade para os ponteiros de retorno
    *tipo = primeiro->tipo;
    *prio = primeiro->prio;

    // Remove o nodo do início da fila (desacopla)
    f->prim = primeiro->prox;

    // Libera a memória do *nodo* (o item será liberado pelo chamador)
    free(primeiro);

    f->num--;

    return item_retirado;
}

// Informa o número de itens na fila.
// Retorno: N >= 0 ou -1 se erro.
int fprio_tamanho (struct fprio_t *f)
{
    if (!f)
        return -1;
    return f->num;
}

// Imprime o conteúdo da fila no formato "(tipo prio) (tipo prio) ..."
// Para cada item deve ser impresso seu tipo e sua prioridade, com um
// espaço entre valores, sem espaços antes ou depois e sem nova linha.
void fprio_imprime (struct fprio_t *f)
{
    if (!f)
        return;

    struct fpnodo_t *atual = f->prim;
    
    // Percorre a fila imprimindo cada nodo
    while (atual)
    {
        printf("(%d %d)", atual->tipo, atual->prio);
        
        // Adiciona espaço apenas se houver um próximo item
        if (atual->prox)
            printf(" ");
            
        atual = atual->prox;
    }
    // Não imprime \n, conforme especificado
}