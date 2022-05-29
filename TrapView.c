
#include "curses.h"

#include "allModels.h"
#include "TrapView.h"
#include "Trap.h"



wchar_t shade(float s)
{
	//arbitrary palette with 30 shades (unicode characters)
	static wchar_t* shades = L"      ░░░░▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓███";
	//convert [O..1] to [0..29]
	int i = ((int)(s*299)) / 10;
	return shades[i];
}

void drawLine(float yStart, float xStart, float yEnd, float xEnd)
{
	struct LineDrawer* d = &__trapViewLineDrawer;
	lineDrawerStart(d, yStart, xStart, yEnd, xEnd);
	while(!lineDrawerHasFinished(d))
	{
		mvaddch(d->_currY, d->_currX, shade(d->_currDist));
		mvaddch(d->_currYbis, d->_currXbis, shade(d->_currDistBis));
		lineDrawerNext(d);
	}
}

void trapsViewUpdate()
{
	int i;//for "for loop"
	werase(stdscr);

	for(i=0; i<s_trapsCount; i++)
	{
		struct Trap* t = &(s_traps[i]);
		drawLine(t->_centerY, t->_centerX, t->_endY, t->_endX);
	}
}
