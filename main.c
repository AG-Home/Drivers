/****************************************************************************
 * \file    main.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   main
 ****************************************************************************/
#include <Gpio_Driver.h>

#define WDTPW   (0x5A00)
#define WDTHOLD (0x0080)

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;

  P2DIR = 0x4;
  P2OUT = 0x4;
  return 0;
}