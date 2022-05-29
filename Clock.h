#ifndef CLOCK_H
#define CLOCK_H

#include <time.h>

struct Clock
{
	//public output
	clock_t _elapsed;

	//private
	clock_t __now;
	clock_t __before;
};

//public static
struct Clock s_clock;

//public methods
void clockStart(struct Clock* clock);
void clockUpdate(struct Clock* clock);

#endif // CLOCK_H

