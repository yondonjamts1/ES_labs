#include "asf.h"
#include "conf_qtouch.h"
#include "string.h"
#include "sam4e_ek.h"

static void init_interface(void) // inteface-uudiig initialize xiix function-g zarlaj todorxoilj uguv.
{
	twi_master_options_t twi_opt;
	memset((void *)&twi_opt, 0, sizeof(twi_master_options_t));
	twi_opt.speed = 100000;
	twi_master_setup(BOARD_QT_TWI_INSTANCE, &twi_opt);
}

struct qt_status status; //qt_status turliin status nertei struct uusgene. 
struct qt_setup_block setup_block; //qt_setup_block turliin setup_block nertei struct uusgene.
int main(void)
{
	enum status_code ret; //status butsaax status_code turliin xuvisagch uusgej zaralna.
	sysclk_init(); // system clock ashiglaxad shaadlagatai function-uudiig duudaj ajilluuldag initialize xiix function
	board_init();  // sam4e-ek xavtang ashiglaxad shaadlagatai function-uudiig duudaj ajilluuldag initialize xiix function
	init_interface(); // interface.uudiig initialize xiix function-uudiig duudaj ajilluulax function.
	
	qt_hardware_reset(); //qt controller-eer ashiglax.n umno reset xiine.

	ret = qt_get_comm_ready(); // qt-gee ajillaxad belen bolgoj function-iin return xiisen utgiig ret xuvsagchid onooj ugno.
	qt_read_setup_block(&setup_block); // qt setup xiixed shaadlagatai ugugduluudiig unshij avna.
	setup_qt_param(&setup_block); // shaadlagatai ugugduluudeer qt-g toxiruulna.
	qt_write_setup_block(&setup_block); // tuxain ugugduluu controller-luugaa bichij torxuulaga xiine.

	qt_get_status(&status); // status-aa avna. tuxain status-aas xamaarch QT interface-g xereglex function ajillana.

	while (1) { // xyazgaargui davtalt
		if (qt_is_change_line_low()) {
			qt_get_status(&status);
			doprocess(&status); // conf_qtouch.h dotor baix doprocess.g ajilluulna. status gdg struct-g oroltiin parameter bolgon avna.
		}
	}
}
