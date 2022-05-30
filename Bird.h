#ifndef BIRD_H
#define BIRD_H


//static public
float s_birdX;
float s_birdY;

float s_birdSpeedY;
float s_birdAccelerationY;

//for user options
float s_birdSpeedYScale;
float s_birdAccelerationYScale;

//public methods
void birdStaticInit();
void birdUpdate();
void birdFlap();


#endif // BIRD_H

