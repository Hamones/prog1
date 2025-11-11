#ifndef THEBOYS
#define THEBOYS
#include "fila.h"
#include "pfrio.h"
#MAX 10000
// descreve um nodo da fila 
struct mundo
{
  int NHerois;  // n´umero total de her´ois no mundo;
  int Herois[MAX]; //vetor representando todos os her´ois;
  int NBases;   //n´umero total de bases no mundo;
  int Bases[MAX];  // vetor representando todas as bases;
  int NMissoes;  // n´umero total de miss˜oes a cumprir;
  int Missoes[MAX];// vetor representando todas as miss˜oes;
};
ID: n´umero inteiro ≥ 0 que identifica a miss˜ao;
• Habilidades: conjunto de habilidades necess´arias para cumprir a miss˜ao;
• Local: localiza¸c˜ao da miss˜ao (par de coordenadas inteiras X, Y ≥ 0).
// descreve uma fila 
struct heroi
{
  int ID;          //  numero inteiro ≥ 0 que identifica unicamente o her´oi;
  int Habilidades; // conjunto de habilidades que o her´oi possui. Cada habilidade eh representada por um n´umero inteiro ≥ 0;
  int Paciencia;  // n´umero inteiro ≥ 0 que indica qu˜ao paciente uma pessoa ´e. Em  nosso modelo, isso afeta as decis˜oes de permanˆencia em bases e filas;
  int Velocidade;// n´umero inteiro ≥ 0 indicando a velocidade de deslocamento de um her´oi, que ir´a afetar o tempo de deslocamento entre as bases;
  int Experiência; n´umero inteiro ≥ 0 que indica o n´umero de miss˜oes em que o her´oi ´a participou;
  int Base; //ID da base onde o her´oi se encontra no momento.
} ;
struct base
{
  int ID; // n´umero inteiro ≥ 0 que identifica cada base;
  int Lotacao; // n´umero m´aximo de her´ois naquela base;
  struct conj Presentes: //conjunto dos IDs dos her´ois que est˜ao atualmente na base, constituem as equipes dispon´ıveis para realizar miss˜oes;
  int Espera; // fila onde os her´ois esperam para poder entrar na base;
  int Local; // localiza¸c˜ao da base (par de coordenadas inteiras X, Y ≥ 0).
};

struct missao
{
  int ID;         // n´umero inteiro ≥ 0 que identifica a miss˜ao;
  int Habilidades;// conjunto de habilidades necess´arias para cumprir a miss˜ao;
  int Local;      // localiza¸c˜ao da miss˜ao (par de coordenadas inteiras X, Y ≥ 0).
};

/*funções para theboys.c*/

struct *cria_heroi();




#endif
