/****************************************************************************
 * \file    main.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   main
 ****************************************************************************/
#include <Gpio_Driver.h>
#include <MSP430_Registers.h>

#define WDTPW   (0x5A00)
#define WDTHOLD (0x0080)

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;

  GPIO_v_init();
  (void)GPIO_v_configPin(bit1, port2, output, gpio);
  (void)GPIO_v_setPinState(bit1, port2, high);

  return 0;
}