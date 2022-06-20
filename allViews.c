
#include "allViews.h"
#include "allModels.h"
#include "TrapView.h"
#include "BirdView.h"
#include "GameOverView.h"

void allViewsStart()
{
	birdViewStart();
}

void allViewsUpdate()
{
	if(s_allModelsSkip)
	{
		return;
	}
	trapsViewUpdate();
	birdViewUpdate();
	gameOverViewUpdate();
}

