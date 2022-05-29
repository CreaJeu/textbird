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
	s_allModelsPlaying = 1;
	clockStart(&s_clock);
	trapStaticInit();
	trapsStart(30);
}

void allModelsUpdate()
{
	if(s_allModelsSkip)
	{
		return;
	}
	clockUpdate(&(s_clock));
	trapsUpdate();
}

