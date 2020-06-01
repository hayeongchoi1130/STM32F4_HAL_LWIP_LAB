/*
 * wizInterface.c
 *
 *  Created on: 2020. 5. 31.
 *      Author: eziya76@gmail.com
 */

#include "wizInterface.h"

extern SPI_HandleTypeDef hspi1;
#define WIZ_SPI_HANDLE	&hspi1

void WIZ_SPI_Select(void)
{
	HAL_GPIO_WritePin(WIZ_SPI1_CS_GPIO_Port, WIZ_SPI1_CS_Pin, GPIO_PIN_RESET);
}

void WIZ_SPI_Deselect(void)
{
	HAL_GPIO_WritePin(WIZ_SPI1_CS_GPIO_Port, WIZ_SPI1_CS_Pin, GPIO_PIN_SET);
}

void WIZ_SPI_TxByte(uint8_t byte)
{
	HAL_SPI_Transmit(WIZ_SPI_HANDLE, &byte, 1, HAL_MAX_DELAY);
}

uint8_t WIZ_SPI_RxByte(void)
{
	uint8_t ret;
	HAL_SPI_Receive(WIZ_SPI_HANDLE, &ret, 1, HAL_MAX_DELAY);
	return ret;
}