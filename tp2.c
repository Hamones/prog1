/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/* coloque aqui as funções auxiliares que precisar neste arquivo */

/* programa principal */
int main ()
{
  /* a completar! */
  /*defina um vetor para até 100 números racionais
  */
  int tam,n,num,den;
  struct racional vetor[tam];

  /*
  leia um valor n tal que 0 < n < 100
  */
  //opção 1:
  for (i= 0; i < (tam-1) ; i++)
    {
      v[i].num -> 0;
      v[i].den -> 0;
    }
  //opção 2:
    for (i= 0; i < (tam-1) ; i++)
    {
      scanf("%d %d,&num,&den);
      criar_r(num,den);
    }
  /* 
  preencha o vetor com n númerros racionais lidos da entrada
  (leia o numerador e o denominador de cada racional
  */
  for (i= 0; i < (tam-1) ; i++)
    {
      scanf("%d",&n);
      v[i].num -> n;
      scanf("%d",&n);
      v[i].den -> n;
    }
  /*
  imprima "VETOR= " e o conteúdo do vetor lido
  */
  for (i= 0; i < (tam-1) ; i++)
    {
      printf("VETOR= ");
      imprime_r(
    }
  
  /*
  elimine deste vetor os elementos inválidos
  imprima "vet =" e o conteúdo do vetor resultante
  */
    
  /*
  calcule a soma de todos os elemetnos do vetor
  imprima "SOMA =" e a soma calculada acima
  */
  /*
  retorne 0
  
  */

  return (0) ;
}
