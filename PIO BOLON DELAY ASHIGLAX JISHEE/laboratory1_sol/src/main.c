#include <asf.h>
#include "sam4e_ek.h"
#include "delay.h"
#include "pio.h"

int main (void)
{

	sysclk_init(); // system clock ashiglaxad shaadlagatai function-uudiig duudaj ajilluuldag initialize xiix function
	board_init();  // sam4e-ek xavtang ashiglaxad shaadlagatai function-uudiig duudaj ajilluuldag initialize xiix function

	while (1)
	{
		pio_toggle_pin(PIO_PA0_IDX); // pio inteface.n oroltiin parametereer zaaj ugson pin-g toggle xiix function.
		delay_ms(100); // delay.h sang ashiglan oroltiin parameter-n daguu millisecond-oor delay uusgex function.
		pio_toggle_pin(PIO_PD20_IDX);
		delay_ms(100);
		pio_toggle_pin(PIO_PD21_IDX);
		delay_ms(100);
		
	}
}
