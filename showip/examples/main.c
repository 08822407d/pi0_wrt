#include <stdlib.h>     //exit()
#include <signal.h>     //signal()
#include "EPD_Test.h"   //Examples
#include "EPD.h"


WS_EPD_s *EPD = &EPD_2in13_V4;


void  Handler(int signo)
{
	//System Exit
	printf("\r\nHandler:exit\r\n");

	EPD->clear();

	alarm(0);

	Debug("Goto Sleep...\r\n");
	EPD->sleep();
	DEV_Delay_ms(2000);//important, at least 2s
	// close 5V
	Debug("close 5V, Module enters 0 power consumption ...\r\n");
	DEV_Module_Exit();

	exit(0);
}

int main(void)
{
	// Exception handling:ctrl + c
	signal(SIGINT, Handler);
	// System shutdown handling
	signal(SIGTERM, Handler);

	if (EPD == NULL)
		return -1;
	
	showip();
	
	return 0;
}
