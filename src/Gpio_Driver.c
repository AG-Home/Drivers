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

#define NOT_INITIALIZED (uint8)0u
#define INITIALIZED     (uint8)1u

#ifdef __cplusplus
extern "C" {
#endif

static void             GPIO_v_setChannelFunction(t_PortPin e_pin, uint8* p_sel1, uint8* p_sel2, t_FunctionSelect e_function);
static void             GPIO_v_setChannelDir(t_PortPin e_pin, uint8* p_dirAddr, t_PinDir e_dir);
static t_PinDir         GPIO_t_getPinDir(t_Port e_port, t_PortPin e_pin);
static t_FunctionSelect GPIO_t_getPinState(t_Port e_port, t_PortPin e_pin);

static uint8 GpioInitialized = NOT_INITIALIZED;

void GPIO_v_init(void)
{
  const uint8 allPinsPort = 0xFF;

  if(GpioInitialized == INITIALIZED)
  {
    // TODO send a SW error (deinitilized)
  }
  else
  {
    GpioInitialized = INITIALIZED;
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
  if(e_dir == input)
  {
    *p_dirAddr &= ~e_pin;
  }
  else
  {
    *p_dirAddr |= e_pin;
  }
}

static t_FunctionSelect GPIO_t_getPinState(t_Port e_port, t_PortPin e_pin)
{
  t_FunctionSelect statePin;
  uint8            pxsel;
  uint8            pxsel2;

  switch(e_port)
  {
    case port1:
      pxsel  = *(uint8*)P1SEL_ADDR & e_pin;
      pxsel2 = *(uint8*)P1SEL2_ADDR & e_pin;
      if((pxsel == 0u) && (pxsel2 == 0u))
      {
        statePin = gpio;
      }
      else if((pxsel == e_pin) && (pxsel2 == 0u))
      {
        statePin = primary;
      }
      else
      {
        statePin = secondary;
      }
      break;
    case port2:
      pxsel  = *(uint8*)P2SEL_ADDR & e_pin;
      pxsel2 = *(uint8*)P2SEL2_ADDR & e_pin;
      if((pxsel == 0u) && (pxsel2 == 0u))
      {
        statePin = gpio;
      }
      else if((pxsel == e_pin) && (pxsel2 == 0u))
      {
        statePin = primary;
      }
      else
      {
        statePin = secondary;
      }
      break;
    default:
      break;
  }
  return statePin;
}

static t_PinDir GPIO_t_getPinDir(t_Port e_port, t_PortPin e_pin)
{
  t_PinDir retVal;
  switch(e_port)
  {
    case port1:
      if((*(uint8*)P1DIR_ADDR & e_pin) == e_pin)
      {
        retVal = output;
      }
      else
      {
        retVal = input;
      }
      break;

    case port2:
      if((*(uint8*)P2DIR_ADDR & e_pin) == e_pin)
      {
        retVal = output;
      }
      else
      {
        retVal = input;
      }
      break;

    default:
      break;
  }

  return retVal;
}

uint8 GPIO_v_configPin(t_PortPin e_pin, t_Port e_port, t_PinDir e_dir, t_FunctionSelect e_function)
{
  uint8 retVal = OK;

  if(GpioInitialized == INITIALIZED)
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

uint8 GPIO_v_setPinState(t_PortPin e_pin, t_Port e_port, t_PinState u_state)
{
  t_FunctionSelect statePin;
  t_PinDir         dirPin;
  uint8            retVal = OK;

  statePin = GPIO_t_getPinState(e_port, e_pin);
  dirPin   = GPIO_t_getPinDir(e_port, e_pin);

  if((statePin == gpio) && (dirPin == output))
  {
    switch(e_port)
    {
      case port1:
        if(u_state == high)
        {
          P1OUT |= e_pin;
        }
        else
        {
          P1OUT &= ~e_pin;
        }
        break;

      case port2:
        if(u_state == high)
        {
          P2OUT |= e_pin;
        }
        else
        {
          P2OUT &= ~e_pin;
        }
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
