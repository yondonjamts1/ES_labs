#include <asf.h>
#include "sam4e_ek.h"
#include "conf_board.h"

void handler(){
	ioport_toggle_pin_level(LED1_GPIO);
	return 0;
}

int main (void)
{
	board_init();
	ioport_init();
	
	pmc_enable_periph_clk(ID_PIOA);
	pio_set_debounce_filter(PIOA, PIN_PUSHBUTTON_1_MASK, 19);
	pio_handler_set(PIOA, ID_PIOA, PIN_PUSHBUTTON_1_MASK, PIN_PUSHBUTTON_1_ATTR, handler);
	NVIC_EnableIRQ((IRQn_Type) ID_PIOA);
	pio_handler_set_priority(PIOA, (IRQn_Type) ID_PIOA, 0);
	pio_enable_interrupt(PIOA, PIN_PUSHBUTTON_1_MASK);

	return 0;
	
}
