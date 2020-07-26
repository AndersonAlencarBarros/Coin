#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Coin_Library.h"

/*
			Projeto : Criptomoeda Coin
Autores: Anderson de Alencar e Guilherme Freire

*/

int main(){
	int i = 1, opcao;
	LISTA_ENC l;
	FILA_ENC f;
	ARV_BIN_ENC t = NULL;

	cria_lista_wallet(&l);
	cria_fila_mineracao(&f);

	printf("\n\t\tCoin\t\t\n\n");
	puts(" 1) Criar uma Carteira");
    puts(" 2) Listar Chaves Publicas");
	puts(" 3) Enviar Coins");
	puts(" 4) Minerar Blocos");
	puts(" 5) Mostrar Blocos da Arvore ");

	while(1){
    scanf(" %d", &opcao);
    switch(opcao){
    case 1: criar_carteira(&l,(tam_lista(l) + 1));
			break;
    case 2: imprimir_publicKeys(l);
    		break;
    case 3: transacao(l,f);
        	break;
    case 4: minerar(f,&t);
            break;
    case 5: percursoEmLargura(t);
			break;;
		}
	}	
}


