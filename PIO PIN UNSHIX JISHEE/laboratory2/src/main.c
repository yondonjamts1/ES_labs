#include <asf.h>
#include "pio.h"
#include "sam4e_ek.h"
#include "conf_board.h"

int main(void)
{
	board_init();  // sam4e-ek xavtang ashiglaxad shaadlagatai function-uudiig duudaj ajilluuldag initialize xiix function
	while (1)
	{
		if (pio_get_pin_value(19)) // pio inteface.n oroltiin parametereer zaasan pin-giin utgiig avax function.
		{
			pio_set_pin_low(LED1_GPIO);
		}
		pio_set_pin_high(LED1_GPIO);
	}
	
	return 0;
}