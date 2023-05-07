/*******************************************************************************
* File Name: EE_CLK.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "EE_CLK.h"

static EE_CLK_BACKUP_STRUCT  EE_CLK_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: EE_CLK_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet EE_CLK_SUT.c usage_EE_CLK_Sleep_Wakeup
*******************************************************************************/
void EE_CLK_Sleep(void)
{
    #if defined(EE_CLK__PC)
        EE_CLK_backup.pcState = EE_CLK_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            EE_CLK_backup.usbState = EE_CLK_CR1_REG;
            EE_CLK_USB_POWER_REG |= EE_CLK_USBIO_ENTER_SLEEP;
            EE_CLK_CR1_REG &= EE_CLK_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(EE_CLK__SIO)
        EE_CLK_backup.sioState = EE_CLK_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        EE_CLK_SIO_REG &= (uint32)(~EE_CLK_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: EE_CLK_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to EE_CLK_Sleep() for an example usage.
*******************************************************************************/
void EE_CLK_Wakeup(void)
{
    #if defined(EE_CLK__PC)
        EE_CLK_PC = EE_CLK_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            EE_CLK_USB_POWER_REG &= EE_CLK_USBIO_EXIT_SLEEP_PH1;
            EE_CLK_CR1_REG = EE_CLK_backup.usbState;
            EE_CLK_USB_POWER_REG &= EE_CLK_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(EE_CLK__SIO)
        EE_CLK_SIO_REG = EE_CLK_backup.sioState;
    #endif
}


/* [] END OF FILE */
