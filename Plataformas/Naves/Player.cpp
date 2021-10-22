#include "Player.h"

Player::Player(float x, float y, Game* game)
	: Actor("res/jugador.png", x, y, 35, 35, game) {
	orientation = game->orientationRight;
	audioShoot = new Audio("res/efecto_disparo.wav", false);

	aIdleRight = new Animation("res/jugador_idle_derecha.png", width, height,
		320, 40, 6, 8, game);
	aIdleLeft = new Animation("res/jugador_idle_izquierda.png", width, height,
		320, 40, 6, 8, game);
	aRunningRight = new Animation("res/jugador_corriendo_derecha.png", width, height,
		320, 40, 6, 8, game);
	aRunningLeft = new Animation("res/jugador_corriendo_izquierda.png", width, height,
		320, 40, 6, 8, game);
	animation = aIdleRight;
}

void Player::update() {
	animation->update();

	// Establecer orientaci�n
	if (vx > 0) {
		orientation = game->orientationRight;
	}
	if (vx < 0) {
		orientation = game->orientationLeft;
	}

	// Selecci�n de animaci�n
	if (vx != 0) {
		if (orientation == game->orientationRight) {
			animation = aRunningRight;
		}
		if (orientation == game->orientationLeft) {
			animation = aRunningLeft;
		}
	}

	if (vx == 0) {
		if (orientation == game->orientationRight) {
			animation = aIdleRight;
		}
		if (orientation == game->orientationLeft) {
			animation = aIdleLeft;
		}
	}

	if (shootTime > 0) {
		shootTime--;
	}
	x = x + vx;
	y = y + vy;
}

void Player::moveX(float axis) {
	vx = axis * 3;
}

void Player::moveY(float axis) {
	vy = axis * 3;
}

Projectile* Player::shoot() {
	if (shootTime == 0) {
		audioShoot->play();
		shootTime = shootCadence;
		return new Projectile(x, y, game);
	}
	else {
		return NULL;
	}
}

void Player::draw() {
	animation->draw(x, y);
}



