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
	void draw(float scrollX = 0) override; // Va a sobrescribir
	void jump();
	void loseLife();

	int shootCadence = 30;
	int shootTime = 0;
	int orientation;
	int state;
	bool onAir;
	int lifes = 3;
	int invulnerableTime = 0;

	Audio* audioShoot;

	Animation* aIdleRight;
	Animation* aIdleLeft;
	Animation* aRunningRight;
	Animation* aRunningLeft;
	Animation* aShootingRight;
	Animation* aShootingLeft;
	Animation* aJumpingRight;
	Animation* aJumpingLeft;
	Animation* animation; // Referencia a la animaci�n mostrada
};


