// programa principal do projeto "The Boys - 2024/2"
// Autor: Ramon Cesar Santos Alves, GRR 20204080
#ifndef THEBOYS

// seus #includes vão aqui
#include "theboys.h"
// seus #defines vão aqui

// minimize o uso de variáveis globais

// programa principal
struct *cria_mundo(int tam){ //implementação aleatória para ponteiro de ponteiros.
	int inicio; //retorno do para posição inicial do ponteiro.
	int mundo*;

	mundo = malloc(sizeof(struct mundo)*tam;
	if (!mundo)
		return 0;

	inicio = *mundo;
	
	for (i = 0; i <= MAX; i++){
		mundo++;
		*mundo = NULL;
	}
	
	mundo = inicio;	
	return mundo;
}

struct heroi cria_heroi(int tam){
	struct heroi *inicio; //retorno do para posição inicial do ponteiro.
	struct heroi *heroi;

	int MAX = tam; //usado apenas para o exemplo

	heroi = malloc(sizeof(struct heroi)*tam);
	if (!heroi)
		return 0;

	inicio = heroi; 
	
	for (int i = 0; i < MAX; i++){
		heroi->ID = 0;
  		heroi->Habilidades = 0;
		heroi->Paciencia = 0;
		heroi->Velocidade = 0;
		heroi->Experiência = 0;
		heroi->Base = 0;
		heroi = sizeof(struct heroi) + heroi;
	}
	
	heroi = heroi - inicio.;
	return heroi;
}

struct *cria_base(){
	int inicio; //retorno do para posição inicial do ponteiro.
	int mundo*;

	mundo = malloc(sizeof(struct base);
	if (!mundo)
		return 0;

	inicio = mundo;
	
	for (i = 0; i <= MAX; i++){
		mundo*++; //atualizamos ao próximo ponteiro.
		mundo = NULL;
	}
	
	mundo = inicio;

	return mundo;
}

struct *cria_missao(){
		int inicio; //retorno do para posição inicial do ponteiro.
	int mundo*;

	mundo = malloc(sizeof(struct missao);
	if (!mundo)
		return 0;

	inicio = 
	
	for (i = 0; i <= MAX; i++){
		mundo*++;
		mundo = NULL;
	}
	
	mundo = inicio;	
}

#define THEBOYS
