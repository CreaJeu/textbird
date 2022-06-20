
#include <string.h>
#include "curses.h"

#include "Bird.h"
#include "World.h"


wchar_t* gameOverL0 = L"                                ";
wchar_t* gameOverL1 = L"   ==========================   ";
wchar_t* gameOverL2 = L"   =                        =   ";
wchar_t* gameOverL3 = L"   =   G A M E    O V E R   =   ";
wchar_t* gameOverL4 = L"   ==========================   ";
wchar_t* gameOverL5 = L"            restart : <space>   ";
wchar_t* gameOverL6 = L"               quit :     <Q>   ";


void gameOverViewUpdate()
{
	if(s_collision)
	{
		int y = _worldHeight / 3;
		int x = _worldWidth / 4;
		mvaddwstr(y, x, gameOverL0);
		mvaddwstr(y + 1, x, gameOverL1);
		mvaddwstr(y + 2, x, gameOverL2);
		mvaddwstr(y + 3, x, gameOverL3);
		mvaddwstr(y + 4, x, gameOverL2);
		mvaddwstr(y + 5, x, gameOverL4);
		mvaddwstr(y + 6, x, gameOverL5);
		mvaddwstr(y + 7, x, gameOverL6);
		mvaddwstr(y + 8, x, gameOverL0);
	}
}
