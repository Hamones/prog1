// TAD Fila de prioridades (FPRIO) genérica
// Carlos Maziero, DINF/UFPR, Out 2024
// Marcos Castilho, inclui as structs no arquivo.c, Out 2025
// Implementação com lista encadeada simples

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

// A COMPLETAR
