#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/* coloque aqui as funções auxiliares que precisar neste arquivo */
struct racional simplifica_r (struct racional r);
long mmc (long a, long b);
long aleat (long min, long max);
long mdc (long a, long b);

/* programa principal */
int main ()
{
  /* a completar! */
  /*defina um vetor para até 100 números racionais
  */
  srand(0);
  int tam,i,j,menor;
  long int n,d;

  scanf("%d",&tam);

  struct racional v[tam];
  struct racional soma;
  
  struct racional aux; //usado para ordenar o vetor.

  for (i= 0; i < tam ; i++)
      v[i]= cria_r(0,0);

  for (i= 0; i < tam ; i++)
    { 
      scanf("%ld",&n);

      scanf("%ld",&d);

      v[i]= cria_r(n,d);
    }
  

  printf("VETOR = ");
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
  }

  printf("VETOR = ");
  for (i= 0; i < tam ; i++)
    {
      for (i= 0; i < tam ; i++)
      imprime_r(v[i]); //deve imprimir "NaN"
      //printf("%ld/%ld \|",v[i].num,v[i].den);
    }
  printf("\n");

  for (i = 0; i < tam; i++)
  {
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
      for (i= 0; i < tam ; i++)
      imprime_r(v[i]); //deve imprimir "NaN"
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
  return (0) ;
}
