/****************************************************************************
 * \file    main.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   main
 ****************************************************************************/
#include <in430.h>

#define REG_16BITS(address) *(signed short int*)address ///< De-reference for 16bits register
#define REG_8BITS(address) *(unsigned char*) address ///< De-refenrece for 8bits register

#define WDTCTL REG_16BITS(0x0120) 
// Registers for port 1
#define P1IN              REG_8BITS(0x20) ///< Port1 Input
#define P1OUT             REG_8BITS(0x21) ///< Port1 Output 
#define P1DIR             REG_8BITS(0x22) ///< Port1 Direction

// Registers for port 2
#define P2IN              REG_8BITS(0x28) ///< Port2 Input
#define P2OUT             REG_8BITS(0x29) ///< Port2 Output 
#define P2DIR             REG_8BITS(0x2A) ///< Port2 Direction

// #define __bic_SR_register(_b) __bic_status_register(_b)

// #define BIC_SR(x)           __bic_SR_register(x) ///< clear Bit in Status Register
// #define BIS_SR(x)           _bis_SR_register(x) ///< set Bit in Status Register

#define GIE                 (0x08) ///< General interrupt enable


#define WDTPW (0x5A00)
#define WDTHOLD (0x0080)

/**
 *
 * main function where all is called
 *  \startuml
 *    Sender->Receiver  : Commands()
 *    Sender<--Receiver : Ack()
 *  \enduml
 *
 */

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;

    __bic_SR_register(GIE);
    P2DIR = 0x1;
    P2OUT = 0x1;
    return 0;
}