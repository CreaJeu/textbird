
#include "allModels.h"
#include "allControllers.h"
#include "allViews.h"

int main()
{
	allModelsStart();
	allControllersStart();
	allViewsStart();

    while(s_allModelsPlaying)
	{
		allControllersUpdate();
		allModelsUpdate();
		allViewsUpdate();

		allControllersPostUpdate();//sleep to prevent 100%CPU
	}

	return allControllersTerminate();
}

