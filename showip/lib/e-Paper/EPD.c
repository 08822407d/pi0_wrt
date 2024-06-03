#include "EPD.h"

WS_EPD_s EPD_2in13_V4 = {
	.init				= EPD_2in13_V4_Init,
	.init_fast			= EPD_2in13_V4_Init_Fast,
	.clear				= EPD_2in13_V4_Clear,
	.clear_black		= EPD_2in13_V4_Clear_Black,
	.display			= EPD_2in13_V4_Display,
	.display_fast		= EPD_2in13_V4_Display_Fast,
	.display_base		= EPD_2in13_V4_Display_Base,
	.display_partial	= EPD_2in13_V4_Display_Partial,
	.sleep				= EPD_2in13_V4_Sleep,
};
