#include "CheckPoint.h"

CheckPoint::CheckPoint(float x, float y, Game* game)
	: Actor("res/bandera.png", x, y, 46, 40, game) {
	activeCheckpoint = false; 
	lastPosition[0] = x; 
	lastPosition[1] = y; 
}
