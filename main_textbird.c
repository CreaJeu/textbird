
#include "curses.h"
#include <stdlib.h>
#include <time.h>
//#include <math.h>

#include "textRaster.h"

#include "allModels.h"

void initCurses()
{
#ifdef XCURSES
    Xinitscr(argc, argv);//??
#else
    initscr();
#endif
    nl();
    noecho();
    curs_set(0);
    timeout(0);
    keypad(stdscr, TRUE);
}

int endCurses()
{
	curs_set(1);
	endwin();
	return EXIT_SUCCESS;
}

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
	struct LineDrawer d;
	lineDrawerStart(&d, yStart, xStart, yEnd, xEnd);
	while(!lineDrawerHasFinished(&d))
	{
		mvaddch(d._currY, d._currX, shade(d._currDist));
		mvaddch(d._currYbis, d._currXbis, shade(d._currDistBis));
		lineDrawerNext(&d);
	}
}

int main()
{
	int i;//for "for loop"

	allModelsStart();

	initCurses();

    while(TRUE)
	{
        switch (getch())
        {
		case 'o':
		case 'O':
			s_trapRotSpeedScale *= .6;
			break;
		case 'p':
		case 'P':
			s_trapRotSpeedScale *= 1.4;
			break;
        case 'q':
        case 'Q':
//		if(getch() != ERR)
//		{
            return endCurses();
		default:



			allModelsUpdate();

			werase(stdscr);

			for(i=0; i<s_trapsCount; i++)
			{
				struct Trap* t = &(s_traps[i]);
				drawLine(t->_centerY, t->_centerX, t->_endY, t->_endX);
			}

			napms(90);


        }


//		refresh();
//		napms(51);
	}

	return endCurses();
}

