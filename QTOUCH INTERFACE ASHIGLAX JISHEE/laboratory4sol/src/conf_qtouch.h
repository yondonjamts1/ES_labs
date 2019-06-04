#ifndef CONF_QTOUCH
#define CONF_QTOUCH

#define QT_SLIDER_RESOLUTION  QT_SLIDER_RESOLUTION_7_BIT
#define QT_SLIDER_MAX         ((0x01 << (8 - QT_SLIDER_RESOLUTION)) - 1)

static void setup_qt_param(struct qt_setup_block *setup_block)
{
	setup_block->slider_num_keys = 7;
	setup_block->slider_resolution = QT_SLIDER_RESOLUTION;


	setup_block->gpio_direction = 0x1C;
	setup_block->gpio_gpo_drive2 = 0x0;
}

static void doprocess(struct qt_status *qt_status)
{
	#define QT_LEFT_KEY_MASK     0x01
	#define QT_RIGHT_KEY_MASK    0x02

	static bool key_left_pressed = false;
	static bool key_right_pressed = false;
	static uint8_t slide_position = 0;

	if (qt_status->key_status_2 & QT_LEFT_KEY_MASK) {
		if (!key_left_pressed) {
			pio_toggle_pin(LED2_GPIO);
			key_left_pressed = true;
		}
		} else {
		if (key_left_pressed) {
			key_left_pressed = false;
		}
	}

	if (qt_status->key_status_2 & QT_RIGHT_KEY_MASK) {
		if (!key_right_pressed) {
			pio_toggle_pin(LED0_GPIO);
			key_right_pressed = true;
		}
		} else {
		if (key_right_pressed) {
			key_right_pressed = false;
		}
	}

	if (qt_status->general_status & QT_GENERAL_STATUS_SDET) {
		if (qt_status->slider_position != slide_position) {
			slide_position = qt_status->slider_position;
			if (slide_position > 64) pio_set_pin_low(LED1_GPIO);
			else pio_set_pin_high(LED1_GPIO);
		}
	}
}

#endif /* CONF_QTOUCH */
