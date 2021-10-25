#pragma once

#include "Actor.h"

class Door : public Actor {
public:
	Door(float x, float y, Game* game);

	Door* connectedTo; // Puerta a la que esta conectada
	int id; // Identificador de la puerta 
};

