/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 * Atualizado em 09/09/2025 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <racional.h>

/* aqui vem a struct racional propriamente dita, nao modifique! */
struct racional {
  long num;          /* numerador   */
  long den;          /* denominador */
};

/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/

/* Maximo Divisor Comum entre a e b      */
/* calcula o mdc pelo metodo de Euclides */
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

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
	long x;
	x = (a * b) / mdc (a,b);
	return x;
}

/* Simplifica o número racional indicado no parâmetro.
 * Por exemplo, se o número for 10/8 muda para 5/4.
 * Retorna 1 em sucesso e 0 se r for inválido ou o ponteiro for nulo.
 * Se ambos numerador e denominador forem negativos, o resultado é positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador. */
int simplifica_r (struct racional *r)
//struct racional simplifica_r (struct racional r)
{
	if (r.num == 00 && r.den == 0)
		return r;
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
* Retorna o numerador do racional r */
long numerador_r (struct racional r);

/* Retorna o denominador do racional r */
long denominador_r (struct racional r);

/* Cria um número racional com o numerador e denominador indicados
 * e retorna um ponteiro que aponta para ele.
 * A memória para o número racional deve ser alocada dinamicamente
 * por esta função. Retorna NULL se não conseguiu alocar a memória. */
struct racional *cria_r (long numerador, long denominador)
//struct racional cria_r (long numerador, long denominador)
{
    struct racional local;

    local.num = numerador;
    local.den = denominador;
	local= simplifica_r(local);
  	return local;
}


/* Libera a memória alocada para o racional apontado por r */
void destroi_r (struct racional **r);

/* Retorna 1 se o racional r for válido ou 0 se for inválido. Um racional
 * é inválido se o denominador for zero ou se ele não tiver sido alocado. */
int valido_r (struct racional *r)
{
//int valido_r (struct racional r)
  	if (r.den == 0)
		return 0;
	else
		return 1;
}
/* Imprime um racional r, respeitando estas regras:
   - o racional deve estar na forma simplificada;
   - não use espacos em branco e não mude de linha;
   - o formato de saída deve ser "num/den", a menos dos casos abaixo;
     - se o ponteiro for nulo, imprime a mensagem "NULL";
     - se o racional for inválido, imprime a mensagem "NaN" (Not a Number);
     - se o numerador for 0, imprime somente "0";
     - se o denominador for 1, imprime somente o numerador;
     - se o numerador e denominador forem iguais, imprime somente "1";
     - se o racional for negativo, o sinal é impresso antes do número;
     - se numerador e denominador forem negativos, o racional é positivo. */
void imprime_r (struct racional *r)
//void imprime_r (struct racional r)
{
	if (r==NULL)
  {
    printf("NULL"); //diferente de tp2.c
  }
    
	if (valido_r(r) == 0)
	{ 
		printf("INVALIDO");		
	}
	else if (r.num == 0)
	{
		printf("0");
	}
	else if (r.den == 1)
	{
		printf("%ld",r.num);
	}
	else if (r.den == r.num)
	{
		printf("1");
	}
	else
		printf("%ld/%ld",r.num,r.den);
}
/* Compara dois números racionais r1 e r2.
 * Retorna -2 se r1 ou r2 for inválido ou se o respectivo ponteiro for nulo.
 * Retorna -1 se r1 < r2; 0 se r1 = r2; 1 se r1 > r2.
 * Atenção: faça a comparação normalizando os denominadores pelo MMC.
 * Fazer a comparação baseado na divisão do numerador pelo denominador
 * pode gerar erro de arredondamento e falsear o resultado. */
int compara_r (struct racional *r1, struct racional *r2);

/* Coloca em *r3 a soma simplificada dos racionais *r1 e *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for inválido ou um ponteiro for nulo. */
int soma_r (struct racional *r1, struct racional *r2, struct racional *r3);

/* Coloca em *r3 a diferença simplificada dos racionais *r1 e *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for inválido ou um ponteiro for nulo. */
int subtrai_r (struct racional *r1, struct racional *r2, struct racional *r3);

/* Coloca em *r3 o produto simplificado dos racionais *r1 e *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for inválido ou um ponteiro for nulo. */
int multiplica_r (struct racional *r1, struct racional *r2, struct racional *r3);

/* Coloca em *r3 a divisão simplificada do racional *r1 por *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for inválido ou um ponteiro for nulo. */
int divide_r (struct racional *r1, struct racional *r2, struct racional *r3);

