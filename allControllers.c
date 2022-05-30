
//for EXIT_SUCCESS
#include <stdlib.h>

#include "curses.h"

#include "allControllers.h"
#include "allModels.h"
#include "Bird.h"


void allControllersStart()
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

void allControllersUpdate()
{
	s_allModelsSkip = 0;//false
	s_flapNow = 0;

	switch (getch())
	{
	case 'o':
	case 'O':
		s_trapRotSpeedScale *= .6;
		s_allModelsSkip = 1;//true, skip
		break;
	case 'p':
	case 'P':
		s_trapRotSpeedScale *= 1.4;
		s_allModelsSkip = 1;//true, skip
		break;
	case ' ':
		s_flapNow = 1;// true
		break;
	case 'q':
	case 'Q':
//		if(getch() != ERR)
		s_allModelsSkip = 1;//true, skip
		s_allModelsPlaying = 0;//false, end game
	}
}

void allControllersPostUpdate()
{
	//a lot of "key repeats" may be in getch() queue
	// => a lot of "naps" to wait !
	// => should not sleep until queue is empty
	if(s_allModelsSkip)
	{
		return;
	}
	//sleep to prevent 100%CPU
	napms(90);
}

int allControllersTerminate()
{
	curs_set(1);
	endwin();
	return EXIT_SUCCESS;
}

