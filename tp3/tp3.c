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

/* programa principal */
int main ()
{
  int i =1;
  long max,n;
  struct racional r1, sm, sub, mult, div;
  struct racional r2;
  struct racional r3;
  srand(0);

  /*    struct racional r1 = {0,0}
  struct racional r2 = {10,10}*/

  scanf("%ld",&n);

  if ((n < 0) || (n  > 100))
  return 1;

  scanf("%ld",&max);

  if ((max < 0) || (max > 30))
  return 1;
  while ( i <= n )
  {  
    /*
      criar um vetor de structs
      for (i = 1; i<n ; i++)
      {
        vet[i] = sorteia_r(-max, max);
      }
    */
    printf("%d: ",i);

    
    r1 = sorteia_r(-max, max);
    
    r2 = sorteia_r(-max, max);

    imprime_r(r1);
    printf(" ");
    imprime_r(r2);
    printf(" ");
    if (valido_r(r1) == 0|| valido_r(r2) == 0)
    {
        printf("NUMERO INVALIDO\n");
        return 1;
    }

    sm   = soma_r(r1,r2,&p3);
    sub  = subtrai_r(r1,r2,&p3);
    mult = multiplica_r(r1,r2,&p3);
    div  = divide_r(r1,r2);

    if (valido_r(div) == 0)
    {
        printf("DIVISAO INVALIDA\n");
        return 1;
    }

    
    //printf("%ld/%ld apenas printf   -   ",r1.num,r1.den);
    /*
    1 - Imprimir os valores
    2 - Imprimir o valor simplificado
    3 - Imprimir op valor não valido

    
    */

    /* 
    Imprimri soma/subtração;

    */
    imprime_r(sm);
    printf(" ");
    
    imprime_r(sub);
    printf(" ");
    /*
    Imprimir multiplicação
    */


    imprime_r(mult);
    printf(" ");        
    
    /*
    Imprimir divisão;
    */
    
    imprime_r(div);
    
    printf("\n");        
    i++;

  }
  return (0) ;
}

