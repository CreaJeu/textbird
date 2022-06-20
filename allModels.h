#ifndef ALL_MODELS_H
#define ALL_MODELS_H

#include "Clock.h"
#include "Trap.h"

//public static
int s_allModelsPlaying;//bool
int s_allModelsSkip;//bool
int s_allModelsRestart;//bool
int s_flapNow;//bool

void allModelsStart();
void allModelsUpdate();

#endif // ALL_MODELS_H

