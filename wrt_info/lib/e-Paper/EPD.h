#ifndef _EPD_GENERICE_H_
#define _EPD_GENERICE_H_

	#include "EPD_1in02d.h"
	#include "EPD_1in54_DES.h"
	#include "EPD_1in54.h"
	#include "EPD_1in54_V2.h"
	#include "EPD_1in54b.h"
	#include "EPD_1in54b_V2.h"
	#include "EPD_1in54c.h"
	#include "EPD_1in64g.h"


	#include "EPD_2in13_DES.h"
	#include "EPD_2in13.h"
	#include "EPD_2in13_V2.h"
	#include "EPD_2in13_V3.h"
	#include "EPD_2in13_V4.h"
	#include "EPD_2in13b_V3.h"
	#include "EPD_2in13b_V4.h"
	#include "EPD_2in13bc.h"
	#include "EPD_2in13d.h"
	#include "EPD_2in13g.h"



	typedef struct WaveShare_Epaper {
		void (*init) (void);
		void (*init_fast) (void);
		void (*init_gUI) (void);
		void (*clear) (void);
		void (*clear_black) (void);
		void (*display) (UBYTE *Image);
		void (*display_fast) (UBYTE *Image);
		void (*display_base) (UBYTE *Image);
		void (*display_partial) (UBYTE *Image);
		void (*sleep) (void);
	} WS_EPD_s;

	extern WS_EPD_s EPD_2in13_V4;

#endif /* _EPD_GENERICE_H_ */