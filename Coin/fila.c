#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Coin_Library.h"

/* Funcao que cria a fila de mineração */

void cria_fila_mineracao (FILA_ENC *f){
	*f = (DESCRITOR *) malloc (sizeof(DESCRITOR));
		if(!*f){
			puts("Memoria Insuficiente\n");
			exit(1);
		}
	(*f)->INICIO = (*f)->FIM = NULL;
	(*f)->N = 0;
}

/* Verifica se a fila é vazia */

int eh_vazia_fila (FILA_ENC f){
	return (f->INICIO == NULL);
}

/* Retorna o tamanho da fila */

int tam_fila (FILA_ENC f){
	return (f->N);
}

/* Insere um bloco na fila de mineração */

void ins_bloco_fila (FILA_ENC f, char* hash_d, char* hash_r ){
	BLOCK *novo;
	novo = (BLOCK *) malloc(sizeof(BLOCK));
		if(!novo){
			puts("Memoria Insuficiente\n");
			exit(2);
		}
	printf("\nFila de Mineracao\n");
    strcpy(novo->hash_destinatario, hash_d);
    strcpy(novo->hash_remetente, hash_r);
    get_time(novo->hora_criado);
    printf("Hora que o bloco foi criado: %s\n",novo->hora_criado);

	novo->next = NULL;
	if(eh_vazia_fila(f)){
		f->INICIO = novo;
	}else
		f->FIM->next = novo;
	f->FIM = novo;
	f->N++;
}

/* Funcao para minerar o bloco, onde cria o hash da "signature" do bloco */

void minerar (FILA_ENC f, ARV_BIN_ENC *t){
	BLOCK *aux;

	if(eh_vazia_fila(f)){
		puts("Fila de Mineracao Vazia\n");
		main();//exit(4);
	}else{
			
	puts("\nMinerando um Bloco...\n");
	delay(5000);
    generate_hash(f->INICIO->signature);
    get_time(f->INICIO->hora_minerado);
    Inserting (t,f->INICIO);

		aux = f->INICIO;
		f->INICIO = f->INICIO->next;
			if(!f->INICIO)
				f->FIM = NULL;
		free(aux);
	}
}

