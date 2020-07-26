#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Coin_Library.h"


/* Funcao para criar a chave pública e privada e a assinatura do bloco.
   O objetivo é ser apenas semelhante a um hash criptomoeda
*/

void generate_hash(char *hash){
    int i;
    char src[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //abcdefghijlkmnopqrstuvwxyz

	for(i=0;i<max-1;i++){
        hash[i] = src[(rand()%(strlen(src)))];
    }
    hash[max-1] = '\0';
}

/* Funcao para receber a hora */

void get_time(char * time_str){
	char * str;
	
    time_t mytime = time(NULL);
    str = ctime(&mytime);
    str[strlen(str)-1] = '\0';
	strcpy(time_str,str);
}

/* Cria apenas um atraso na mineração do bloco */

void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

/* Recebe as Strings relativas a hora (criadas por get_time()) 
e analisa a ordem apenas pela hora que o bloco foi minerado */

int ordem_cronologica(char *string1, char *string2 ){	// classificar pelos segundos

	char dia1[3], mes1[3], dia2[3], mes2[3];
	int data1,horas1,minutos1,segundos1,ano1;
	int data2,horas2,minutos2,segundos2,ano2;
		
	sscanf( string1, "%s %s %d %d:%d:%d %d", dia1, mes1, &data1, &horas1, &minutos1, &segundos1, &ano1);
	sscanf( string2, "%s %s %d %d:%d:%d %d", dia2, mes2, &data2, &horas2, &minutos2, &segundos2, &ano2);
	
	if(horas1 != horas2)
		if(horas1 < horas2)
			return 1;
		else if(minutos1 != minutos2)
				if(minutos1 < minutos2)
					return 1;
				else if(segundos1 != segundos2)
						if(segundos1 < segundos2)
						return 1;

	return 0;
			
}

