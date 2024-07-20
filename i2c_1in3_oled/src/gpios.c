#include "glob.h"
#include "gpio_listener.h"
#include "screen_disp.h"

#include "KEY_APP.h"


pthread_t gpio_thread;

void keys_reset(keysstate_s *KeysStat)
{
	KeysStat->Up = false;
	KeysStat->Down = false;
	KeysStat->Left = false;
	KeysStat->Right = false;
	KeysStat->Center = false;
	KeysStat->Key1 = false;
	KeysStat->Key2 = false;
	KeysStat->Key3 = false;
}

void keys_behavior(glob_s *Glob)
{
	dispstate_s *DispStat = &Glob->Display_Status;
	keysstate_s *KeysStat = &Glob->Keys_Status;

	if (
		KeysStat->Up ||
		KeysStat->Down ||
		KeysStat->Left ||
		KeysStat->Right ||
		KeysStat->Center ||
		KeysStat->Key1
		)
		activeScreen(DispStat);
	else if (
		KeysStat->Key2 ||
		KeysStat->Key3
	)
		deactiveScreen(DispStat);
}

void* gpio_listener(void* arg) {

	glob_s *Glob = (glob_s *)arg;
	keysstate_s *KeysStat = &Glob->Keys_Status;
	
	while (!stop) {
        pthread_mutex_lock(&KeysStat->lock);

		if(KEY_UP_RD == 0)
			KeysStat->Up = true;
		else
			KeysStat->Up = false;

		if(KEY_DOWN_RD == 0)
			KeysStat->Down = true;
		else
			KeysStat->Down = false;

		if(KEY_LEFT_RD == 0)
			KeysStat->Left = true;
		else
			KeysStat->Left = false;

		if(KEY_RIGHT_RD == 0)
			KeysStat->Right = true;
		else
			KeysStat->Right = false;

		if(KEY_PRESS_RD == 0)
			KeysStat->Center = true;
		else
			KeysStat->Center = false;

		if(KEY1_RD == 0)
			KeysStat->Key1 = true;
		else
			KeysStat->Key1 = false;

		if(KEY2_RD == 0)
			KeysStat->Key2 = true;
		else
			KeysStat->Key2 = false;

		if(KEY3_RD == 0)
			KeysStat->Key3 = true;
		else
			KeysStat->Key3 = false;

        pthread_mutex_unlock(&KeysStat->lock);

		keys_behavior(Glob);

		usleep(1000);
	}

	printf("Thread: gpio_listener Exiting.\n");
	return NULL;
}