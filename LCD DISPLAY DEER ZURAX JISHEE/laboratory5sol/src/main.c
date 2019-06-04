#include "asf.h"
#include "stdio_serial.h"
#include "conf_board.h"
#include "conf_clock.h"
#include "smc.h"
#include "delay.h"
#include "sam4e_ek.h"

#define ILI93XX_LCD_CS      1

struct ili93xx_opt_t g_ili93xx_display_opt; // Degetsend zoriulj medeelel damjuulax struct uusgex

int main(void)
{
	sysclk_init();
	board_init();

	pmc_enable_periph_clk(ID_SMC);

	smc_set_setup_timing(SMC, ILI93XX_LCD_CS, SMC_SETUP_NWE_SETUP(2)
			| SMC_SETUP_NCS_WR_SETUP(2)
			| SMC_SETUP_NRD_SETUP(2)
			| SMC_SETUP_NCS_RD_SETUP(2));
	smc_set_pulse_timing(SMC, ILI93XX_LCD_CS, SMC_PULSE_NWE_PULSE(4)
			| SMC_PULSE_NCS_WR_PULSE(4)
			| SMC_PULSE_NRD_PULSE(10)
			| SMC_PULSE_NCS_RD_PULSE(10));
	smc_set_cycle_timing(SMC, ILI93XX_LCD_CS, SMC_CYCLE_NWE_CYCLE(10)
			| SMC_CYCLE_NRD_CYCLE(22));
#if ((!defined(SAM4S)) && (!defined(SAM4E)))
	smc_set_mode(SMC, ILI93XX_LCD_CS, SMC_MODE_READ_MODE
			| SMC_MODE_WRITE_MODE
			| SMC_MODE_DBW_8_BIT);
#else
	smc_set_mode(SMC, ILI93XX_LCD_CS, SMC_MODE_READ_MODE
			| SMC_MODE_WRITE_MODE);
#endif

	g_ili93xx_display_opt.ul_width = ILI93XX_LCD_WIDTH;
	g_ili93xx_display_opt.ul_height = ILI93XX_LCD_HEIGHT;
	g_ili93xx_display_opt.foreground_color = COLOR_BLACK;
	g_ili93xx_display_opt.background_color = COLOR_WHITE;


	aat31xx_disable_backlight();

	ili93xx_init(&g_ili93xx_display_opt); // delgetsiig initialize xiix.


	aat31xx_set_backlight(AAT31XX_AVG_BACKLIGHT_LEVEL); // delgetsnii gerliig toxiruulax

	ili93xx_set_foreground_color(COLOR_WHITE); // background color-g toxiruulax.
	ili93xx_draw_filled_rectangle(0, // exleliin tseg X tenxleg /xevtee tenxleg/
	 							  0, // exleliin tseg Y tenxleg /bosoo tenxleg/
	 							  ILI93XX_LCD_WIDTH, // dursiin xemjee X tenxleg /xevtee tenxleg/
								  ILI93XX_LCD_HEIGHT); //dursiin xemjee Y tenxleg /bosoo tenxleg/ 
								  // 53-r murund baix function ni umno toxiruulsan background color-ooroo zaasan parameteriin daguu tegsh untsogt zurax. 
	ili93xx_display_on(); // delgetsiig asaax function
	ili93xx_set_cursor_position(0, 0); // exleliin tsegiig toxiruulax function.

	int i = 10;
	
	while (i < ILI93XX_LCD_WIDTH - 10)
	{
		ili93xx_set_foreground_color(COLOR_WHITE);
		ili93xx_draw_filled_rectangle(0,0,240,35);
		ili93xx_set_foreground_color(COLOR_BLACK);
		ili93xx_draw_string(i, 20, (uint8_t *)"ursdag text"); // zaasan coordination deer string bichix function
		delay_ms(25);
		i++;
		if (i >= ILI93XX_LCD_WIDTH - 10)
		{
			i = 10;
		}
	}

	while (1) {
	}
}
