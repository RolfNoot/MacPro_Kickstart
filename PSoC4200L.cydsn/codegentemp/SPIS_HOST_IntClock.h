/*******************************************************************************
* File Name: SPIS_HOST_IntClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_SPIS_HOST_IntClock_H)
#define CY_CLOCK_SPIS_HOST_IntClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void SPIS_HOST_IntClock_StartEx(uint32 alignClkDiv);
#define SPIS_HOST_IntClock_Start() \
    SPIS_HOST_IntClock_StartEx(SPIS_HOST_IntClock__PA_DIV_ID)

#else

void SPIS_HOST_IntClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void SPIS_HOST_IntClock_Stop(void);

void SPIS_HOST_IntClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 SPIS_HOST_IntClock_GetDividerRegister(void);
uint8  SPIS_HOST_IntClock_GetFractionalDividerRegister(void);

#define SPIS_HOST_IntClock_Enable()                         SPIS_HOST_IntClock_Start()
#define SPIS_HOST_IntClock_Disable()                        SPIS_HOST_IntClock_Stop()
#define SPIS_HOST_IntClock_SetDividerRegister(clkDivider, reset)  \
    SPIS_HOST_IntClock_SetFractionalDividerRegister((clkDivider), 0u)
#define SPIS_HOST_IntClock_SetDivider(clkDivider)           SPIS_HOST_IntClock_SetDividerRegister((clkDivider), 1u)
#define SPIS_HOST_IntClock_SetDividerValue(clkDivider)      SPIS_HOST_IntClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define SPIS_HOST_IntClock_DIV_ID     SPIS_HOST_IntClock__DIV_ID

#define SPIS_HOST_IntClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define SPIS_HOST_IntClock_CTRL_REG   (*(reg32 *)SPIS_HOST_IntClock__CTRL_REGISTER)
#define SPIS_HOST_IntClock_DIV_REG    (*(reg32 *)SPIS_HOST_IntClock__DIV_REGISTER)

#define SPIS_HOST_IntClock_CMD_DIV_SHIFT          (0u)
#define SPIS_HOST_IntClock_CMD_PA_DIV_SHIFT       (8u)
#define SPIS_HOST_IntClock_CMD_DISABLE_SHIFT      (30u)
#define SPIS_HOST_IntClock_CMD_ENABLE_SHIFT       (31u)

#define SPIS_HOST_IntClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << SPIS_HOST_IntClock_CMD_DISABLE_SHIFT))
#define SPIS_HOST_IntClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << SPIS_HOST_IntClock_CMD_ENABLE_SHIFT))

#define SPIS_HOST_IntClock_DIV_FRAC_MASK  (0x000000F8u)
#define SPIS_HOST_IntClock_DIV_FRAC_SHIFT (3u)
#define SPIS_HOST_IntClock_DIV_INT_MASK   (0xFFFFFF00u)
#define SPIS_HOST_IntClock_DIV_INT_SHIFT  (8u)

#else 

#define SPIS_HOST_IntClock_DIV_REG        (*(reg32 *)SPIS_HOST_IntClock__REGISTER)
#define SPIS_HOST_IntClock_ENABLE_REG     SPIS_HOST_IntClock_DIV_REG
#define SPIS_HOST_IntClock_DIV_FRAC_MASK  SPIS_HOST_IntClock__FRAC_MASK
#define SPIS_HOST_IntClock_DIV_FRAC_SHIFT (16u)
#define SPIS_HOST_IntClock_DIV_INT_MASK   SPIS_HOST_IntClock__DIVIDER_MASK
#define SPIS_HOST_IntClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_SPIS_HOST_IntClock_H) */

/* [] END OF FILE */
