/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include "delay.h"
#include "pwm.h"
#include "led.h"
#include "pio.h"
#include "board.h"

void Button_Handler(uint32_t id, uint32_t mask)
{

	ioport_toggle_pin_level(LED1_GPIO);
}


int main (void)
{

	board_init();

	pmc_enable_periph_clk(ID_PIOA);
	pio_set_debounce_filter(PIOA, PIN_PUSHBUTTON_1_MASK, 19);
	pio_handler_set(PIOA, ID_PIOA,
	PIN_PUSHBUTTON_1_MASK, PIN_PUSHBUTTON_1_ATTR, Button_Handler);
	NVIC_EnableIRQ((IRQn_Type) ID_PIOA);
	pio_handler_set_priority(PIOA, (IRQn_Type) ID_PIOA, 0);
	pio_enable_interrupt(PIOA, PIN_PUSHBUTTON_1_MASK);
	
	ioport_set_pin_level(LED2_GPIO, LED2_ACTIVE_LEVEL);
	//}
		
}
