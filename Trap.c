
//for rand()
#include <stdlib.h>
//for cos() etc.
#include <math.h>

#include "Trap.h"
#include "Clock.h"
#include "World.h"
#include "Bird.h"
#include "Intersection.h"


float range(float min, float max)
{
	float span = max - min;
	float ratio = ((float)rand()) / (float)RAND_MAX;
	return min + (span * ratio);
}

void trapStaticInit()
{
	s_trapsCount = 8;
	s_traps = (struct Trap*)malloc(s_trapsCount * sizeof(struct Trap));
	//free : don't bother, lifetime = whole game lifetime

	s_trapsCurrentFront = 0;

	s_trapRotSpeedScale = 1;
	s_trapsXInterval = 12;
}

void __trapStart(struct Trap* t, float x)
{
	float maxRadius = 14;
	t->_centerY = range(1, _worldHeight - maxRadius - 1);
	t->_centerX = x;
	t->__radius = range(6, maxRadius);
	t->__rotSpeed = range(.0002, .002);

	float angle = range(0, 6.3);
	t->__cosBefore = cosf(angle);
	t->__cosNow = t->__cosBefore;
	t->__cosDelta = 1;
	t->__sinBefore = sinf(angle);
	t->__sinNow = t->__sinBefore;
	t->__sinDelta = 0;

	t->_endY = t->_centerY + t->__sinNow * t->__radius;
	t->_endX = t->_centerX + t->__cosNow * t->__radius;
}

void trapsStart(float startX)
{
	int i;//for "for loop"
	for(i=0; i<s_trapsCount; i++)
	{
		struct Trap* t = &(s_traps[i]);
		float xTrap = startX + (i * s_trapsXInterval);
		__trapStart(t, xTrap);
	}
}

void __trapsTurnover()
{
	struct Trap* t = &(s_traps[s_trapsCurrentFront]);
	float newX = t->_centerX + (s_trapsCount * s_trapsXInterval);
	__trapStart(t, newX);
	s_trapsCurrentFront = (s_trapsCurrentFront + 1) % s_trapsCount;
}

void trapsUpdate()
{
	int i,j;//for "for loop"

	if(s_traps[s_trapsCurrentFront]._centerX <= -4)
	{
		__trapsTurnover();
	}

	for(j=0; j<s_trapsCount; j++)
	{
		i = (j + s_trapsCurrentFront) % s_trapsCount;

		struct Trap* t = &(s_traps[i]);
		t->_centerX -= s_clock._elapsed * _worldXSpeed;
		t->__cosBefore = t->__cosNow;
		t->__sinBefore = t->__sinNow;
		clock_t deltaTime = s_clock._elapsed;

		t->__cosDelta = cosf(t->__rotSpeed * s_trapRotSpeedScale * deltaTime);
		t->__sinDelta = sinf(t->__rotSpeed * s_trapRotSpeedScale * deltaTime);
		//cos(a+b) = cos a cos b - sin a sin b
		//cosNow = cos(before + deltaTime)
		t->__cosNow = (t->__cosBefore * t->__cosDelta) - (t->__sinBefore * t->__sinDelta);

		//sin(a+b) = cos a sin b + sin a cos b
		//sinNow = sin(before + delatTime)
		t->__sinNow = (t->__cosBefore * t->__sinDelta) + (t->__sinBefore * t->__cosDelta);

		t->_endY = t->_centerY + (t->__radius * t->__sinNow);
		t->_endX = t->_centerX + (t->__radius * t->__cosNow);

		//collision test
		if((i < 4) && (!s_collision))
		{
			float minY = s_birdY - 1;
			float maxY = s_birdY + 1;
			//avoid passing through walls when speed is high
			if(s_birdSpeedY < 0)
			{
				maxY -= (s_birdSpeedY * s_clock._elapsed);
			}
			else
			{
				minY -= (s_birdSpeedY * s_clock._elapsed);
			}
			s_collision = intersectSegBox(t->_centerX, t->_centerY, t->_endX, t->_endY,
										s_birdX-2, minY, s_birdX+2, maxY);
		}
	}
}

