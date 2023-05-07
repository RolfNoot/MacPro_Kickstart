/*******************************************************************************
* File Name: SPIM_EE_INT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Master
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIM_EE_PVT.h"
#include "cyapicallbacks.h"

/* User code required at start of ISR */
/* `#START SPIM_EE_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPIM_EE_TX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_EE_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIM_EE_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  SPIM_EE_txBuffer[SPIM_EE_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_EE_TX_ISR)
{
    #if(SPIM_EE_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (SPIM_EE_TX_SOFTWARE_BUF_ENABLED) */

    #ifdef SPIM_EE_TX_ISR_ENTRY_CALLBACK
        SPIM_EE_TX_ISR_EntryCallback();
    #endif /* SPIM_EE_TX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START SPIM_EE_TX_ISR_START` */

    /* `#END` */
    
    #if(SPIM_EE_TX_SOFTWARE_BUF_ENABLED)
        /* Check if TX data buffer is not empty and there is space in TX FIFO */
        while(SPIM_EE_txBufferRead != SPIM_EE_txBufferWrite)
        {
            tmpStatus = SPIM_EE_GET_STATUS_TX(SPIM_EE_swStatusTx);
            SPIM_EE_swStatusTx = tmpStatus;

            if(0u != (SPIM_EE_swStatusTx & SPIM_EE_STS_TX_FIFO_NOT_FULL))
            {
                if(0u == SPIM_EE_txBufferFull)
                {
                   SPIM_EE_txBufferRead++;

                    if(SPIM_EE_txBufferRead >= SPIM_EE_TX_BUFFER_SIZE)
                    {
                        SPIM_EE_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPIM_EE_txBufferFull = 0u;
                }

                /* Put data element into the TX FIFO */
                CY_SET_REG8(SPIM_EE_TXDATA_PTR, 
                                             SPIM_EE_txBuffer[SPIM_EE_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        if(SPIM_EE_txBufferRead == SPIM_EE_txBufferWrite)
        {
            /* TX Buffer is EMPTY: disable interrupt on TX NOT FULL */
            SPIM_EE_TX_STATUS_MASK_REG &= ((uint8) ~SPIM_EE_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* (SPIM_EE_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_EE_TX_ISR_END` */

    /* `#END` */
    
    #ifdef SPIM_EE_TX_ISR_EXIT_CALLBACK
        SPIM_EE_TX_ISR_ExitCallback();
    #endif /* SPIM_EE_TX_ISR_EXIT_CALLBACK */
}


/*******************************************************************************
* Function Name: SPIM_EE_RX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_EE_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPIM_EE_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPIM_EE_rxBuffer[SPIM_EE_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_EE_RX_ISR)
{
    #if(SPIM_EE_RX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint8 rxData;
    #endif /* (SPIM_EE_RX_SOFTWARE_BUF_ENABLED) */

    #ifdef SPIM_EE_RX_ISR_ENTRY_CALLBACK
        SPIM_EE_RX_ISR_EntryCallback();
    #endif /* SPIM_EE_RX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START SPIM_EE_RX_ISR_START` */

    /* `#END` */
    
    #if(SPIM_EE_RX_SOFTWARE_BUF_ENABLED)

        tmpStatus = SPIM_EE_GET_STATUS_RX(SPIM_EE_swStatusRx);
        SPIM_EE_swStatusRx = tmpStatus;

        /* Check if RX data FIFO has some data to be moved into the RX Buffer */
        while(0u != (SPIM_EE_swStatusRx & SPIM_EE_STS_RX_FIFO_NOT_EMPTY))
        {
            rxData = CY_GET_REG8(SPIM_EE_RXDATA_PTR);

            /* Set next pointer. */
            SPIM_EE_rxBufferWrite++;
            if(SPIM_EE_rxBufferWrite >= SPIM_EE_RX_BUFFER_SIZE)
            {
                SPIM_EE_rxBufferWrite = 0u;
            }

            if(SPIM_EE_rxBufferWrite == SPIM_EE_rxBufferRead)
            {
                SPIM_EE_rxBufferRead++;
                if(SPIM_EE_rxBufferRead >= SPIM_EE_RX_BUFFER_SIZE)
                {
                    SPIM_EE_rxBufferRead = 0u;
                }

                SPIM_EE_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            SPIM_EE_rxBuffer[SPIM_EE_rxBufferWrite] = rxData;

            tmpStatus = SPIM_EE_GET_STATUS_RX(SPIM_EE_swStatusRx);
            SPIM_EE_swStatusRx = tmpStatus;
        }

    #endif /* (SPIM_EE_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_EE_RX_ISR_END` */

    /* `#END` */
    
    #ifdef SPIM_EE_RX_ISR_EXIT_CALLBACK
        SPIM_EE_RX_ISR_ExitCallback();
    #endif /* SPIM_EE_RX_ISR_EXIT_CALLBACK */
}

/* [] END OF FILE */
