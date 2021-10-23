#pragma once

#include "Layer.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Text.h"
#include "Audio.h" 
#include "Tile.h"
#include "Space.h" // importar

#include <fstream> // Leer ficheros
#include <sstream> // Leer líneas / String
#include <list>

class GameLayer : public Layer
{
public:
	GameLayer(Game* game);
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;
	void keysToControls(SDL_Event event);
	void loadMap(string name);
	void loadMapObject(char character, float x, float y);
	void calculateScroll();

	Player* player;
	Background* background;
	bool controlShoot = false;
	int controlMoveY = 0;
	int controlMoveX = 0;
	int newEnemyTime = 0;
	Actor* backgroundPoints;
	Text* textPoints;
	int points;
	Audio* audioBackground;
	int mapWidth;
	list<Tile*> tiles;
	float scrollX;
	Space* space;
	Tile* cup; // Elemento de final de nivel

	list<Enemy*> enemies;
	list<Projectile*> projectiles;
};


