#ifndef _GLOBAL_VARIABLES_H_
#define _GLOBAL_VARIABLES_H_

#include "types.h"


	extern pthread_cond_t cond;
	extern volatile sig_atomic_t stop;
	extern glob_s GlobData;

#endif /* _GLOBAL_VARIABLES_H_ */