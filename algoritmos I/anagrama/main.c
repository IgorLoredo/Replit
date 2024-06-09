//#include <hash.h>
#include <stdlib.h>
#include <stdio.h>

#include "hash.h"
int main(){
   // int PRIMO 1632703
    HASH *new =  criarHash(PRIMO);
    char *entrada = (char*)malloc(sizeof(char)*15);
    scanf("%s",entrada);
    FILE *arquivo = fopen(entrada,"r");
    processar(arquivo,new);

    free(entrada);
    fclose(arquivo);
    return 0;
}