/*******************************************************************************
* File Name: SPIM_EE_PM.c
* Version 2.50
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

#include "SPIM_EE_PVT.h"

static SPIM_EE_BACKUP_STRUCT SPIM_EE_backup =
{
    SPIM_EE_DISABLED,
    SPIM_EE_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIM_EE_SaveConfig
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
void SPIM_EE_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_EE_RestoreConfig
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
void SPIM_EE_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_EE_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIM_EE_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_EE_Sleep(void) 
{
    /* Save components enable state */
    SPIM_EE_backup.enableState = ((uint8) SPIM_EE_IS_ENABLED);

    SPIM_EE_Stop();
}


/*******************************************************************************
* Function Name: SPIM_EE_Wakeup
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
*  SPIM_EE_backup - used when non-retention registers are restored.
*  SPIM_EE_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_EE_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_EE_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_EE_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_EE_Wakeup(void) 
{
    #if(SPIM_EE_RX_SOFTWARE_BUF_ENABLED)
        SPIM_EE_rxBufferFull  = 0u;
        SPIM_EE_rxBufferRead  = 0u;
        SPIM_EE_rxBufferWrite = 0u;
    #endif /* (SPIM_EE_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_EE_TX_SOFTWARE_BUF_ENABLED)
        SPIM_EE_txBufferFull  = 0u;
        SPIM_EE_txBufferRead  = 0u;
        SPIM_EE_txBufferWrite = 0u;
    #endif /* (SPIM_EE_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_EE_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_EE_backup.enableState)
    {
        SPIM_EE_Enable();
    }
}


/* [] END OF FILE */
