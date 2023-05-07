/*******************************************************************************
* File Name: EE_CLK.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_EE_CLK_H) /* Pins EE_CLK_H */
#define CY_PINS_EE_CLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "EE_CLK_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} EE_CLK_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   EE_CLK_Read(void);
void    EE_CLK_Write(uint8 value);
uint8   EE_CLK_ReadDataReg(void);
#if defined(EE_CLK__PC) || (CY_PSOC4_4200L) 
    void    EE_CLK_SetDriveMode(uint8 mode);
#endif
void    EE_CLK_SetInterruptMode(uint16 position, uint16 mode);
uint8   EE_CLK_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void EE_CLK_Sleep(void); 
void EE_CLK_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(EE_CLK__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define EE_CLK_DRIVE_MODE_BITS        (3)
    #define EE_CLK_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - EE_CLK_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the EE_CLK_SetDriveMode() function.
         *  @{
         */
        #define EE_CLK_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define EE_CLK_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define EE_CLK_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define EE_CLK_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define EE_CLK_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define EE_CLK_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define EE_CLK_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define EE_CLK_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define EE_CLK_MASK               EE_CLK__MASK
#define EE_CLK_SHIFT              EE_CLK__SHIFT
#define EE_CLK_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in EE_CLK_SetInterruptMode() function.
     *  @{
     */
        #define EE_CLK_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define EE_CLK_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define EE_CLK_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define EE_CLK_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(EE_CLK__SIO)
    #define EE_CLK_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(EE_CLK__PC) && (CY_PSOC4_4200L)
    #define EE_CLK_USBIO_ENABLE               ((uint32)0x80000000u)
    #define EE_CLK_USBIO_DISABLE              ((uint32)(~EE_CLK_USBIO_ENABLE))
    #define EE_CLK_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define EE_CLK_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define EE_CLK_USBIO_ENTER_SLEEP          ((uint32)((1u << EE_CLK_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << EE_CLK_USBIO_SUSPEND_DEL_SHIFT)))
    #define EE_CLK_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << EE_CLK_USBIO_SUSPEND_SHIFT)))
    #define EE_CLK_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << EE_CLK_USBIO_SUSPEND_DEL_SHIFT)))
    #define EE_CLK_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(EE_CLK__PC)
    /* Port Configuration */
    #define EE_CLK_PC                 (* (reg32 *) EE_CLK__PC)
#endif
/* Pin State */
#define EE_CLK_PS                     (* (reg32 *) EE_CLK__PS)
/* Data Register */
#define EE_CLK_DR                     (* (reg32 *) EE_CLK__DR)
/* Input Buffer Disable Override */
#define EE_CLK_INP_DIS                (* (reg32 *) EE_CLK__PC2)

/* Interrupt configuration Registers */
#define EE_CLK_INTCFG                 (* (reg32 *) EE_CLK__INTCFG)
#define EE_CLK_INTSTAT                (* (reg32 *) EE_CLK__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define EE_CLK_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(EE_CLK__SIO)
    #define EE_CLK_SIO_REG            (* (reg32 *) EE_CLK__SIO)
#endif /* (EE_CLK__SIO_CFG) */

/* USBIO registers */
#if !defined(EE_CLK__PC) && (CY_PSOC4_4200L)
    #define EE_CLK_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define EE_CLK_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define EE_CLK_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define EE_CLK_DRIVE_MODE_SHIFT       (0x00u)
#define EE_CLK_DRIVE_MODE_MASK        (0x07u << EE_CLK_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins EE_CLK_H */


/* [] END OF FILE */
