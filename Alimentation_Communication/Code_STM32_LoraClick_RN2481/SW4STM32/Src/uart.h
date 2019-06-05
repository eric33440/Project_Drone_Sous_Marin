/*
 * uart.h
 *
 *  Created on: 1 avr. 2019
 *      Author: Ricod
 */

#ifndef UART_H_
#define UART_H_

#include <stm32f4xx_hal.h>
#include <stdlib.h>


#define init "mac pause"
#define size_init 12


#define tx_timout 100
#define rx_timout 1000

UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;


static uint8_t send[10] = "radio tx ";
static uint8_t send1[12] = "mac pause";
static uint8_t receive[15] = "radio rx 100";
static uint8_t after[13] = "mac resume\r\n";

uint8_t bufferdata[20];
uint8_t bufferdata1[20];
uint8_t bufferdata2[40];
uint8_t test[20];

void envoie_function(void);
void global_envoie(void);
void global_reception(void);
void init_lora(uint8_t);
void preenvoie(void);
void postenvoie(void);
void envoie_lora(uint8_t delay, int nbre_caractere ,uint8_t carac_envoie[nbre_caractere+1]);
void reception_lora(uint8_t);
void string(void);


#endif /* UART_H_ */
