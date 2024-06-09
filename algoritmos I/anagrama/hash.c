//#include <hash.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

//aloca ponteiro para habe
HASH *criarHash(unsigned long int tam){
    HASH *p = (HASH*)calloc(1,sizeof(HASH));
    p->primo = tam;
    p->table = (hashElem**)calloc(tam,sizeof(hashElem*));
    return p;
}

unsigned long int gerarHash(char*palavra){
    unsigned long int hash=1,i;
    unsigned long int aux;
    int *vetPri = (int*)malloc(27*sizeof(int));
    // vet com os primos pequenos
    vetPri[0] = 2;
    vetPri[1] = 3; 
    vetPri[2] = 5;
    vetPri[3] =7; 
    vetPri[4] =11; 
    vetPri[5] =13; 
    vetPri[6] =17; 
    vetPri[7] =19; 
    vetPri[8] =23; 
    vetPri[9] =29; 
    vetPri[10] =31; 
    vetPri[11] =37; 
    vetPri[12] =41; 
    vetPri[13] =43; 
    vetPri[14]= 47;
    vetPri[15]= 53;
    vetPri[16] =59;
    vetPri[17] =61;
    vetPri[18] =67;
    vetPri[19] =71;
    vetPri[20] =73; 
    vetPri[21] =79; 
    vetPri[22] =83; 
    vetPri[23] =89; 
    vetPri[24] =97; 
    vetPri[25] =101; 

    for(i=0;i<strlen(palavra);i++){
        aux = vetPri[(palavra[i]-97)];
        hash = (hash *aux) % PRIMO;
    }
    return hash;
}

hashElem *criarElem(int tam){
    hashElem* new = (hashElem*)calloc(1,sizeof(hashElem));
	new->quant=0;
    new->palavra = (char**)calloc(1,sizeof(char*));
	//new->palavra[new->quant] = (char*)calloc(tam+1,sizeof(char));
    return new;
}

int acharPosi(HASH* table, unsigned long int id, char*palavra){
    if(!table) return ERRO_HASH;
    if(!table->table[id]){
        hashElem *new = criarElem(1);
       new->palavra = (char**)realloc(new->palavra,sizeof(char*)*(new->quant+1));
        new->palavra[new->quant] = palavra;
		new->quant++;
        table->table[id] = new;        
    }
    else{
		
        hashElem **p = &table->table[id];
        (*p)->palavra = (char**)realloc((*p)->palavra,sizeof(char*)*(*p)->quant+1);
		//(*p)->palavra[(*p)->quant] = (char*)realloc((*p)->palavra[(*p)->quant],sizeof(char)*sizeof(palavra)+1);
    	(*p)->palavra[(*p)->quant] = palavra;
		(*p)->quant++;
     	//printf("%ld    %ld\n",id,(*p)->quant);

    }


    if(table->maior < table->table[id]->quant ){
	//	printf("%lu   %ld  %ld\n", table->table[id]->quant, id,table->maior);
	    table->maior = table->table[id]->quant;
		}
		
    return SUCESSO;
}

int vetHash(HASH *p,hashElem **vet){
	if(!p) return ERRO_HASH;
	int num=0;
	unsigned long int i;		//printf("aqui 2 %ld\n",id);
	//vet = (hashElem**)malloc(sizeof(hashElem*));
	for(i=0;i<p->primo;i++){
		if(p->table[i]){
			if(p->table[i]->quant == p->maior){
				vet = (hashElem**)realloc(vet,sizeof(hashElem*)*num+1);
				vet[num] = p->table[i];
				num++;
			}
		}
	}
	return num;
}

int printElem(hashElem* elem){
    if(!elem) return ERRO_HASH;
    //hashElem *elem= table->table[id];
    int i;
	//puts("entrou");
    for(i=0;i<elem->quant-1;i++)
        printf("%s, ",elem->palavra[i]);
	printf("%s",elem->palavra[i]);
    printf("\n");
	return SUCESSO;
}

int printAnagrama(int num,hashElem **vet){
	if(!vet) return ERRO_VET;
	int i;
	//puts("entrou");
	for(i=0;i<num;i++)
		printElem(vet[i]);

	return SUCESSO;
}

int processar(FILE* arq,HASH *table){
    if(!arq) return ERRO_ARQ;
    unsigned long int id=0;
    unsigned long int i=0;
    char **aux = (char**)malloc(sizeof(char*));
     aux[i] = (char*)malloc(sizeof(char)*20);

   while(fscanf(arq," %s",aux[i]) != EOF){
        id = gerarHash(aux[i]);
       	acharPosi(table,id,aux[i]);
         i++;
        aux = (char**)realloc(aux,sizeof(char*)*(i+1));
        aux[i] = (char*)malloc(sizeof(char)*20);
    }

	hashElem **vetResposta = (hashElem**)malloc(sizeof(hashElem*));

	int numAnagrama = vetHash(table,vetResposta);
	printf("%d\n",numAnagrama);
	printElem(vetResposta[1]);
	printAnagrama(numAnagrama,vetResposta);

	//printf("%ld\n",table->maior);
	//printElem(table,table->maior);

    
    return SUCESSO;
}

//#include <hash.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

//aloca ponteiro para habe
HASH *criarHash(unsigned long int tam){
    HASH *p = (HASH*)calloc(1,sizeof(HASH));
    p->primo = tam;
    p->table = (hashElem**)calloc(tam,sizeof(hashElem*));
    return p;
}

unsigned long int gerarHash(char*palavra){
    unsigned long int hash=1,i;
    unsigned long int aux;
    int *vetPri = (int*)malloc(27*sizeof(int));
    // vet com os primos pequenos
    vetPri[0] = 2;
    vetPri[1] = 3; 
    vetPri[2] = 5;
    vetPri[3] =7; 
    vetPri[4] =11; 
    vetPri[5] =13; 
    vetPri[6] =17; 
    vetPri[7] =19; 
    vetPri[8] =23; 
    vetPri[9] =29; 
    vetPri[10] =31; 
    vetPri[11] =37; 
    vetPri[12] =41; 
    vetPri[13] =43; 
    vetPri[14]= 47;
    vetPri[15]= 53;
    vetPri[16] =59;
    vetPri[17] =61;
    vetPri[18] =67;
    vetPri[19] =71;
    vetPri[20] =73; 
    vetPri[21] =79; 
    vetPri[22] =83; 
    vetPri[23] =89; 
    vetPri[24] =97; 
    vetPri[25] =101; 

    for(i=0;i<strlen(palavra);i++){
        aux = vetPri[(palavra[i]-97)];
        hash = (hash *aux) % PRIMO;
    }
    return hash;
}

hashElem *criarElem(int tam){
    hashElem* new = (hashElem*)calloc(1,sizeof(hashElem));
	new->quant=0;
    new->palavra = (char**)calloc(1,sizeof(char*));
	//new->palavra[new->quant] = (char*)calloc(tam+1,sizeof(char));
    return new;
}

int acharPosi(HASH* table, unsigned long int id, char*palavra){
    if(!table) return ERRO_HASH;
    if(!table->table[id]){
        hashElem *new = criarElem(1);
       new->palavra = (char**)realloc(new->palavra,sizeof(char*)*(new->quant+1));
        new->palavra[new->quant] = palavra;
		new->quant++;
        table->table[id] = new;        
    }
    else{
		
        hashElem **p = &table->table[id];
        (*p)->palavra = (char**)realloc((*p)->palavra,sizeof(char*)*(*p)->quant+1);
		//(*p)->palavra[(*p)->quant] = (char*)realloc((*p)->palavra[(*p)->quant],sizeof(char)*sizeof(palavra)+1);
    	(*p)->palavra[(*p)->quant] = palavra;
		(*p)->quant++;
     	//printf("%ld    %ld\n",id,(*p)->quant);

    }


    if(table->maior < table->table[id]->quant ){
	//	printf("%lu   %ld  %ld\n", table->table[id]->quant, id,table->maior);
	    table->maior = table->table[id]->quant;
		}
		
    return SUCESSO;
}

int vetHash(HASH *p,hashElem **vet){
	if(!p) return ERRO_HASH;
	int num=0;
	unsigned long int i;		//printf("aqui 2 %ld\n",id);
	//vet = (hashElem**)malloc(sizeof(hashElem*));
	for(i=0;i<p->primo;i++){
		if(p->table[i]){
			if(p->table[i]->quant == p->maior){
				vet = (hashElem**)realloc(vet,sizeof(hashElem*)*num+1);
				vet[num] = p->table[i];
				num++;
			}
		}
	}
	return num;
}

int printElem(hashElem* elem){
    if(!elem) return ERRO_HASH;
    //hashElem *elem= table->table[id];
    int i;
	//puts("entrou");
    for(i=0;i<elem->quant-1;i++)
        printf("%s, ",elem->palavra[i]);
	printf("%s",elem->palavra[i]);
    printf("\n");
	return SUCESSO;
}

int printAnagrama(int num,hashElem **vet){
	if(!vet) return ERRO_VET;
	int i;
	//puts("entrou");
	for(i=0;i<num;i++)
		printElem(vet[i]);

	return SUCESSO;
}

int processar(FILE* arq,HASH *table){
    if(!arq) return ERRO_ARQ;
    unsigned long int id=0;
    unsigned long int i=0;
    char **aux = (char**)malloc(sizeof(char*));
     aux[i] = (char*)malloc(sizeof(char)*20);

   while(fscanf(arq," %s",aux[i]) != EOF){
        id = gerarHash(aux[i]);
       	acharPosi(table,id,aux[i]);
         i++;
        aux = (char**)realloc(aux,sizeof(char*)*(i+1));
        aux[i] = (char*)malloc(sizeof(char)*20);
    }

	hashElem **vetResposta = (hashElem**)malloc(sizeof(hashElem*));

	int numAnagrama = vetHash(table,vetResposta);
	printf("%d\n",numAnagrama);
	printElem(vetResposta[1]);
	printAnagrama(numAnagrama,vetResposta);

	//printf("%ld\n",table->maior);
	//printElem(table,table->maior);

    
    return SUCESSO;
}

