#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Coin_Library.h"

/* Cria uma arvore binária, onde recebe os dados da fila de mineração */

void maketree (ARV_BIN_ENC *t, char *hash_dest, char *hash_remet, char * signature, char * hora_criado,
char * hora_minerado ){
	*t = (ARV_BIN_ENC) malloc (sizeof(BLOCK));
	if(!(*t)){
		printf("Memoria Cheia\n");
		exit(1);
	}

	strcpy((*t)->hash_destinatario, hash_dest);
    strcpy((*t)->hash_remetente, hash_remet);
    strcpy((*t)->signature, signature);
    strcpy((*t)->hora_criado, hora_criado);
	strcpy((*t)->hora_minerado, hora_minerado);

	(*t)->left = NULL;
	(*t)->right = NULL;
	(*t)->father = NULL;
	(*t)->next = NULL;
}

/* Cria um filho esquerdo */

void setleft (ARV_BIN_ENC t, char *hash_dest, char *hash_remet, char * signature, char * hora_criado, char * hora_minerado){
	t->left = (ARV_BIN_ENC)malloc(sizeof(BLOCK));
	if(!(t->left)){
		puts("Memoria Cheia\n");
		exit(2);
	}
	strcpy(t->left->hash_destinatario, hash_dest);
    strcpy(t->left->hash_remetente, hash_remet);
    strcpy(t->left->signature, signature);
	strcpy(t->left->hora_criado, hora_criado);
	strcpy(t->left->hora_minerado, hora_minerado);

	t->left->left = NULL;
	t->left->right = NULL;
	t->left->next = NULL;
	t->left->father = t;

}

/* Cria um filho direito */

void setright (ARV_BIN_ENC t, char *hash_dest, char *hash_remet,  char * signature,  char * hora_criado, char * hora_minerado){
	t->right = (ARV_BIN_ENC)malloc(sizeof(BLOCK));
	if(!(t->right)){
		puts("Memoria Cheia\n");
		exit(2);
	}
	strcpy(t->right->hash_destinatario, hash_dest);
    strcpy(t->right->hash_remetente, hash_remet);
    strcpy(t->right->signature, signature);
	strcpy(t->right->hora_criado, hora_criado);
	strcpy(t->right->hora_minerado, hora_minerado);

	t->right->left = NULL;
	t->right->right = NULL;
	t->right->next = NULL;
	t->right->father = t;

}

/* Imprime as Informacoes de um nó da árvore */

void info (ARV_BIN_ENC t){
	printf("\nSignature: %s of Block\n", t->signature);
	printf("Destinatario: %s\n", t->hash_destinatario);
	printf("Remetente: %s\n", t->hash_remetente);
	printf("Hora que o Block foi Criado: %s\n", t->hora_criado);
	printf("Hora que o Block foi Minerado: %s\n", t->hora_minerado);
}

ARV_BIN_ENC left(ARV_BIN_ENC t){
	return t->left;
}
ARV_BIN_ENC right(ARV_BIN_ENC t){
	return t->right;
}
ARV_BIN_ENC father(ARV_BIN_ENC t){
	return t->father;
}
ARV_BIN_ENC brother(ARV_BIN_ENC t){
	if(father(t)){
		if(isleft(t))
			return right(father(t));
		}else return left(father(t));
	return NULL;
}
int isleft (ARV_BIN_ENC t){
	BLOCK *q = father(t);
	if(!q)
		return 0;
	if(left(q) == t)
		return 1;
	return 0;
}
int isright (ARV_BIN_ENC t){
	if(father(t))
		return (!isleft(t));
	return 0;
}

/* Insere um Nó da árvore com base na ordem cronológica de quando os blocos foram minerados */

void Inserting (ARV_BIN_ENC *t, BLOCK *b){

	if (!(*t)){
		maketree(t,b->hash_destinatario,b->hash_remetente, b->signature, b->hora_criado, b->hora_minerado );
		info(*t);	
	}else {
		ARV_BIN_ENC father = *t;
	do{
		if(ordem_cronologica(b->hora_minerado, father->hora_minerado)){
			if((*t)->left)
				father = (*t)->left;
			else{
				setleft(father, b->hash_destinatario, b->hash_remetente,b->signature, b->hora_criado, b->hora_minerado);
				info(father);
				break;
			}
		}else if((*t)->right)
				father = (*t)->right;
			  else {
			  	setright(father, b->hash_destinatario, b->hash_remetente,b->signature, b->hora_criado, b->hora_minerado);
			  	info(father);
				break;
			  }
	}while(1);
		}
}

/* Busca em Largura */
void percursoEmLargura(ARV_BIN_ENC arv){
	fila_busca fila;
	cria_queue(&fila);
		if(arv)
		ins_queue(fila,arv);
	while(!eh_vazia_queue(fila)){
		info(cons_queue(fila));
		if(left(cons_queue(fila)))
			ins_queue(fila, left(cons_queue(fila)));
		if(right(cons_queue(fila)))
			ins_queue(fila, right(cons_queue(fila)));
	ret_queue(fila);
	}
}

