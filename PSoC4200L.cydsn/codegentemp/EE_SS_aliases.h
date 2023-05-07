/*******************************************************************************
* File Name: EE_SS.h  
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

#if !defined(CY_PINS_EE_SS_ALIASES_H) /* Pins EE_SS_ALIASES_H */
#define CY_PINS_EE_SS_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define EE_SS_0			(EE_SS__0__PC)
#define EE_SS_0_PS		(EE_SS__0__PS)
#define EE_SS_0_PC		(EE_SS__0__PC)
#define EE_SS_0_DR		(EE_SS__0__DR)
#define EE_SS_0_SHIFT	(EE_SS__0__SHIFT)
#define EE_SS_0_INTR	((uint16)((uint16)0x0003u << (EE_SS__0__SHIFT*2u)))

#define EE_SS_INTR_ALL	 ((uint16)(EE_SS_0_INTR))


#endif /* End Pins EE_SS_ALIASES_H */


/* [] END OF FILE */
