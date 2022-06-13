
#include <stdlib.h>
#include <string.h>
#include "Sprite.h"


void spriteStart(struct Sprite* s, wchar_t* textSprite)
{
	int i;//for "for loop"
	int textLength = wcslen(textSprite);
	s->_nbChars = 0;
	int currNbChars = 0;
	int y = 0;
	int x = 0;
	int maxX = 0;
	int maxY = 0;
	int dX = 0;
	int dY = 0;
	for(i=0; i<textLength; i++)
	{
		if( (textSprite[i] != L'\n') && (textSprite[i] != L' ') )
		{
			currNbChars++;
		}
	}
	s->_chars = malloc(currNbChars * sizeof(struct __SpriteChar));

	for(i=0; i<textLength; i++)
	{
		if(textSprite[i] == L'\n')
		{
			y++;
			x = -1;
		}
		else if(textSprite[i] != L' ')
		{
			s->_chars[s->_nbChars]._y = y;
			s->_chars[s->_nbChars]._x = x;
			s->_chars[s->_nbChars]._c = textSprite[i];
			s->_nbChars++;
			if(x > maxX)
			{
				maxX = x;
			}
		}
		x++;
	}

	//center x/y on sprite center
	maxY = s->_chars[s->_nbChars - 1]._y;
	dX = maxX / 2;
	dY = maxY / 2;
	for(i=0; i < s->_nbChars; i++)
	{
		s->_chars[i]._y -= dY;
		s->_chars[i]._x -= dX;
	}

	s->_y = 0;
	s->_x = 0;
}

void spriteFree(struct Sprite* s)
{
	free(s->_chars);
	s->_nbChars = 0;
}

