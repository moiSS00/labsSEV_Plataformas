#pragma once

#include "Actor.h"
#include "Animation.h" 

class Enemy : public Actor
{
public:
	Enemy(float x, float y, Game* game);
	void update();
	void draw() override; // Va a sobrescribir
	void impacted(); // Recibe impacto y pone animación de morir

	Animation* aMoving;
	Animation* animation; // Referencia a la animación mostrada
	int state;
	Animation* aDying;
};


