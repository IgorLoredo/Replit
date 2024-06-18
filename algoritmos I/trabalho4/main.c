#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
  char *nome;
  char *sobrenome;
  char *cpf;
  char *telefone;
	int counter;
};
// int argc, int *argv[]
void iniciar(struct list*);
void cadrastrar(struct list*);
void busca(struct list*,char*);
int main(){
    struct list *lista;
		lista = (struct list*)malloc(sizeof(struct list)*lista->counter+1);
    char *op;
		char *buscar;
		buscar = (char*)malloc(sizeof(char)*11);
    op = (char*)malloc(sizeof(char)*15);
    scanf(" %s", op);
		while(strcmp(op,"sair")== 0){
			if(strcmp(op, "dmp") == 0) // print

			if(strcmp(op, "sair") == 0){
				scanf(" %s",buscar);

			}
			
    return 0;
	}
}

void iniciar(struct list *lista) {
    lista->nome = (char*)malloc(sizeof(char)*15);
    lista->sobrenome = (char*)malloc(sizeof(char)*15);
    lista->cpf = (char*)malloc(sizeof(char)*11);
    lista->telefone = (char*)malloc(sizeof(char)*20);
}

void cadrastrar(struct list *p){
	p = (struct list*)realloc(p, p->counter*sizeof(struct list)+1);
	iniciar(p);
	
	scanf(" %s", p->nome);
	scanf(" %s", p->sobrenome);
	scanf(" %s", p->cpf);
	scanf(" %s", p->telefone);
	p->counter++;
}

void busca(struct list* p,char*bus){
	while();
}