/*******************************************************************************
* File Name: HOST_WP.c  
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
#include "HOST_WP.h"

static HOST_WP_BACKUP_STRUCT  HOST_WP_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: HOST_WP_Sleep
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
*  \snippet HOST_WP_SUT.c usage_HOST_WP_Sleep_Wakeup
*******************************************************************************/
void HOST_WP_Sleep(void)
{
    #if defined(HOST_WP__PC)
        HOST_WP_backup.pcState = HOST_WP_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            HOST_WP_backup.usbState = HOST_WP_CR1_REG;
            HOST_WP_USB_POWER_REG |= HOST_WP_USBIO_ENTER_SLEEP;
            HOST_WP_CR1_REG &= HOST_WP_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(HOST_WP__SIO)
        HOST_WP_backup.sioState = HOST_WP_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        HOST_WP_SIO_REG &= (uint32)(~HOST_WP_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: HOST_WP_Wakeup
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
*  Refer to HOST_WP_Sleep() for an example usage.
*******************************************************************************/
void HOST_WP_Wakeup(void)
{
    #if defined(HOST_WP__PC)
        HOST_WP_PC = HOST_WP_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            HOST_WP_USB_POWER_REG &= HOST_WP_USBIO_EXIT_SLEEP_PH1;
            HOST_WP_CR1_REG = HOST_WP_backup.usbState;
            HOST_WP_USB_POWER_REG &= HOST_WP_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(HOST_WP__SIO)
        HOST_WP_SIO_REG = HOST_WP_backup.sioState;
    #endif
}


/* [] END OF FILE */
