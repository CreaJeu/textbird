#include "Clock.h"

void clockStart(struct Clock* c)
{
	c->__now = clock();
	c->__before = c->__now;
}

void clockUpdate(struct Clock* c)
{
	c->__before = c->__now;
	c->__now = clock();
	c->_elapsed = c->__now - c->__before;
}

