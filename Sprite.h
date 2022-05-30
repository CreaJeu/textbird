#ifndef SPRITE_H
#define SPRITE_H

//for wchar_t
#include <string.h>

struct __SpriteChar
{
	int _y;
	int _x;
	wchar_t _c;
};

struct Sprite
{
	//public output
	struct __SpriteChar* _chars;
	int _nbChars;

	int _y;
	int _x;
};

//public methods
void spriteStart(struct Sprite* s, wchar_t* textSprite);
void spriteFree(struct Sprite* s);


#endif // SPRITE_H

