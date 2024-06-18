#include <stdlib.h>
#include <stdio.h>
//#include <maze.h>
#include "maze.h"

GRAFO *iniciarGrafo(float x,float y){
    GRAFO *new = (GRAFO*)calloc(1,sizeof(GRAFO));
    new->y = y;
    new->x = x;
    return new;
}

LAB *iniciar_lab(int n){
    LAB *new = (LAB*)calloc(1,sizeof(LAB));
    new->vet = (GRAFO**)malloc(sizeof(GRAFO*)*n);
    return new;
} 

int inseriCamara(LAB*p,int camara,int aberto){
    if(!p) return ERRO_LAB; 
    p->vet[camara]->aberto = aberto;
    return SUCESS;
}

int inseriSeg(LAB *lab, int c1, int c2){
    if(!lab) return ERRO_LAB;

  	GRAFO **p = &lab->vet[c1];
    (*p)->no = (GRAFO**)realloc((*p)->no,(sizeof(GRAFO*)*(*p)->liga)+1);
    
    //GRAFO ***aux;
    (*p)->no[(*p)->liga] = lab->vet[c2];

    (*p)->liga++;
    return SUCESS;
}

/*int *resultado(LAB* lab,int x){
	int *vet = (int*)malloc(sizeof(int));
	return vet;
}*/

int empilhar(PILHA* pilha,int x){
	if(!pilha) return ERRO_PILHA;
	pilha->lugar++;
	pilha->vet = (int*)realloc(pilha->vet,sizeof(int)*pilha->lugar);
	return SUCESS;
}

int reempilhar(PILHA* pilha){
	if(!pilha) return ERRO_PILHA;
	int x = pilha->vet[pilha->lugar];
	pilha->lugar--;
	pilha->vet = (int*)realloc(pilha->vet,sizeof(int)*pilha->lugar);
	return x;	
}

PILHA *criarpilha(){
	PILHA *novo= (PILHA*)calloc(1, sizeof(PILHA));
	return novo;
}

int **processar(LAB *lab,int inicial){
	//if(!lab) return ERRO_LAB;
	PILHA *pi = criarpilha();
	int **vet = (int**)calloc(1,sizeof(int*));
	GRAFO **p = &lab->vet[inicial];
	GRAFO **aux;
	int flag,nCamara;
	int segPercorridos;
	
	while(flag){
		while((*p)->aberto == 1){
			empilhar(pi,x);
			p = &(*p)->no[(*p)->vistado];
		}

	
	}
	
	return SUCESS;
}