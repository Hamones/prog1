/*
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 09/09/2025 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/* coloque aqui as funções auxiliares que precisar neste arquivo */
void troca_r(struct racional *r1,struct racional*r2)
{
  struct racional *aux;
  aux->num = r1->num;
  aux->den = r1->den;
  r2 = *r1;
  r1 = *aux;
}

struct racional simplifica_r (struct racional r);
long mmc (long a, long b);
long aleat (long min, long max);
long mdc (long a, long b);

/*Alocao de variaveis*/
  
int tam,i,j,menor;
long int n,d,a,b,endereço;

struct racional **vetor;
struct racional *ponteiro;
//struct racional soma; //tp2
//struct racional aux; //tp2: usado para ordenar o vetor.

/* programa principal */
int main ()
{
  /* a completar! */
  /*defina um vetor para até 100 números racionais
  */
  
  scanf("%d",&tam);

  vetor = malloc (sizeof(struct racional *)*tam); //entender a diferença entre struct racional* p


  if (!vetor)
  {
    printf ("erro ao alocar o vetor \n");
    exit (1); // testar qual a diferença entre exit
  }
  
  for (i = 0; i < tam; i++)
  { 

    *vetor = cria_r(0,0); //por que não podemos usar o vetor =?
    vetor++;
  }
  vetor = vetor - tam;

  for (i = 0; i < tam; i++)
  {
    imprime_r(*vetor); // estamos atribuindo o valor para o vetor.
    vetor++;
  }
  vetor = vetor - tam;
  printf("\n");

    for (i = 0; i < tam; i++)
  { 
    scanf("%ld",&a);
    scanf("%ld",&b);
    *vetor = cria_r(a,b); //por que não podemos usar o vetor =?
    vetor++;
  }
  vetor = vetor - tam;

  for (i = 0; i < tam; i++)
  {
    imprime_r(*vetor); // estamos atribuindo o valor para o vetor.
    vetor++;
  }
  vetor = vetor - tam;
  printf("\n");

// teste da função valido_r():
  for (i = 0; i < tam; i++)
  {
    if (valido_r(vetor[i]) == 0)
    {
      while (valido_r(vetor[tam])== 0)
          tam--;
      troca_r(vetor[i],vetor[tam]);
      tam--; 
    }
  }

/*Lista de Tarefas*/
//1.) Escrever o pseudo código para a troca de valores que estão na última posição.
  return (0) ;
}
