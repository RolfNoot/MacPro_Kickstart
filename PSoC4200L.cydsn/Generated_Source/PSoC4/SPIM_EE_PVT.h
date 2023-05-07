/*******************************************************************************
* File Name: .h
* Version 2.50
*
* Description:
*  This private header file contains internal definitions for the SPIM
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_PVT_SPIM_EE_H)
#define CY_SPIM_PVT_SPIM_EE_H

#include "SPIM_EE.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 SPIM_EE_swStatusTx;
extern volatile uint8 SPIM_EE_swStatusRx;

#if(SPIM_EE_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_EE_txBuffer[SPIM_EE_TX_BUFFER_SIZE];
    extern volatile uint8 SPIM_EE_txBufferRead;
    extern volatile uint8 SPIM_EE_txBufferWrite;
    extern volatile uint8 SPIM_EE_txBufferFull;
#endif /* (SPIM_EE_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_EE_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_EE_rxBuffer[SPIM_EE_RX_BUFFER_SIZE];
    extern volatile uint8 SPIM_EE_rxBufferRead;
    extern volatile uint8 SPIM_EE_rxBufferWrite;
    extern volatile uint8 SPIM_EE_rxBufferFull;
#endif /* (SPIM_EE_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_SPIM_EE_H */


/* [] END OF FILE */
