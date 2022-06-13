#include "Clock.h"

void clockStart(struct Clock* c)
{
	c->__now = clock();
	c->__before = c->__now;
	c->_scale = 1;
}

void clockUpdate(struct Clock* c)
{
	c->__before = c->__now;
	c->__now = clock();
	c->_elapsed = (int)((c->__now - c->__before) * c->_scale);
}

