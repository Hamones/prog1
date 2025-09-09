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
      scanf("%ld",&n);
      v[i].num = n;
      scanf("%ld",&n); //adição de script1
      v[i].den = n;
    }
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
      scanf("%ld",&n);
      v[i].num = n;
      scanf("%ld",&n); //adição de script1
      v[i].den = n;
    }
  
  /*
  imprima "VETOR= " e o conteúdo do vetor lido
  */
  printf("VETOR = ");
  for (i= 0; i < tam-1 ; i++)
    {
      for (i= 0; i < tam ; i++)
      imprime_r(v[i]); //deve imprimir "NaN"
      //printf("%ld/%ld \|",v[i].num,v[i].den);
    }
  printf("\n");
  /*
  elimine deste vetor os elementos invalidos
  imprima "vet =" e o conteudo do vetor resultante
  */

  //código para remover vetor <-
  for (i = 0 ; i< tam;i++)
  {
    if (valido_r(v[i]) == 0)
    {
      for (i;i<tam;i++)//verificar se esse loop estah correto.
      {
        v[i] = v[++i];
      }
     tam--;
    }
  }
  while (valido_r(v[i]) == 0) // sem tam - 1 pode subs a var p/ lixo
  {
    if (i = tam)
      tam = tam -1;
    else
      v[i]=v[++i];
  }
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

  /*
  imprima "VETOR= " e o conteúdo do vetor lido
  */
  printf("VETOR = ");
  for (i= 0; i < tam-1 ; i++)
    {
      for (i= 0; i < tam ; i++)
      imprime_r(v[i]); //deve imprimir "NaN"
      //printf("%ld/%ld \|",v[i].num,v[i].den);
    }
  printf("\n");
  /*
  elimine deste vetor os elementos invalidos
  imprima "vet =" e o conteudo do vetor resultante
  */

  //código para remover vetor <-
  for (i = 0 ; i< tam;i++)
  {
    if (valido_r(v[i]) == 0)
    {
      for (i;i<tam;i++)//verificar se esse loop estah correto.
      {
        v[i] = v[++i];
      }
     tam--;
    }
  }
  while (valido_r(v[i]) == 0) // sem tam - 1 pode subs a var p/ lixo
  {
    if (i = tam)
      tam = tam -1;
    else
      v[i]=v[++i];
  }
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
