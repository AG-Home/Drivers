/**********************************************************************************************************************
 * \file Gpio_Driver.h
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

#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <MSP430_Types.h>
#include <MSP430_Registers.h>

#ifdef __cplusplus
extern "C" {
#endif

void GPIO_v_configPin(t_PortPin e_pin, t_Port e_port, t_PinDir e_dir);

#ifdef __cplusplus
}
#endif

#endif
