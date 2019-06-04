#include <asf.h>

void xotsor(__IO uint32_t time); // xotsor nertei void user function uusgene.
extern __IO uint32_t tdelay; // tdelay nertei global xuvisagch uusgene

int main (void)
{
	SysTick_Config( SystemCoreClock / 33 ); // undsen System-n clock-g 1000Hz clock bolgoj xuvaana
	
	sysclk_init(); // system clock ashiglaxad shaadlagatai function-uudiig duudaj ajilluuldag initialize xiix function
	board_init();  // sam4e-ek xavtang ashiglaxad shaadlagatai function-uudiig duudaj ajilluuldag initialize xiix function
	
	while(1){
		ioport_toggle_pin_level(LED1_GPIO);
		xotsor(500); // uusgesen xereglegchiin function-ruugaa oroltiin utga ugch ajilluulna.
	}
}

void xotsor(__IO uint32_t time)
{
	tdelay = time; // orj irsen parameteriig tdelay-t onoono.
	while(tdelay !=0); //tdelay ni "0"-ees yalaatai toxioldold ene function ajillasaar baina
}

__IO uint32_t tdelay;
void SysTick_Handler(void){ // Sistick sangaas deer 8r murund zarlasan 1000Hz-iin daguur tick xiine
	if (tdelay != 0) // tdelay-g SysTick_Config-t zaasnii daguur clock bureer "0"-ees yalgaatai toxioldold buyu "0" xurtel xorogduulna.
	{
		tdelay--;
	}
}