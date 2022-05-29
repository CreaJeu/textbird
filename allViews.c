
#include "allViews.h"
#include "allModels.h"
#include "TrapView.h"

void allViewsStart()
{
}

void allViewsUpdate()
{
	if(s_allModelsSkip)
	{
		return;
	}
	trapsViewUpdate();
}

