#include <asf.h>

int main (void)
{
	sysclk_init(); // system clock ashiglaxad shaadlagatai function-uudiig duudaj ajilluuldag initialize xiix function
	board_init();  // sam4e-ek xavtang ashiglaxad shaadlagatai function-uudiig duudaj ajilluuldag initialize xiix function
	
	while(1){
		ioport_toggle_pin_level(LED1_GPIO); // zaaj ugson pin.g ioport sang ashiglan toggle xiix function.
		delay_ms(500);
	}
}