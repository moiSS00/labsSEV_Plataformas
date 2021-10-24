#pragma once

#include "Actor.h"
#include "Animation.h"

class Collectable : public Actor {
public:
	Collectable(float x, float y, Game* game); // Constructor
	void draw(float scrollx = 0) override; // Sobrescribir para pintar la animacion 
	void update(); // Actualizar la animación 

	Animation* animation; // Animacion infinita a usar
};

