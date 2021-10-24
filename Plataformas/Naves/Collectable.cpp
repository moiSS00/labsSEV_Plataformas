#include "Collectable.h"

Collectable::Collectable(float x, float y, Game* game)
	: Actor("res/icono_recolectable.png", x, y, 40, 40, game) {

	animation = new Animation("res/recolectable.png", width, height,
		256, 32, 6, 8, true, game);
}

void Collectable::draw(float scrollx) {
	animation->draw(x - scrollx, y);
}

void Collectable::update() {
	animation->update(); // Actualizamos la animacion
}


