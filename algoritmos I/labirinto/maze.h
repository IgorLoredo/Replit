#ifndef maze_h
#define maze_h

#define SUCESS 0
#define ERRO_LAB -1
#define ERRO_PILHA -2

struct grafo{
    float x,y;
    char aberto;
    char camara;
    int vistado;
    int liga;
    struct grafo **no;
};

struct lab{
    int Npontos,Ncamaras,Nsegmentos;
    struct grafo **vet;
};

struct pilha {
	int lugar;
	int *vet;
};

typedef struct pilha PILHA;
typedef struct grafo GRAFO;
typedef struct lab LAB;

PILHA *criarpilha();
int empilhar(PILHA*,int);
int reempilhar(PILHA*);
LAB *iniciar_lab(int);
GRAFO *iniciarGrafo(float,float);
int inseriCamara(LAB*,int,int);
int inseriSeg(LAB*,int,int);

int **processar(LAB*,int);
 
#endif