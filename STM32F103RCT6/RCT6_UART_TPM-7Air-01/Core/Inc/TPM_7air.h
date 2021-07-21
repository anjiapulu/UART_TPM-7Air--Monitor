#ifndef __TMP_7air_H__
#define __TMP_7air_H__
#include "main.h"
/*------------------------------------------------------------------------------
 *  Struct
 *-----------------------------------------------------------------------------*/
typedef struct{
	unsigned int CO2_DATA;
	unsigned int CH20_DATA;
	unsigned int TVOC_DATA;
	unsigned int PM25_DATA;
	unsigned int PM10_DATA;
	unsigned char Temperature0_DATA;
	unsigned int Temperature1_DATA;
	unsigned char Humidity0_DATA;
	unsigned int Humidity1_DATA;
	uint8_t Rx_buff[17];
}
 UART_TMP_7AIR_T;
extern UART_TMP_7AIR_T uart_tmp_7air;       	

void tpm_receive_count();
#endif