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

/**
 *
 * DIO_v_init
 * Init all pins for all ports
 *
 */
void DIO_v_init(void);

/**
 *
 * DIO_u_configPin
 * Pin's configuration
 *
 * \param [in] e_pin:       Pin port \n
 *                          data_type  = t_PortPin \n
 *                          resolution = bit0 to bit7
 * \param [in] e_port:      Port 1 or 2 of MSP430g2553 \n
 *                          data_type  = t_Port \n
 *                          resolution = port1 / port2
 * \param [in] e_dir:       Pin direction \n
 *                          data_type  = t_PinDir \n
 *                          resolution = input / output
 * \param [in] e_function:  Dio functionality \n
 *                          data_type  = t_FunctionSelect \n
 *                          resolution = gpio/ secondary / primary
 * \param [in] e_res:       Set resistor internal \n
 *                          data_type  = t_Ren \n
 *                          resolution = disabled / pullUp / pullDown
 *
 * \return  data_type  = uint8 \n
 *          resolution = OK / NOK
 *
 */
uint8 DIO_u_configPin(t_PortPin e_pin, t_Port e_port, t_PinDir e_dir, t_FunctionSelect e_function, t_Ren e_res);

/**
 *
 * DIO_u_setPinState
 * Set state of a pin that is configured as an output
 *
 * \param [in] e_pin:       Pin port \n
 *                          data_type  = t_PortPin \n
 *                          resolution = bit0 to bit7
 * \param [in] e_port:      Port 1 or 2 of MSP430g2553 \n
 *                          data_type  = t_Port \n
 *                          resolution = port1 / port2
 * \param [in] u_state:     Pin state \n
 *                          data_type  = t_PinState \n
 *                          resolution = low / high
 *
 * \return  data_type  = uint8 \n
 *          resolution = OK / NOK
 *
 */
uint8 DIO_u_setPinState(t_PortPin e_pin, t_Port e_port, t_PinState u_state);

/**
 *
 * DIO_u_getPinState
 * Get state of a pin that is configured as an input
 *
 * \param [in] e_pin:       Pin port \n
 *                          data_type  = t_PortPin \n
 *                          resolution = bit0 to bit7
 * \param [in] e_port:      Port 1 or 2 of MSP430g2553 \n
 *                          data_type  = t_Port \n
 *                          resolution = port1 / port2
 * \param [out] p_pinState: Pin's state \n
 *                          data_type  = t_PinState* \n
 *                          resolution = low / high
 *
 * \return  data_type  = uint8 \n
 *          resolution = OK / NOK
 *
 */
uint8 DIO_u_getPinState(t_PortPin e_pin, t_Port e_port, t_PinState* p_pinState);

#ifdef __cplusplus
}
#endif

#endif
