// programa principal do projeto "The Boys - 2024/2"
// Autor: Ramon Cesar Santos Alves, GRR 20204080

// seus #includes vão aqui
#include "ftheboys.c"
// seus #defines vão aqui

// minimize o uso de variáveis globais

// programa principal
int main ()
{


  // iniciar o mundo
	caracteŕisticas do mundo
	
/* Implementações Iniciasi.*/


int **mundo;
int *heroi;
int *missao;
int *base;

Mundo - tamanho do mundo. Base e Altura.
mundo()

-Herói
--criar vetor herois [];
heroi = cria_heroi();
heroi.posição = ;
--posição(variável) == posiçao inicial (Rand(min max) //(x,y) que seria a posição aleatória. /* evitar e de criar o personagem dentro de uma base*/ caso for um local de base fazer o calculo novamente. 
heroi.habilidades = ;
--habilidades == {h1,h2,h2,h4,h5,h6} //vetor simples.
heroi.experiência = ;
--experiência == aumenta quando a missão acontece. //poderíamos aumentar quando ele se desloca, mas ele também pode ser expulso da base.
heroi.deslocamento = ;
--deslocamento == tempo para a missão mais próxima.
---verificar todas as bases -> escolher a mais próxima. 
----não retornar para base anterior.
---criar a função tempo que descide o tempo para chegar em outra base.
----evitar conflitos com outras bases.
evento.heroi;
--Morrer == v[H1] = NULL;

-Base
--criar vetor base[].
--posição (fixa) == posição inicial (Rand(min Max)) // (x,y) que seria a posição aleatória. /*evitar que uma missão fique dentro.
--lista de heróis (o tamanho varia?) == 
--lista de espera (fixo) == 
--porteiro ==  


  // executar o laço de simulação
/*Eventos*/

iniciar evento com maior prioridade.
gerar novos eventos na fila de prioridade.
executar alterações no mundo.

iniciar eventos pequenos.
- deslocamento do herói.
iniciar eventos grandes.
- tempo de permanência do herói
--se agente sair = atualzar conjunto
iniciar missões.
- concluir a missão: verificar todos os conjuntos das bases.
- decidir qual herói tomará a poção.

  // destruir o mundo
/*Liberar ponteiros:
- Executar de funções destroi para todos os ponteiros.*/
  return (0) ;
}

