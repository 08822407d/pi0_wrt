#ifndef _GPIO_STATUS_H_
#define _GPIO_STATUS_H_

#include "types.h"

    extern pthread_t gpio_thread;


    extern void* gpio_listener(void* arg);
    extern void keys_reset(keysstate_s *KeysStat);

#endif /* _GPIO_STATUS_H_ */