//for srand()
#include <stdlib.h>
//for time() for srand()
#include <time.h>

#include "allModels.h"
#include "Clock.h"
#include "World.h"
#include "Trap.h"
#include "Bird.h"

void allModelsStart()
{
	srand(time(00));
	s_allModelsPlaying = 1;
	s_allModelsRestart = 0;
	s_flapNow = 0;
	clockStart(&s_clock);
	worldStaticInit();
	trapStaticInit();
	trapsStart(30);
	birdStaticInit();
}

void allModelsUpdate()
{
	if(s_allModelsRestart)
	{
		allModelsStart();
		return;
	}
	if(s_allModelsSkip)
	{
		return;
	}
	clockUpdate(&(s_clock));
	if(s_flapNow)
	{
		birdFlap();
	}
	birdUpdate();
	trapsUpdate();
	if(s_collision)
	{
		s_clock._scale = 0;
	}
}

