// programa principal do projeto "The Boys - 2024/2"
// Autor: Ramon Cesar Santos Alves, GRR 20204080

// seus #includes vão aqui
#include "theboys.h"
// seus #defines vão aqui
#define q  20000

// minimize o uso de variáveis globais

// programa principal
int main ()
{
  // 1. Inicialização
  srand(time(NULL)); // Inicializar números aleatórios
  int TAM_MUNDO_X = MAX;
  int TAM_MUNDO_Y = MAX;
  struct mundo *world = cria_mundo(MAX);
  struct fprio_t *fila_eventos = fprio_cria();
  // 2. Popular o mundo (Exemplo: 10 Heróis, 3 Bases)
  for (int i = 0; i < 10; i++) {
    struct heroi *h = adiciona_heroi(world);
    // Lógica inicial de alocação de heróis a bases (TBD)
  }
  for (int i = 0; i < 3; i++){
    adiciona_base(world, TAM_MUNDO_X, TAM_MUNDO_Y);
    adiciona_missao(world, TAM_MUNDO_X, TAM_MUNDO_Y);
  } // 1 Missão inicial
  // 3. Laço de Simulação (Event Loop)
  while (fprio_tamanho(fila_eventos) > 0 /* || outras condições de parada */)
  {
    int tipo, prio;
    struct evento *ev = fprio_retira(fila_eventos, &tipo, &prio);
    // Atualizar o tempo de simulação (se necessário)
    // processa_evento(world, fila_eventos, ev); // Função TBD
    // free(ev);
  }
  // 4. Destruir o mundo
  // ... liberar fila_eventos e mundo ...
  destroi_mundo(world);
  return 0;
}

