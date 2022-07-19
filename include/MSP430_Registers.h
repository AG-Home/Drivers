/**********************************************************************************************************************
 * \file MSP430_Registers.h
 *
 * \author  Marco Aguilar
 *
 * \date Jul-16-2022
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the ADC driver
 *********************************************************************************************************************/

#include <Std_Types.h>

#ifndef MSP430_REGISTERS_H
#define MSP430_REGISTERS_H

#ifdef __cplusplus
extern "C" {
#endif

#define REG_16BITS(address) *(uint16*)address ///< De-reference for 16bits register
#define REG_8BITS(address)  *(uint8*)address  ///< De-refenrece for 8bits register

/************************************************************
 * DIGITAL I/O Port1/2 Pull up / Pull down Resistors
 ************************************************************/
#define P1IN_ADDR   (uint16)0x0020u ///< Port 1 Input Address
#define P1OUT_ADDR  (uint16)0x0021u ///< Port 1 Output Address
#define P1DIR_ADDR  (uint16)0x0022u ///< Port 1 Direction Address
#define P1IFG_ADDR  (uint16)0x0023u ///< Port 1 Interrupt Flag Address
#define P1IES_ADDR  (uint16)0x0024u ///< Port 1 Interrupt Edge Select Address
#define P1IE_ADDR   (uint16)0x0025u ///< Port 1 Interrupt Enable Address
#define P1SEL_ADDR  (uint16)0x0026u ///< Port 1 Port Select Address
#define P1SEL2_ADDR (uint16)0x0041u ///< Port 1 Port Select2 Address
#define P1REN_ADDR  (uint16)0x0027u ///< Port 1 Resistor Enable Address
#define P2IN_ADDR   (uint16)0x0028u ///< Port 2 Input Address
#define P2OUT_ADDR  (uint16)0x0029u ///< Port 2 Output Address
#define P2DIR_ADDR  (uint16)0x002Au ///< Port 2 Direction Address
#define P2IFG_ADDR  (uint16)0x002Bu ///< Port 2 Interrupt Flag Address
#define P2IES_ADDR  (uint16)0x002Cu ///< Port 2 Interrupt Edge Select Address
#define P2IE_ADDR   (uint16)0x002Du ///< Port 2 Interrupt Enable Address
#define P2SEL_ADDR  (uint16)0x002Eu ///< Port 2 Port Select Address
#define P2SEL2_ADDR (uint16)0x0042u ///< Port 2 Port Select2 Address
#define P2REN_ADDR  (uint16)0x002Fu ///< Port 2 Resistor Enable Address

#define P1IN        REG_8BITS(P1IN_ADDR)   ///< Port 1 Input
#define P1OUT       REG_8BITS(P1OUT_ADDR)  ///< Port 1 Output
#define P1DIR       REG_8BITS(P1DIR_ADDR)  ///< Port 1 Direction
#define P1IFG       REG_8BITS(P1IFG_ADDR)  ///< Port 1 Interrupt Flag
#define P1IES       REG_8BITS(P1IES_ADDR)  ///< Port 1 Interrupt Edge Select
#define P1IE        REG_8BITS(P1IE_ADDR)   ///< Port 1 Interrupt Enable
#define P1SEL       REG_8BITS(P1SEL_ADDR)  ///< Port 1 Port Select
#define P1SEL2      REG_8BITS(P1SEL2_ADDR) ///< Port 1 Port Select2
#define P1REN       REG_8BITS(P1REN_ADDR)  ///< Port 1 Resistor Enable
#define P2IN        REG_8BITS(P2IN_ADDR)   ///< Port 2 Input
#define P2OUT       REG_8BITS(P2OUT_ADDR)  ///< Port 2 Output
#define P2DIR       REG_8BITS(P2DIR_ADDR)  ///< Port 2 Direction
#define P2IFG       REG_8BITS(P2IFG_ADDR)  ///< Port 2 Interrupt Flag
#define P2IES       REG_8BITS(P2IES_ADDR)  ///< Port 2 Interrupt Edge Select
#define P2IE        REG_8BITS(P2IE_ADDR)   ///< Port 2 Interrupt Enable
#define P2SEL       REG_8BITS(P2SEL_ADDR)  ///< Port 2 Port Select
#define P2SEL2      REG_8BITS(P2SEL2_ADDR) ///< Port 2 Port Select2
#define P2REN       REG_8BITS(P2REN_ADDR)  ///< Port 2 Resistor Enable

/************************************************************
 * WATCHDOG TIMER
 ************************************************************/
#define WDTCTL REG_16BITS(0x0120u) ///< Watchdog Timer

#ifdef __cplusplus
}
#endif

#endif
