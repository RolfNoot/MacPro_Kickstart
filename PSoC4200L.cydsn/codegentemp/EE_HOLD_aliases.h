/*******************************************************************************
* File Name: EE_HOLD.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_EE_HOLD_ALIASES_H) /* Pins EE_HOLD_ALIASES_H */
#define CY_PINS_EE_HOLD_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define EE_HOLD_0			(EE_HOLD__0__PC)
#define EE_HOLD_0_PS		(EE_HOLD__0__PS)
#define EE_HOLD_0_PC		(EE_HOLD__0__PC)
#define EE_HOLD_0_DR		(EE_HOLD__0__DR)
#define EE_HOLD_0_SHIFT	(EE_HOLD__0__SHIFT)
#define EE_HOLD_0_INTR	((uint16)((uint16)0x0003u << (EE_HOLD__0__SHIFT*2u)))

#define EE_HOLD_INTR_ALL	 ((uint16)(EE_HOLD_0_INTR))


#endif /* End Pins EE_HOLD_ALIASES_H */


/* [] END OF FILE */
