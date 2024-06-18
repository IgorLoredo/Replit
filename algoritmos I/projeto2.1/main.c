#include<stdlib.h>
#include <stdio.h>
#include <math.h>

/* dct ii  é a somantoria da multiplicação do vetor de entrada, o cosseno de pi sobre i tamanho do vetor de entreada vezes o valor atual de matriz de entrada vezes o j(k) mais 1/2;
cada membro do vetor novo é a somatoria 
*/
void dct(double *ino ,double *out, long size){
    int i,j;
    double temp=0; // variaveis para fazer o calculo
    for(i=0;i<size;i++){
			temp =0; // zera o valor de temp, pois ele é somatoria de cada valor novo
        for(j=0;j<size;j++){
          	temp += ino[j] *cos(i*M_PI/size*(j + 0.5)); 
        }
    out[i] = temp; // coloca o valor calculado no vetor de saida
   } 
}

int main(){
    int i;
    long tam; // guarda o tamanho do vetor de entrada 
    double *vetorIn = NULL;
    double *vetorOut = NULL; // cria os ponteiros
    scanf("%ld",&tam);
    vetorIn = (double*)malloc(sizeof(double)*tam);
    vetorOut = (double*)malloc(sizeof(double)*tam); // aloca os espaços 
    
    for(i=0;i<tam;i++)
        scanf("%lf",&vetorIn[i]);
    
    dct(vetorIn,vetorOut,tam);
		
     for(i=0;i<tam;i++)
        printf("%lf\n",vetorOut[i]);

    free(vetorIn); // libera a memoria 
    free(vetorOut);
    return 0;
}