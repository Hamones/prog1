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

struct racional simplifica_r (struct racional r);
long mmc (long a, long b);
long aleat (long min, long max);
long mdc (long a, long b);

/*Alocao de variaveis*/
  
int tam,i,j,menor;
long int n,d;

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
		scanf("%ld/%ld", &a,&b);
		if (a < 0 || b < 0 || a > 100 || b> 100)
			exit return(1);
    *vetor = cria_r(1,2); //por que não podemos usar o vetor =?
    vetor++;
  }
  vetor = vetor - tam;

  for (i = 0; i < tam; i++)
  {
    imprime_r(*vetor); // estamos atribuindo o valor para o vetor.
    vetor++;
  }
  printf("/n");





/*printf("VETOR = ");
  for (i= 0; i < tam ; i++)
    {
      for (i= 0; i < tam ; i++)
      imprime_r(v[i]); //deve imprimir "NaN"
      //printf("%ld/%ld \|",v[i].num,v[i].den);
    }
  printf("\n");

  for (i = 0; i < tam; i++) 
  {
    if (valido_r(v[i]) == 0) 
    {
      v[i] = v[tam-1];
      tam--;
      i--;
    }
  }*/
  
/*
  printf("VETOR = ");
  for (i= 0; i < tam ; i++)
    {
      for (i= 0; i < tam ; i++)
      imprime_r(v[i]); //deve imprimir "NaN"
      //printf("%ld/%ld \|",v[i].num,v[i].den);
    }
  printf("\n");

  for (i = 0; i < tam; i++)
  {A memória para o número racional deve ser alocada dinamicamente
    menor = i;
    {
      for (j = i; j < tam; j++)
        if (compara_r(v[j], v[menor]) == -1)
        {
          menor = j;
        }
    }
      if (i != j)
      {
      aux = v[i];
      v[i] = v[menor];
      v[menor] = aux;
    }
  }
  printf("VETOR = ");
  for (i= 0; i < tam ; i++)
    {
      for (i= 0; i < tam ; i++)b.num,ra
      imprime_r(v[i]); //deve iA memória para o número racional deve ser alocada dinamicamentemprimir "NaN"
      //printf("%ld/%ld \|",v[i].num,v[i].den);
    }
  printf("\n");
  printf("SOMA = ");
  soma = v[0];
  for (i= 1; i < tam; i++){
    soma_r(v[i], soma, &soma);
  }
  if (valido_r(soma))
  {
    imprime_r(soma);
  }
  else
  printf ("0");
  
  printf("\n");
  */
  
  return (0) ;
}
