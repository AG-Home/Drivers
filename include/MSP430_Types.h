/**********************************************************************************************************************
 * \file MSP430_Types.h
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
 *  which are relevant for the MSP's project
 *********************************************************************************************************************/

#ifndef MSP430_TYPES_H
#define MSP430_TYPES_H

#include <Std_Types.h>

#define OK  (uint8)0x00;
#define NOK (uint8)0x01;

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
  bit0 = 1u,
  bit1 = 2u,
  bit2 = 4u,
  bit3 = 8u,
  bit4 = 16u,
  bit5 = 32u,
  bit6 = 64u,
  bit7 = 128u,

} t_PortPin;

typedef enum
{
  port1 = 0,
  port2
} t_Port;

typedef enum
{
  input = 0,
  output
} t_PinDir;

typedef enum
{
  gpio      = 0,
  primary   = 1,
  secondary = 2
} t_FunctionSelect;

#ifdef __cplusplus
}
#endif

#endif
