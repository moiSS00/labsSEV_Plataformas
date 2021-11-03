#include "Actor.h"

class CheckPoint : public Actor
{
public:
	CheckPoint(float x, float y, Game* game);

	bool activeCheckpoint = false; // Indica si se activó un checkPoint o no
	int lastPosition[2]; // Almacena la posició nueva (X e Y)
};


