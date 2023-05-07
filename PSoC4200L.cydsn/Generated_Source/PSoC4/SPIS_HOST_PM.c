/*******************************************************************************
* File Name: SPIS_HOST_PM.c
* Version 2.70
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIS_HOST_PVT.h"

static SPIS_HOST_BACKUP_STRUCT SPIS_HOST_backup = 
{
    SPIS_HOST_DISABLED,
    SPIS_HOST_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIS_HOST_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIS_HOST_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIS_HOST_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIS_HOST_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIS_HOST_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPI Slave Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIS_HOST_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_HOST_Sleep(void) 
{
    /* Save components enable state */
    if ((SPIS_HOST_TX_STATUS_ACTL_REG & SPIS_HOST_INT_ENABLE) != 0u)
    {
        SPIS_HOST_backup.enableState = 1u;
    }
    else /* Components block is disabled */
    {
        SPIS_HOST_backup.enableState = 0u;
    }

    SPIS_HOST_Stop();

}


/*******************************************************************************
* Function Name: SPIS_HOST_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIS_HOST_backup - used when non-retention registers are restored.
*  SPIS_HOST_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIS_HOST_txBufferRead - modified every function call - resets to
*  zero.
*  SPIS_HOST_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIS_HOST_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_HOST_Wakeup(void) 
{
    #if (SPIS_HOST_TX_SOFTWARE_BUF_ENABLED)
        SPIS_HOST_txBufferFull = 0u;
        SPIS_HOST_txBufferRead = 0u;
        SPIS_HOST_txBufferWrite = 0u;
    #endif /* SPIS_HOST_TX_SOFTWARE_BUF_ENABLED */

    #if (SPIS_HOST_RX_SOFTWARE_BUF_ENABLED)
        SPIS_HOST_rxBufferFull = 0u;
        SPIS_HOST_rxBufferRead = 0u;
        SPIS_HOST_rxBufferWrite = 0u;
    #endif /* SPIS_HOST_RX_SOFTWARE_BUF_ENABLED */

    SPIS_HOST_ClearFIFO();

    /* Restore components block enable state */
    if (SPIS_HOST_backup.enableState != 0u)
    {
         /* Components block was enabled */
         SPIS_HOST_Enable();
    } /* Do nothing if components block was disabled */
}


/* [] END OF FILE */
