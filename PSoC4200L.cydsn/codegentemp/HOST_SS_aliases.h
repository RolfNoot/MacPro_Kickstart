/*******************************************************************************
* File Name: HOST_SS.h  
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

#if !defined(CY_PINS_HOST_SS_ALIASES_H) /* Pins HOST_SS_ALIASES_H */
#define CY_PINS_HOST_SS_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define HOST_SS_0			(HOST_SS__0__PC)
#define HOST_SS_0_PS		(HOST_SS__0__PS)
#define HOST_SS_0_PC		(HOST_SS__0__PC)
#define HOST_SS_0_DR		(HOST_SS__0__DR)
#define HOST_SS_0_SHIFT	(HOST_SS__0__SHIFT)
#define HOST_SS_0_INTR	((uint16)((uint16)0x0003u << (HOST_SS__0__SHIFT*2u)))

#define HOST_SS_INTR_ALL	 ((uint16)(HOST_SS_0_INTR))


#endif /* End Pins HOST_SS_ALIASES_H */


/* [] END OF FILE */
