// programa principal do projeto "The Boys - 2024/2"
// Autor: Ramon Cesar Santos Alves, GRR 20204080


// seus #includes vão aqui
#include "theboys.h"
#include "conjunto.h"
#include "stdlib.h"
//definição de structs
struct heroi
{
  int ID;          //  numero inteiro ≥ 0 que identifica unicamente o her´oi;
  struct cjto_t Habilidades; // conjunto de habilidades que o her´oi possui. Cada habilidade eh representada por um n´umero inteiro ≥ 0;
  int Paciencia;  // n´umero inteiro ≥ 0 que indica qu˜ao paciente uma pessoa ´e. Em  nosso modelo, isso afeta as decis˜oes de permanˆencia em bases e filas;
  int Velocidade;// n´umero inteiro ≥ 0 indicando a velocidade de deslocamento de um her´oi, que ir´a afetar o tempo de deslocamento entre as bases;
  int experiencia;// n´umero inteiro ≥ 0 que indica o n´umero de miss˜oes em que o her´oi ´a participou;
  int Base; //ID da base onde o her´oi se encontra no momento.
} ;
struct base
{
  int ID; // n´umero inteiro ≥ 0 que identifica cada base;
  int Lotacao; // n´umero m´aximo de her´ois naquela base;
  struct cjto_t presentes ; //conjunto dos IDs dos her´ois que est˜ao atualmente na base, constituem as equipes dispon´ıveis para realizar miss˜oes;
  struct cjto_t Espera; // fila onde os her´ois esperam para poder entrar na base;
  int Local; // localiza¸c˜ao da base (par de coordenadas inteiras X, Y ≥ 0).
};

struct missao
{
  int ID;         // n´umero inteiro ≥ 0 que identifica a miss˜ao;
  int Habilidades;// conjunto de habilidades necess´arias para cumprir a miss˜ao;
  int Local;      // localiza¸c˜ao da miss˜ao (par de coordenadas inteiras X, Y ≥ 0).
};

struct mundo
{
  int NHerois;  // n´umero total de her´ois no mundo;
  struct heroi H[MAX]; //vetor representando todos os her´ois;
  int NBases;   //n´umero total de bases no mundo;
  struct base B[MAX];  // vetor representando todas as bases;
  int NMissoes;  // n´umero total de miss˜oes a cumprir;
  struct missao M[ MAX];// vetor representando todas as miss˜oes;
};
/*Funcoes auxiliares*/
int aleat(int min, int max)
{
	a = ;
	return a;
}
/*Principais funções*/
struct mundo *cria_mundo(int tam){ //implementação aleatória para ponteiro de ponteiros.
	struct mundo *world;

	world = malloc(sizeof(struct mundo)*tam);
	if (!world)
		return 0;

		world->NHerois = 0;  // n´umero total de her´ois no mundo;
		world->base = 0;   //n´umero total de bases no mundo;
		world->NMissoes = 0;  // n´umero total de miss˜oes a cumprir

	world = inicio;	
	return world;
}

struct heroi *cria_heroi(int tam){
	struct heroi *heroi;
	//int MAX = tam; //usado apenas para o exemplo

	heroi = malloc(sizeof(struct heroi)*tam);
	if (!heroi)
		exit;

	/*criação de variáveis mais simples*/
		heroi.ID = nherois;
		heroi.Paciencia = aleat(1,3);
		heroi.Velocidade = aleat (1,3);
		heroi.experiencia = NULL;
		heroi.Base = NULL;
		struct cjto_t Habilidades{aleat(1,10),aleat(1,10),aleat(1,10)}
	

	heroi = heroi - tam;
	/*criação e variáives mais complexas*/


	
	heroi = heroi - tam;

	return heroi;
}

struct base *cria_base(int tam){
	struct base *base;

	base = malloc(sizeof(struct base));
	if (!base)
		exit;
	
	for (i = 0; i <= tam; i++)
		base++;
	
	base = tam - mundo;

	return base;
}

struct missao *cria_missao(int tam){

	struct missao *missao;

	missao = malloc(sizeof(struct missao));
	if (!missao)
		exit;
	
	for (i = 0; i <= tam; i++){
		missao++;
		missao = NULL;
	}
	
	missao = missao - tam;
}
/*Funções para herois*/
modifica_heroi (atribuir parâmetros){
/*aumento de experiência*/
struct heroi aumento_de_nível (struct heroi h1, int exp){

	for (int i= 0; i < exp; i++) 
		heroi.Habilidades = Habilidades + aleat(1,10);

	return struct heroi;
}

destroi_heroi (habilidades){

	if exp > 3
}


}
adiciona_base


adiciona_missao (tam)