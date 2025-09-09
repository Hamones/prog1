/* Tipos Abstratos de Dados - TADs
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
  srand(0);
  int tam,i;
  long int n;

  scanf("%d",&tam);

  struct racional v[tam];
  struct racional soma;
  /*
  leia um valor n tal que 0 < n < 100
  */
  //opção 1:
	
	/*if (tam < 0 || tam >100)
		return 1;
  */
  
  for (i= 0; i < tam ; i++)
    {
      v[i].num = 0;
      v[i].den = 0;
    }
  i=0;
  /*opção 2:
    for (i= 0; i < (tam-1) ; i++)
    {
      scanf("%d %d,&num,&den);
      criar_r(v[i]);
    }*/
  /* 
  preencha o vetor com n númerros racionais lidos da entrada
  (leia o numerador e o denominador de cada racional
  */
  for (i= 0; i < tam ; i++)
    { 
      scanf("%ld",&n)
      v[i].num = n;
      scanf("%ld",&n); //adição de script1
      v[i].den = n;
    }
  
  /*
  imprima "VETOR= " e o conteúdo do vetor lido
  */
  for (i= 0; i < tam-1 ; i++)
    {
      for (i= 0; i < tam ; i++)
      imprime_r(v[i]); //deve imprimir "NaN"
      //printf("%ld/%ld \|",v[i].num,v[i].den);
    }
  
  /*
  elimine deste vetor os elementos inválidos
  imprima "vet =" e o conteúdo do vetor resultante
      for (l= 0; l < (tam-1) ; l++)
    {
      if ( valido_r(v[l]) == 1)
        v[l] = v[++l]; //funciona em v[tam]?
      
        printf("VETOR= ");
      imprime_r(v[l]); //deve imprimir "NaN"
    }
    */

  /*
  calcule a soma de todos os elemetnos do vetor
  imprima "SOMA =" e a soma calculada acima
  */
  soma_r(v[i],v[++i],&soma);
  printf("\n");
  printf("valor da soma: %ld/%ld", soma.num,soma.den);
  /*
  retorne 0
  */
  return (0) ;
}
