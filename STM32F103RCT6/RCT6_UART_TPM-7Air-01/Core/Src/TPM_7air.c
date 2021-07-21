#include "TPM_7air.h"
#include <stdio.h>
#include "usart.h"
#include "oled.h"
extern char Temper[16];
int i;
UART_TMP_7AIR_T uart_tmp_7air =
{
	.CO2_DATA = 0,
	.CH20_DATA = 0,
	.TVOC_DATA = 0,
	.PM25_DATA = 0,
	.PM10_DATA = 0,
	.Temperature0_DATA = 0,
	.Temperature1_DATA = 0,
	.Humidity0_DATA = 0,
	.Humidity1_DATA = 0,
	.Rx_buff = 0
};
void tpm_receive_count()
{
	if (uart_tmp_7air.Rx_buff[0] != 0x3C && uart_tmp_7air.Rx_buff[1] != 0x02)
	{
		HAL_UART_Receive(&huart4, uart_tmp_7air.Rx_buff, sizeof(uart_tmp_7air.Rx_buff), 1000);
	}
	else
	{
	  uart_tmp_7air.Rx_buff[0] = 0x00;
		uart_tmp_7air.Rx_buff[1] = 0x00;
		uart_tmp_7air.CO2_DATA = uart_tmp_7air.Rx_buff[2] * 256 + uart_tmp_7air.Rx_buff[3];
		uart_tmp_7air.CH20_DATA = uart_tmp_7air.Rx_buff[4] * 256 + uart_tmp_7air.Rx_buff[5];
		uart_tmp_7air.TVOC_DATA = uart_tmp_7air.Rx_buff[6] * 256 + uart_tmp_7air.Rx_buff[7];
		uart_tmp_7air.PM25_DATA = uart_tmp_7air.Rx_buff[8] * 256 + uart_tmp_7air.Rx_buff[9];
		uart_tmp_7air.PM10_DATA = uart_tmp_7air.Rx_buff[10] * 256 + uart_tmp_7air.Rx_buff[11];
		uart_tmp_7air.Temperature0_DATA = uart_tmp_7air.Rx_buff[12];
		uart_tmp_7air.Temperature1_DATA = uart_tmp_7air.Rx_buff[13];
		uart_tmp_7air.Humidity0_DATA = uart_tmp_7air.Rx_buff[14];
		uart_tmp_7air.Humidity1_DATA = uart_tmp_7air.Rx_buff[15];
	}


}
