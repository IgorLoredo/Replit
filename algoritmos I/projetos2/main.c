#include<stdlib.h>
#include <stdio.h>
#include <math.h>

#define pi 3.14 // define o valor de pi como 3,14(nao sei se ta certo)

void dct(double *in,double *out,long size){
    int i,j;
    float t = 2.0;
    double matriz[size][size];
    for(j=0;j<size;j++){
        matriz[0][j] = 1.0/sqrt(size) * in[j];
    }
    for(i = 1;i<size;i++){
        for(j=0;j<size;j++){
            matriz[i][j] = sqrt(t/size) * cos(i*pi/(t*size) * (t*j+1)) * in[i];
        }
    }
    /*for(i=0;i<size;i++)
        out[i] =0; */

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            out[i]+=matriz[i][j];
        }
    }
}
int main(){
    int i;
    long tam;
    double *vetorIn;
    double *vetorOut = NULL;
    scanf("%ld",&tam);
    vetorIn = (double*)malloc(sizeof(double)*tam);
    vetorOut = (double*)malloc(sizeof(double)*tam); // coloca os espacos como zero
    for(i=0;i<tam;i++)
        scanf("%lf",&vetorIn[i]);
    
    dct(vetorIn,vetorOut,tam);

     for(i=0;i<tam;i++)
        printf("%lf\n",vetorOut[i]);
    return 0;
}