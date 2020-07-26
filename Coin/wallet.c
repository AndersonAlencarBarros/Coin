#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Coin_Library.h"

/* Cria a Lista de Carteiras */

void cria_lista_wallet (LISTA_ENC *p){
	*p=NULL;
}

/* Verifica se a Lista de Carteiras é vazia */

int eh_vazia_lista (LISTA_ENC p){
		return (p==NULL);
}

/* Retorna o tamanho da Lista */

int tam_lista (LISTA_ENC p){
	 int i;

	 for(i=0;p!=NULL;i++)
	 	p = p->next;
	return (i);

}

/* Funcao para criar uma Carteira. 
   Todas as Carteiras já iniciam com 5 Coins.
*/

void criar_carteira(LISTA_ENC *p, int k){
	NODO *novo;

	if(k<1 || k> tam_lista(*p)+1){
		printf("\nERRO! Posicao invalida\n");
		exit(1);
	}
	novo = (NODO*) malloc(sizeof(NODO));
		if(!novo){
			printf("\nErro! Memoria cheia\n");
			exit(2);
		}

	generate_hash(novo->PrivateKey);
	generate_hash(novo->PublicKey);
	novo->Coin = 5;
	printf("  PublicKey:\t%s\n  PrivateKey:\t%s\n  Coins:\t%.2f\n",novo->PublicKey, novo->PrivateKey, novo->Coin );

	if(k==1){
		novo->next = *p;
		*p = novo;
	}else{
		LISTA_ENC aux;
		for(aux=*p;k>2;aux=aux->next,k--);
		novo->next = aux->next;
		aux->next = novo;
	}
}

/* Funcao para realizar uma transação.
	Recebe a Chave Pública do destinatário, na qual identifica uma
	carteira que irá receber uma certa quantidade de Coins
	e a Chave Privada de quem está enviando, pois a Chave Privada
	realiza a mesma função de uma senha, e permite a realização da transferência  
*/
void transacao (LISTA_ENC p, FILA_ENC f){      // transacao/transferenci
	NODO *aux,*aux1;
	aux = aux1 = p;
	char key[10], key2[10];
	float coin;
	int logic = 1;

	puts("\nInsira a PublicKey do Destinatario\n");
		scanf("%s", key);
	while(aux){
		if(!(strcmp(aux->PublicKey,key))){
			logic = 0;
			break;
		}
			aux = aux->next;
	}
	if(logic){
		puts("\nPublicKey Nao Encontrada\n");
		exit(1);
	}

	logic = 1;
	puts("\nInsira a sua PrivateKey\n");
		scanf("%s", key2);
	while(aux1){
		if(!(strcmp(aux1->PrivateKey,key2))){
			logic = 0;
			break;
		}
			aux1 = aux1->next;
	}
	if(logic){
		puts("\nPrivateKey Nao Encontrada\n");
		exit(1);
	}

	printf("\nInsira a quantidade de Coins a ser Transferida\n");
		scanf("%f", &coin);

			if(aux1->Coin < coin){
				puts("\nSaldo Insuficiente\n");
				exit(1);
			}else{
				aux->Coin += coin;
				aux1->Coin -= coin;
				printf("\nSaldo Transferido\n 	%s: Saldo %.2f\n 	%s: Saldo %.2f\n",aux->PublicKey, aux->Coin, aux1->PublicKey, aux1->Coin);
                ins_bloco_fila(f,aux->PublicKey, aux1->PublicKey);

			}

}

/*
	Função de Impressão das Chaves, o trabalho é pensado como se vários usuários
	realizassem transferências, como não é o caso aqui nesse projeto, e para fins
	de exemplificação
*/
void imprimir_publicKeys(LISTA_ENC p){

   NODO* l;
   for (l = p; l != NULL; l = l->next){
		printf("\nPublicKey: %s", l->PublicKey);
		printf("\nPrivateKey: %s", l->PrivateKey);
		printf("\nSaldo: %.2f", l->Coin);
		printf("\n");
	}
}

