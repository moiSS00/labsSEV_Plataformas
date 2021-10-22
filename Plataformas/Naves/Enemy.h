#pragma once

#include "Actor.h"
#include "Animation.h" 

class Enemy : public Actor
{
public:
	Enemy(float x, float y, Game* game);
	void update();
	void draw() override; // Va a sobrescribir
	void impacted(); // Recibe impacto y pone animaci�n de morir

	Animation* aMoving;
	Animation* animation; // Referencia a la animaci�n mostrada
	int state;
	Animation* aDying;
};


