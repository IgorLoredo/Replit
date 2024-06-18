#include <stdlib.h>
#include <stdio.h>
//#include <maze.h>
#include "maze.h"

int main(){
    int i,inicial,camada,aberto,c1,c2;
    float x,y;
    int npont,ncamara,nSeg;
    scanf("%d",&npont);
    LAB *labirinto = iniciar_lab(npont);

    for(i=0;i<npont;i++){
        scanf("%f %f",&x,&y);
        labirinto->vet[i] = iniciarGrafo(x,y);
        
    }

    scanf("%d",&ncamara);
    for(i=0;i<ncamara;i++){
        scanf("%d %d",&camada,&aberto);
        inseriCamara(labirinto,camada,aberto);
    } 

    scanf("%d",&nSeg);
    for(i=0;i<nSeg;i++){
        scanf("%d %d",&c1,&c2);
        if(c1>-1 || c2 >-1) // considero sÃ³ os segmentos sem obstaculos
            inseriSeg(labirinto,c1,c2);
    }

    scanf("%d",&inicial);
	processar(labirinto, inicial);
		//printf("mos\n");
    //free(labirinto);
    return 0;
}
	