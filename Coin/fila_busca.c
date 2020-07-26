#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Coin_Library.h"

/*
	Todas as funções adiante se referem a busca em largura na árvore:
	criar uma fila, verificar se é vazia, inserir na fila, consultar e remover.
*/

void cria_queue (fila_busca *f){
	*f = (DES_ARV *) malloc (sizeof(DES_ARV));
		if(!*f){
			puts("Memoria Insuficiente\n");
			exit(1);
		}
	(*f)->INICIO = (*f)->FIM = NULL;
}

int eh_vazia_queue (fila_busca f){
	return (f->INICIO == NULL);
}

void ins_queue (fila_busca f, ARV_BIN_ENC t){
	fila_arv *novo;
	novo = (fila_arv *) malloc(sizeof(fila_arv));
		if(!novo){
			puts("Memoria Insuficiente\n");
			exit(2);
		}
	novo->tree = t;
	novo->next = NULL;
	
	if(eh_vazia_queue(f)){
		f->INICIO = novo;
	}else
		f->FIM->next = novo;
	f->FIM = novo;
			
}

ARV_BIN_ENC cons_queue (fila_busca f){
	if(eh_vazia_queue(f)){
		puts("Fila Vazia\n");
		exit(3);
	}else
		return (f->INICIO->tree);
}

void ret_queue (fila_busca f){
	fila_arv *aux;			
	
	if(eh_vazia_queue(f)){
		puts("Fila de Arvore Vazia\n");
		exit(4);
	}else{
		aux = f->INICIO;
		f->INICIO = f->INICIO->next;
			if(!f->INICIO)
				f->FIM = NULL;
		free(aux);
	}	
}

ARV_BIN_ENC cons_ret_queue (fila_busca f){
	if(eh_vazia_queue(f)){
		puts("Fila Vazia\n");
		exit(4);
	}else{
		ARV_BIN_ENC v = cons_queue(f);
		ret_queue(f);
		return v;	
	}
}
