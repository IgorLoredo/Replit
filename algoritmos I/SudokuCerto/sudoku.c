#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include "sudoku.h"

// cria a aloca matriz
char **criarMat(int tam){
	if(tam <=0){ printf("erro tamanho da matriz"); return NULL;}
	int i;
	char **matriz = (char**)calloc(tam,sizeof(char*));
	for(i =0; i<tam;i++)
		matriz[i] = (char*)calloc(tam,sizeof(char));
	
	return  matriz;
}

// ler Sudoku
int lerSudoku(char**matriz,int tam ){
	if(!matriz) return ERRO_MATRIZ;
	int i,j;
	for(i=0;i<tam;i++)
		for(j=0;j<tam;j++)
			scanf(" %c", &matriz[i][j]);
	return SUCESSO;
}


int printSudoku(char** mat,int tam){
	if(!mat) return ERRO_MATRIZ;
	int i,j;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			printf("%c", mat[i][j]);
		}
	printf("\n");
	}
	return SUCESSO;
}

int conferer(char**mat,int x,int y, int *pos){
	int i,j;
	int flagQuadrado = 16; // seta 16 para todos os flag
	int flagColuna = 16;
	int flagLinha = 16;
	int index=0;
	int posi = (x/4)*4;
	int posj = (y/4)*4;

	int *vet = (int*)calloc(16,sizeof(int));
	fflush(stdin);
	for(i = posi; i < (posi+4); i++){
		for(j =posj; j < (posj+4) ;j++){
			
				if( isdigit(mat[i][j]) == 1){ // confere se é um numero 
					vet[mat[i][j]-48]++;
					flagQuadrado--;
				}
				else{ 
					if(!ispunct(mat[i][j])){
					vet[mat[i][j]-55]++;
					//flagQuadrado--;
				}

			//flagQuadrado--;
			}
		}
	}

	// confere a linha 
	for(i=0;i < 16 ;i++){
		if( isdigit(mat[i][y] == 1) ){ // confere se é um numero 
				vet[mat[i][y]- 48]++;
				flagLinha--;
			}
			else {
				if(!ispunct(mat[i][y])){
					vet[mat[i][y]-55]++;
				flagLinha--;
			}
		
		}
	}



	for(j=0 ; j < 16; j++){

			if( isdigit(mat[x][j] == 1 ) ){ // confere se é um numero 
				vet[mat[x][j] - 48]++;
			}
			else {
				if(!ispunct(mat[x][j])){
				vet[mat[x][j] - 55]++;
				flagColuna--;
			}
		
		}
		
	}
	
	index  = 0 ; // setar posição como zero
	printf("%d %d %d\n",flagLinha,flagColuna,flagQuadrado);
	if(flagLinha == 0 || flagColuna == 0 || flagQuadrado == 0){
		
		// acha o numero com tem a maior possibilidade de ser
		for(i =0;i<16;i++){
			if(vet[i] > index){
				index = vet[i];
				*pos = i;
			}	
		}
		return 1;
	} else {
		return 0;
	}

}

int Sudoku(char **mat,int tam){
	if(!mat) return ERRO_MATRIZ;
	int i,j;
	int pos = 1,num,flag = 1;
	char *vetResposta = (char*)malloc(sizeof(char)*15);

	for(i = 0; i < tam;i++){
		if(i < 10)
			vetResposta[i] = (char)(i+48);
		else
			vetResposta[i] = (char)(i+55);
	}

	while(flag){
		pos = 1;
		for(i= 0; i <tam && pos ;i++){
			for(j =0; j<tam && pos;j++){
				if(ispunct(mat[i][j])){
					num = conferer(mat,i,j,&pos);
						if(num == 1){ 
							//printf("entrou %d %d j%c\n",i,j,mat[i][j]);
							mat[i][j] = vetResposta[pos]; 
							pos =0;
						}
				}
			}
			if( i >= tam-1 && j >= tam-1 ){
				flag = 0;
			} 
			

		}
	}


	return SUCESSO;
}