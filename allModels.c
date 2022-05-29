//for srand()
#include <stdlib.h>
//for time() for srand()
#include <time.h>

#include "allModels.h"
#include "Clock.h"
#include "Trap.h"

void allModelsStart()
{
	srand(time(00));
	clockStart(&s_clock);
	trapStaticInit();
	trapsStart(30);
}

void allModelsUpdate()
{
	clockUpdate(&(s_clock));
	trapsUpdate();
}

