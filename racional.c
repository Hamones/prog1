/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/

/* retorna um número aleatório entre min e max, inclusive. */
long aleat (long min, long max)
{
  return  (rand() % (max - min +1))+ min ;
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
long mdc (long a, long b)
{
 long resto ;
 while (b != 0)
	 {
		resto = (a % b);
		a = b;
		b = resto; 
	}
  return a;
}

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
	long x;
	x = (a * b) / mdc (a,b);
	return x;
}

/* Recebe um número racional e o simplifica.
 * Por exemplo, ao receber 10/8 deve retornar 5/4.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r (struct racional r)
{
	long valor;
	struct racional local;
	valor = mdc(r.num,r.den);

	local.num = r.num/valor;
	local.den = r.den/valor;

  
	if ( (local.num < 0 && local.den < 0) )
	{
		local.num = local.num *-1;
		local.den = local.den *-1;
	}
	if (local.num >= 0 && local.den < 0) 
	{
		local.num = local.num *-1;
		local.den = local.den *-1;
	}
	return local;
}

/* implemente as demais funções de racional.h aqui */
/* Cria um número racional com o numerador e denominador indicados. */
struct racional cria_r (long numerador, long denominador)
{
  	struct racional local;

    local.num = numerador;
    local.den = denominador;
	  local= simplifica_r(local);
  	return local;
}


/* Retorna 1 se o racional r for válido ou 0 se for inválido.
 * Um racional é inválido se seu denominador for zero */
int valido_r (struct racional r)
{
  	if (r.den == 0)
		return 0;
	else
		return 1;
}
/* Retorna um número racional aleatório na forma simplificada.
 * Deve ser sorteado o numerador e depois o denominador.
 * o racional gerado pode ser válido ou inválido.
 * O numerador e o denominador devem ser inteiros entre min e max. */
struct racional sorteia_r (long min, long max)
{

	struct racional a;
	long x,y;
	
	x = aleat (min, max);
	y = aleat (min, max);
   	a = cria_r(x,y);

	a=simplifica_r(a);

	return a;
}

/* Imprime um racional r, respeitando estas regras:
   - o racional deve ser impresso na forma simplificada;
   - não imprima espaços em branco e não mude de linha;
   - a saída deve ter o formato "num/den", a menos dos casos abaixo:
     - se o racional for inválido, imprime a mensagem "NaN" (Not a Number);
     - se o numerador for 0, imprime somente "0";
     - se o denominador for 1, imprime somente o numerador;
     - se o numerador e denominador forem iguais, imprime somente "1";
     - se o racional for negativo, o sinal "-" vem antes do numerador;
     - se numerador e denominador forem negativos, o racional é positivo. */
void imprime_r (struct racional r)
{	
	if (valido_r(r) == 0)
	{ 
		printf("INVALIDO ");		
	}
	else if (r.num == 0)
	{
		printf("0 ");
	}
	else if (r.den == 1)
	{
		printf("%ld ",r.num);
	}
	else if (r.den == r.num)
	{
		printf("1 ");
	}
	else
		printf("%ld/%ld ",r.num,r.den);
}
/* Compara dois racionais r1 e r2. Retorno: 
	-2 se r1 ou r2 for inválido,
	-1 se r1 < r2, 
	0  se r1 = r2 ou 1 se r1 > r2 */
int compara_r (struct racional r1, struct racional r2)
{	
	struct racional valor;
	subtrai_r(r1,r2,&valor);

	if (valido_r(r1) == 0 || valido_r(r2))
		return -2;
	if (valor.num < 0)
		return -1;
		else
			return 0;
	/* exemplo de diminuição:
	se a é menor b logo a-b <-0 ;
	se a é manior que b logo a - b > 0;
	se a é igual a b logo a - b = 0;
	*/

}
	

	
/* Retorna a soma dos racionais r1 e r2 no parametro *r3.
 * Retorna 1 se a operacao foi bem sucedida ou
 *         0 se r1 ou r2 for inválido ou se *r3 for nulo */
int soma_r (struct racional r1, struct racional r2, struct racional *r3)
//usar &agregado em *r3
{
	struct racional local;
  
  if (valido_r(r1) == 1|| valido_r (r2) == 1 || r3 == 0)
  {
    return 0;
  }
  
	local.num = (r1.num*r2.den) + (r2.num*r1.den);
	local.den = (r1.den*r2.den);

	local = simplifica_r(local); //não trabalha com ponteiros.
  	r3 = &local;
	return 1;
}


/* Retorna a subtracao dos racionais r1 e r2 no parametro *r3.
 * Retorna 1 se a operacao foi bem sucedida ou
 *         0 se r1 ou r2 for inválido ou se *r3 for nulo */
int subtrai_r (struct racional r1, struct racional r2, struct racional *r3)
//usar &agregado em *r3
{
	struct racional local;
  
  if (valido_r(r1) == 1|| valido_r (r2) == 1 || r3 == 0)
  {
    return 0;
  }
  
	local.num = (r1.num*r2.den) - (r2.num*r1.den);
	local.den = (r1.den*r2.den);

	local = simplifica_r(local); //não trabalha com ponteiros.
 	 r3 = &local;
	return 1;
}

/* Retorna a multiplicacao dos racionais r1 e r2 no parametro *r3.
 * Retorna 1 se a operacao foi bem sucedida ou
 *         0 se r1 ou r2 for inválido ou se *r3 for nulo */
int multiplica_r (struct racional r1, struct racional r2, struct racional *r3)
{
	struct racional local = {0,0};

	if (valido_r(r1) == 0 || valido_r(r2) || r3 == 0)
		return 0;
	else
		{		
		local.num = (r1.num * r1.num);
		local.den = (r2.den * r2.den);
		}

	local = simplifica_r(local);
	r3 = &local;
  return 1;
}

/* Retorna a divisao dos racionais r1 e r2 no parametro *r3.
 * Retorna 1 se a operacao foi bem sucedida ou
 *         0 se r1 ou r2 for inválido ou se *r3 for nulo */
int divide_r (struct racional r1, struct racional r2, struct racional *r3)
{
	struct racional local = {0,0};

	if (valido_r(r1) == 0 || valido_r(r2) || r3 == 0)
		return 0;
	else
		{		
		local.num = (r1.num * r2.den);
		local.den = (r1.den * r2.num);
		}

	local = simplifica_r(local);
  r3 = &local;
  return 1;
}
  
