#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define max 10

/******************		STRUCTS		***********************/

typedef struct node{
	char hash_remetente[max];
	char hash_destinatario[max];
	char signature[max];
    char hora_criado[30];
    char hora_minerado[30];

    struct node *left;
	struct node *right;
	struct node *father;
	struct node *next;
}BLOCK;

typedef BLOCK *ARV_BIN_ENC;

typedef struct{
	BLOCK *INICIO;
	BLOCK *FIM;
	int N;
}DESCRITOR;

typedef DESCRITOR *FILA_ENC;

typedef struct nodo{
	ARV_BIN_ENC tree;
	struct nodo *next;
}fila_arv;

typedef struct{
	fila_arv *INICIO;
	fila_arv *FIM;
}DES_ARV;

typedef DES_ARV *fila_busca;

typedef struct nodo_lista{
	char PrivateKey[max];
    char PublicKey[max];
    float Coin;
	struct nodo_lista *next;

}NODO;

typedef NODO *LISTA_ENC;


/******************		FUNCOES		***********************/

	/*      FIlA        */

void cria_fila_mineracao (FILA_ENC *);
int eh_vazia_fila (FILA_ENC );
int tam_fila (FILA_ENC );
void ins_bloco_fila (FILA_ENC , char* , char*  );
void minerar (FILA_ENC , ARV_BIN_ENC *);


	/*      ARVORE      */

void maketree (ARV_BIN_ENC *, char *, char *, char *, char *,char *);
void precursoEmLargura(ARV_BIN_ENC );
void setleft (ARV_BIN_ENC t, char *, char *, char *, char *,char *);
void setright (ARV_BIN_ENC t, char *, char *, char *, char *,char *);
void info (ARV_BIN_ENC);
ARV_BIN_ENC left(ARV_BIN_ENC);
ARV_BIN_ENC right(ARV_BIN_ENC);
ARV_BIN_ENC father(ARV_BIN_ENC);
ARV_BIN_ENC brother(ARV_BIN_ENC);
int isleft (ARV_BIN_ENC);
int isright (ARV_BIN_ENC);
void Inserting (ARV_BIN_ENC *, BLOCK * );


	/*      LISTA WALLET      */

void cria_lista_wallet(LISTA_ENC *);
int eh_vazia_lista (LISTA_ENC);
int tam_lista (LISTA_ENC);
void criar_carteira (LISTA_ENC *, int);
void excluir_wallet (LISTA_ENC *);
void transacao (LISTA_ENC , FILA_ENC );
void imprimir_publicKeys (LISTA_ENC);

	/*      MOEDA      */
	
void generate_hash(char *);
void get_time(char *);
void delay(unsigned int );

	/*      BUSCA EM LARGURA     */

void cria_queue (fila_busca *); 
int eh_vazia_queue (fila_busca );
void ins_queue (fila_busca, ARV_BIN_ENC );
ARV_BIN_ENC cons_queue (fila_busca );
void ret_queue (fila_busca );
ARV_BIN_ENC cons_ret_queue (fila_busca );


