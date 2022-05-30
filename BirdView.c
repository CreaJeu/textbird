
#include <string.h>
#include "curses.h"

#include "allModels.h"
#include "BirdView.h"
#include "Bird.h"
#include "Sprite.h"



void birdViewStart()
{
	wchar_t* txt = L"\\  /\n \\/";
	spriteStart(&s__birdSpriteFly, txt);
	s__birdSpriteFly._x = s_birdX;

	txt = L" __\n/  \\";
	spriteStart(&s__birdSpriteFlap, txt);
	s__birdSpriteFlap._x = s_birdX;
}

void __drawSprite(struct Sprite* s)
{
	int i;
	for(i=0; i<s->_nbChars; i++)
	{
		struct __SpriteChar* sc = &(s->_chars[i]);
		mvaddch(s->_y + sc->_y, s->_x + sc->_x, sc->_c);
	}
}

void birdViewUpdate()
{
	struct Sprite* currSprite;
	if(s_flapNow)
	{
		currSprite = &s__birdSpriteFlap;
	}
	else
	{
		currSprite = &s__birdSpriteFly;
	}
	currSprite->_y = s_birdY;
	__drawSprite(currSprite);
}
