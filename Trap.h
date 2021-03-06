#ifndef TRAP_H
#define TRAP_H

struct Trap
{
	//public output
	float _centerY;
	float _centerX;
	float _endY;
	float _endX;

	//private
	float __radius;
	float __rotSpeed;
	float __cosBefore;
	float __cosDelta;
	float __sinBefore;
	float __sinDelta;
	float __cosNow;
	float __sinNow;
};

//static public
struct Trap* s_traps;
int s_trapsCount;
int s_trapsCurrentFront;

float s_trapRotSpeedScale;
float s_trapsXInterval;


//public methods
void trapStaticInit();
void trapsStart(float startX);
void trapsUpdate();

//private methods
void __trapStart(struct Trap* trap, float x);
void __trapsTurnover();

#endif // TRAP_H

