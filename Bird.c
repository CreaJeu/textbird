
#include "Bird.h"
#include "Clock.h"
#include "World.h"


void birdStaticInit()
{
	s_birdX = 10;
	s_birdY = _worldHeight / 2;

	s_birdSpeedYScale = 1;
	s_birdAccelerationYScale = 1;

	s_birdSpeedY = -.035;
	s_birdAccelerationY = .00004;
}

void birdUpdate()
{
	s_birdSpeedY += s_birdAccelerationY * s_birdAccelerationYScale * s_clock._elapsed;
	s_birdY += s_birdSpeedY * s_birdSpeedYScale * s_clock._elapsed;
}

void birdFlap()
{
	s_birdSpeedY = -.025;
}

