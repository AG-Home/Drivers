/**********************************************************************************************************************
 * \file Dio_Driver.h
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

#ifndef DIO_DRIVER_H
#define DIO_DRIVER_H

#include <Dio_Types.h>
#include <Std_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

void DIO_v_init(void);

uint8 DIO_u_configPin(t_PortPin e_pin, t_Port e_port, t_PinDir e_dir, t_FunctionSelect e_function, t_Ren e_res);

uint8 DIO_v_setPinState(t_PortPin e_pin, t_Port e_port, t_PinState u_state);

void DIO_v_getPinState(t_PortPin e_pin, t_Port e_port, uint8 u_state);

#ifdef __cplusplus
}
#endif

#endif
