/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>

/* coloque aqui as funções auxiliares que precisar neste arquivo */

/* programa principal */
int main ()
{
  /* a completar! */
  /*defina um vetor para até 100 números racionais
  */
  int *vet;
  int tam;
  int i;
  tam = 100;
  vetor = malloc (tam*sizeof(int));
  if (!vetor)
  {
    printf("erro ao alocar o vetor\n");
    return 1;
  }
  for (i = 0; i < tam ;i++)
    vetor[i]= NULL;
  //alocar dados no vetor que 

  /*
  leia um valor n tal que 0 < n < 100
  */
  scanf("%d",&n);
  if (n< 0 || n>100)
    return 1;
  /*
  preencha o vetor com n númerros racionais lidos da entrada
  (leia o numerador e o denominador de cada racional
  */
  vetor = &script;
  /*
  imprima "VETOR= " e o conteúdo do vetor lido
  */
  printf("VETOR= ",&vetor)
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
