/*
 * uart.c
 *
 *  Created on: 1 avr. 2019
 *      Author: Ricod
 */

#include "init_uart.h"
#include "uart.h"
#include <stm32f4xx_hal.h>
#include <stdlib.h>
#include <stdio.h>


//Toute commande doit finir par deux chose \r\n, appeler CRLF car le module
//pour comprendre que l'envoie de la commande est terminer

void fin_envoie_huart3(void)
{
	HAL_UART_Transmit(&huart3,(uint8_t*)"\r",1,10);
	HAL_UART_Transmit(&huart3,(uint8_t*)"\n",1,10);
}
void fin_envoie_huart2(void)
{
	HAL_UART_Transmit(&huart2,(uint8_t*)"\r",1,10);
	HAL_UART_Transmit(&huart2,(uint8_t*)"\n",1,10);
}

void end_send(void)
{
	fin_envoie_huart2();
	fin_envoie_huart3();
}

// fonction permettant de vider les buffer de reception pour éviter les
// problemes de commentaire en trop ou restant de la derniere reponse

void string(void)
{
	for(int i=0 ; i<sizeof(bufferdata) ; i++)
	{
		bufferdata[i]=0;
		bufferdata1[i]=0;
		bufferdata2[i]=0;
	}
}
void init_lora(uint8_t delay)
{
	string();
	// permet la reinitialisation du module

	HAL_UART_Transmit(&huart3,"sys reset\r\n",11,tx_timout);
	HAL_UART_Transmit(&huart2,"sys reset\r\n",11,tx_timout);
	while(bufferdata2[0]=='\0')
	{
		HAL_UART_Receive(&huart3,bufferdata2,30,rx_timout);
		HAL_UART_Transmit(&huart2,bufferdata2,30,tx_timout);
	}
	//Permet de savoir la fonctionnalité de la pile, si tout va bien censé répondre 4294967295
	//commande permettant la reinitialisation du module
	/*for(int i=0 ; i<9; i++)
	{
		HAL_UART_Transmit(&huart3,&send1[i],1,tx_timout);
		HAL_UART_Transmit(&huart2,&send1[i],1,tx_timout);
	}
	end_send();
	while(bufferdata[0]=='\0')
	{
		HAL_UART_Receive(&huart3,bufferdata,10,rx_timout);
		HAL_UART_Transmit(&huart2,(uint8_t*)bufferdata,10,tx_timout);
	}*/

}

void preenvoie(void)
{
	string();
	//end_send();
	//envoie de la commande mac pause
	for(int i=0 ; i<9; i++)
	{
		HAL_UART_Transmit(&huart3,&send1[i],1,tx_timout);
		HAL_UART_Transmit(&huart2,&send1[i],1,tx_timout);
	}
	end_send();
	//attente de la réponse du module
	//HAL_UART_Receive_IT(&huart3,bufferdata1,12);
	while(bufferdata[2]=='\0')
	{
		HAL_UART_Receive(&huart3,bufferdata,12,rx_timout);

	}HAL_UART_Transmit(&huart2,(uint8_t*)bufferdata,12,tx_timout);
	// Apres avoir effectue la commande init "mac pause" on doit recevoir :4294967245
}
void postenvoie(void)
{
	string();
	//envoie de la commande mac resume
	for (int i=0 ; i < 13 ; i++)
	{
		HAL_UART_Transmit(&huart3,&after[i],1,tx_timout);
		HAL_UART_Transmit(&huart2,&after[i],1,tx_timout);
	}
	//HAL_UART_Receive_IT(&huart3,bufferdata1,4);
	while(bufferdata2[2]=='\0')
	{
		HAL_UART_Receive(&huart3,bufferdata2,4,rx_timout);
		HAL_UART_Transmit(&huart2,bufferdata2,4,tx_timout);
	}
}

void envoie_lora(uint8_t delay, int nbre_caractere ,uint8_t carac_envoie[nbre_caractere+1])
{
	init_lora(1);
	preenvoie();
	string();

	for(int i=0 ; i< 11/*sizeof((send))*/;i++)
	{
		HAL_UART_Transmit(&huart3,&send[i],1,tx_timout);
		HAL_UART_Transmit(&huart2,&send[i],1,tx_timout);
	}
	for(int i = 0; i <  nbre_caractere;i++ )
	{
		HAL_UART_Transmit(&huart3,&carac_envoie[i],1,tx_timout);
		HAL_UART_Transmit(&huart2,&carac_envoie[i],1,tx_timout);
	}
	end_send();
	/*HAL_UART_Receive_IT(&huart3,bufferdata1,4);
	HAL_UART_Receive_IT(&huart3,bufferdata1,13);*/
	while(bufferdata2[7]=='\0')
	{
		HAL_UART_Receive(&huart3,bufferdata2,19,rx_timout);
	}
	HAL_UART_Transmit(&huart2,bufferdata2,19,tx_timout);
	/*while(bufferdata2[0]=='\0')
	{

	}*/
	//HAL_UART_Receive(&huart3,bufferdata2,11,rx_timout);
	string();
	postenvoie();
}

void reception_lora(uint8_t delais)
{
	init_lora(1);
	preenvoie();//envoie de la commande de preenvoie
	string();// vide les tableau avant et après utilisation pour éviter les décalages ou problèmes de changement de symbole
	uint8_t CRLF[2];
	for(int i = 0; i < 11/* sizeof(carac_envoie)*/;i++ )
	{
		HAL_UART_Transmit(&huart3,&receive[i],1,tx_timout);
		HAL_UART_Transmit(&huart2,&receive[i],1,tx_timout);
	}
	end_send();

	while(bufferdata1[7]=='\0')
	{
		HAL_UART_Receive(&huart3,bufferdata1,18,rx_timout);
	}
	HAL_UART_Transmit(&huart2,bufferdata1,18,tx_timout);

	char *result;//tableau fait la même taille que le buffer de réception + 1 pour le \0
	*result = NULL;
	result = strrchr( bufferdata1, ' ');// on cherche a séparé la donnée du reste de la commande reçue
	strcpy(datarx,result);//copie du résultat dans la chaîne qui contiendra le résultat final
	for (int var = 0; var < sizeof(datarx); ++var)
	{
		if(datarx[var]=='\r')//s le résultat est \r alors on le remplaçera par rien
			datarx[var]='\0';
		if(datarx[var]=='\n')//s le résultat est \n alors on le remplaçera par rien
			datarx[var]='\0';
	}
	//la donnée reçue est accessible sur la chaîne de caractères datarx
	string();
	postenvoie();
}

void test_separate_string(void)
{

	uint8_t data[20]="radio rx aa\r\n";
	uint8_t datarx[10];
	char *result;//tableau fait la même taille que le buffer de réception + 1 pour le \0
	*result = NULL;
	result = strrchr( data, ' ');// on cherche a séparé la donnée du reste de la commande reçue
	strcpy(datarx,result);//copie du résultat dans la chaîne qui contiendra le résultat final
	for (int var = 0; var < sizeof(datarx); ++var)
	{
		if(datarx[var]=='\r')//s le résultat est \r alors on le remplaçera par rien
			datarx[var]='\0';
		if(datarx[var]=='\n')//s le résultat est \n alors on le remplaçera par rien
			datarx[var]='\0';

	}

	//fonction separe la chaîne
	// data retournera la donnée reçue par le module est envoyer par la télécommande
	HAL_UART_Transmit(&huart2,result,20,tx_timout);
	HAL_UART_Transmit(&huart2,"\r\n",2,tx_timout);

}




/*void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart==&huart3)
	{
		HAL_UART_Transmit(&huart2,bufferdata1,sizeof(bufferdata1),tx_timout);
	}
}*/

/*
 * lora.c
 *
 *  Created on: 2 avr. 2019
 *      Author: Ricod
 */


