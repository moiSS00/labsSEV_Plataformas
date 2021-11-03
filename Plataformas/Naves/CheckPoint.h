#include "Actor.h"

class CheckPoint : public Actor
{
public:
	CheckPoint(float x, float y, Game* game);

	bool activeCheckpoint = false; // Indica si se activ� un checkPoint o no
	int lastPosition[2]; // Almacena la posici� nueva (X e Y)
};


