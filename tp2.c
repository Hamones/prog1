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

      scanf("%ld",&d); //adição de script1

      v[i].num = n;
      v[i].den = d;
      v[i] = simplifica_r(v[i]);
    }
  
  /*
  imprima "VETOR= " e o conteúdo do vetor lido
  */
  printf("VETOR = ");
  for (i= 0; i < tam ; i++)
    {
      for (i= 0; i < tam ; i++)
      imprime_r(v[i]); //deve imprimir "NaN"
      //printf("%ld/%ld \|",v[i].num,v[i].den);
    }
  printf("\n");
  /*
  elimine deste vetor os elementos invalidos*/

  for (i = 0; i < tam; i++) 
  {
    if (valido_r(v[i]) == 0) 
    {
      for (j = i; j < tam - 1; j++) 
      {
        v[j] = v[j + 1];
      }
        tam--;
        i--;
    }
  }


  //código para remover vetor <-

  printf("VETOR = ");
  for (i= 0; i < tam ; i++)
    {
      for (i= 0; i < tam ; i++)
      imprime_r(v[i]); //deve imprimir "NaN"
      //printf("%ld/%ld \|",v[i].num,v[i].den);
    }
  printf("\n");
   /*
  Ordenar e imprimir o vetor
  pseudo código
  determinar o menor com v[0].
  comparar o vetor i com o vetor i+1
    se for menor armazenar o índice de i em menor.
    adicionar o menor vetor no início.
  pular a posição de i;
  */
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
  /*
  calcule a soma de todos os elemetnos do vetor
  imprima "SOMA =" e a soma calculada acima
  - percorrer todo o vetor uma vez.
  - acumular o valor da soma.
  */
  //soma_r(v[i],v[i+1],&soma);
  soma = v[0];
  for (i= 1; i < tam; i++){
    soma_r(v[i], soma, &soma);
  }
  imprime_r(soma);
  
  //printf("valor da soma: %ld/%ld", soma.num,soma.den);
  /*
  retorne 0
  */
  return (0) ;
}
