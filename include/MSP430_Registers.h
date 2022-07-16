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
extern "C"
{
#endif

#define REG_16BITS(address) *(uint16*)address ///< De-reference for 16bits register
#define REG_8BITS(address)  *(uint8*)address  ///< De-refenrece for 8bits register

/************************************************************
 * DIGITAL I/O Port1/2 Pull up / Pull down Resistors
 ************************************************************/
#define P1IN   (uint8)0x0020u ///< Port 1 Input
#define P1OUT  (uint8)0x0021u ///< Port 1 Output
#define P1DIR  (uint8)0x0022u ///< Port 1 Direction
#define P1IFG  (uint8)0x0023u ///< Port 1 Interrupt Flag
#define P1IES  (uint8)0x0024u ///< Port 1 Interrupt Edge Select
#define P1IE   (uint8)0x0025u ///< Port 1 Interrupt Enable
#define P1SEL  (uint8)0x0026u ///< Port 1 Port Select
#define P1SEL2 (uint8)0x0041u ///< Port 1 Port Select2
#define P1REN  (uint8)0x0027u ///< Port 1 Resistor Enable
#define P2IN   (uint8)0x0028u ///< Port 2 Input
#define P2OUT  (uint8)0x0029u ///< Port 2 Output
#define P2DIR  (uint8)0x002Au ///< Port 2 Direction
#define P2IFG  (uint8)0x002Bu ///< Port 2 Interrupt Flag
#define P2IES  (uint8)0x002Cu ///< Port 2 Interrupt Edge Select
#define P2IE   (uint8)0x002Du ///< Port 2 Interrupt Enable
#define P2SEL  (uint8)0x002Eu ///< Port 2 Port Select
#define P2SEL2 (uint8)0x0042u ///< Port 2 Port Select2
#define P2REN  (uint8)0x002Fu ///< Port 2 Resistor Enable

/************************************************************
 * WATCHDOG TIMER
 ************************************************************/
#define WDTCTL (uint16)0x0120u ///< Watchdog Timer

#ifdef __cplusplus
}
#endif

#endif