#pragma once

#include "Actor.h"
#include "Projectile.h" 
#include "Audio.h"
#include "Animation.h" // incluir animacion 

class Player : public Actor
{
public:
	Player(float x, float y, Game* game);
	void update();
	void moveX(float axis);
	void moveY(float axis);
	Projectile* shoot();
	void draw() override; // Va a sobrescribir

	int shootCadence = 30;
	int shootTime = 0;
	int orientation;
	int state;

	Audio* audioShoot;

	Animation* aIdleRight;
	Animation* aIdleLeft;
	Animation* aRunningRight;
	Animation* aRunningLeft;
	Animation* aShootingRight;
	Animation* aShootingLeft;
	Animation* animation; // Referencia a la animaci�n mostrada
};

