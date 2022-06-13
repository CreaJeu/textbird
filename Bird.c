
#include "Bird.h"
#include "Clock.h"
#include "World.h"


void birdStaticInit()
{
	s_birdX = 10;
	s_birdY = _worldHeight / 2;

	s_birdSpeedYScale = 1;
	s_birdAccelerationYScale = 1;

	s_birdSpeedY = -.06;
	s_birdAccelerationY = .00007;

	s_collision = 0;
}

void birdUpdate()
{
	s_birdSpeedY += s_birdAccelerationY * s_birdAccelerationYScale * s_clock._elapsed;
	s_birdY += s_birdSpeedY * s_birdSpeedYScale * s_clock._elapsed;

	if(s_birdY <= 0)
	{
		s_birdY = 0;
		s_collision = 1;//true
	}
	if(s_birdY >= _worldHeight)
	{
		s_birdY = _worldHeight;
		s_collision = 1;//true
	}
}

void birdFlap()
{
	s_birdSpeedY = -.04;
}

