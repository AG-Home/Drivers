/**********************************************************************************************************************
 * \file Gpio_Driver.c
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
 *  which are relevant for the GPIO Driver
 *********************************************************************************************************************/

#include <Gpio_Driver.h>
#include <MSP430_Registers.h>

#ifdef __cplusplus
extern "C" {
#endif

static void GPIO_v_setChannelFunction(t_PortPin e_pin, uint8* p_sel1, uint8* p_sel2, t_FunctionSelect e_function);
static void GPIO_v_setChannelDir(t_PortPin e_pin, uint8* p_dirAddr, t_PinDir e_dir);

static uint8 GpioInitialized = 0;

void GPIO_v_init(void)
{
  const uint8 allPinsPort = 0xFF;
  const uint8 PinsPort    = 0xFF;

  if(GpioInitialized == 1)
  {
    // TODO send a SW error (deinitilized)
  }
  else
  {
    GpioInitialized = 1;
  }

  P1DIR = 0;
  P2DIR = 0;
  P1OUT = 0;
  P2OUT = 0;
  P1REN = allPinsPort;
  P2REN = allPinsPort;
}

static void GPIO_v_setChannelFunction(t_PortPin e_pin, uint8* p_sel1, uint8* p_sel2, t_FunctionSelect e_function)
{
  switch(e_function)
  {
    case gpio:
      *p_sel1 &= ~e_pin;
      *p_sel2 &= ~e_pin;
      break;
    case primary:
      *p_sel1 |= e_pin;
      *p_sel2 &= ~e_pin;
      break;
    case secondary:
      *p_sel1 |= e_pin;
      *p_sel2 |= e_pin;
      break;
    default:
      break;
  }
}

static void GPIO_v_setChannelDir(t_PortPin e_pin, uint8* p_dirAddr, t_PinDir e_dir)
{
  if(e_dir = input)
  {
    *p_dirAddr &= ~e_pin;
  }
  else
  {
    *p_dirAddr |= e_pin;
  }
}

uint8 GPIO_v_configPin(t_PortPin e_pin, t_Port e_port, t_PinDir e_dir, t_FunctionSelect e_function)
{
  uint8 retVal = OK;

  if(GpioInitialized == 1)
  {
    switch(e_port)
    {
      case port1:
        GPIO_v_setChannelDir(e_pin, (uint8*)P1DIR_ADDR, e_dir);
        GPIO_v_setChannelFunction(e_pin, (uint8*)P1SEL_ADDR, (uint8*)P1SEL2_ADDR, e_function);
        break;

      case port2:
        GPIO_v_setChannelDir(e_pin, (uint8*)P2DIR_ADDR, e_dir);
        GPIO_v_setChannelFunction(e_pin, (uint8*)P2SEL_ADDR, (uint8*)P2SEL2_ADDR, e_function);
        break;

      default:
        break;
    }
  }
  else
  {
    retVal = NOK;
  }

  return retVal;
}

#ifdef __cplusplus
}
#endif
