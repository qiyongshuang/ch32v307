/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2022/08/20
* Description        : Main program body.
*********************************************************************************
* Copyright (c) 2025 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/*
 *@Note
  This example simulates a UAC 1.0 Microphone device and transmits the received 
  audio data through UART.

  Microphone Topology (MT)  Unit:
    [Input Terminal ID4]  ->  [Feature Unit ID5]  ->  [Output Terminal ID6 ]
  
  The specific configuration is as follows:
    �� Number of Channels: 2 Channels (Stereo)
    �� Sampling Depth: 16-bit
    �� Sampling Rate: 48000 Hz

  This example can be used in conjunction with the UAC10_Headphone example, the 
  data transmitted from the host to the headset is transmitted via the microphone,
  with the connection as follows:
    
    UAC10_Headphone    UAC10_Microphone
       TX PA2  -----------> RX PA3
*/

#include "ch32v30x_usbfs_device.h"
#include "uac10_microphone.h"
#include "debug.h"

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    SystemCoreClockUpdate( );
    Delay_Init( );
    USART_Printf_Init( 921600 );

    printf( "SystemClk:%d\r\n", SystemCoreClock );
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf( "USBFS UAC 1.0 Microphone\n");

    /* USBFSD device init */
    USBFS_RCC_Init();
    USBFS_Device_Init( ENABLE );

    while(1)
    {
        UAC_UART_Rx_Handle();
    }
}
