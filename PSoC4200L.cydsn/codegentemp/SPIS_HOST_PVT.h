/*******************************************************************************
* File Name: .h
* Version 2.70
*
* Description:
*  This private header file contains internal definitions for the SPIS
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIS_PVT_SPIS_HOST_H)
#define CY_SPIS_PVT_SPIS_HOST_H

#include "SPIS_HOST.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/
extern volatile uint8 SPIS_HOST_swStatusTx;
extern volatile uint8 SPIS_HOST_swStatusRx;

#if (SPIS_HOST_RX_SOFTWARE_BUF_ENABLED)

    extern volatile uint8 SPIS_HOST_rxBuffer[SPIS_HOST_RX_BUFFER_SIZE];
    extern volatile uint8 SPIS_HOST_rxBufferRead;
    extern volatile uint8 SPIS_HOST_rxBufferWrite;
    extern volatile uint8 SPIS_HOST_rxBufferFull;

#endif /* SPIS_HOST_RX_SOFTWARE_BUF_ENABLED */

#if (SPIS_HOST_TX_SOFTWARE_BUF_ENABLED)

    extern volatile uint8 SPIS_HOST_txBuffer[SPIS_HOST_TX_BUFFER_SIZE];
    extern volatile uint8 SPIS_HOST_txBufferRead;
    extern volatile uint8 SPIS_HOST_txBufferWrite;
    extern volatile uint8 SPIS_HOST_txBufferFull;

#endif /* SPIS_HOST_TX_SOFTWARE_BUF_ENABLED */

#endif /* CY_SPIS_PVT_SPIS_HOST_H */


/* [] END OF FILE */
