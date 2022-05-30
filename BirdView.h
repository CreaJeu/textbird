#ifndef BIRD_VIEW_H
#define BIRD_VIEW_H

#include "Sprite.h"

//private static
struct Sprite s__birdSpriteFly;
struct Sprite s__birdSpriteFlap;
struct Sprite s__birdSpriteDead;

//public methods
void birdViewStart();
void birdViewUpdate();


#endif // BIRD_VIEW_H

