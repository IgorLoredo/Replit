#include <stdio.h>
#include <stdlib.h>

/* 
struct PGM {
int c; // número de colunas na imagem
int l; // número de linhas na imagem
unsigned char maximo; // valor máximo para cada pixel
unsigned char **dados; // variável para armazenar os pixels da imagem (matriz)
};
*/
struct pgm{
	char *tipo; // tipo de imagem
	int l,c; // tamanho da matriz
	int apli;
	int **imagem;
};

void entrada(FILE *f1, struct pgm* entr ){
	f1 = fopen("img.txt","r");
	if(f1 == NULL){
		printf("ERRO AO LER");
		exit(1);
	}
	//entr->tipo = (char*)malloc(sizeof(char)*2);
	printf("vendo\n");
	fscanf(f1,"%s",entr->tipo);
	fscanf(f1, "%d %d", &entr->l,&entr->c);

}


int main(void) {
	FILE *img;
	struct pgm *entr;
	entrada(img,entr);

	printf("%s", entr->tipo);
	fclose(img);
  return 0;
}