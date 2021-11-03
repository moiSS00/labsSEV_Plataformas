#pragma once

#include "Layer.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Text.h"
#include "Audio.h" 
#include "Tile.h"
#include "Space.h" 
#include "Pad.h"
#include "Collectable.h"
#include "CheckPoint.h"
#include "Door.h"

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
	void mouseToControls(SDL_Event event); // USO DE MOUSE
	void gamePadToControls(SDL_Event event); // USO DE GAMEPAD

	Player* player;
	Background* background;
	bool controlShoot = false;
	int controlMoveY = 0;
	int controlMoveX = 0;
	int newEnemyTime = 0;
	Audio* audioBackground;
	int mapWidth;
	float scrollX;
	Space* space;

	// Elementos de interfaz
	SDL_GameController* gamePad;
	Pad* pad;
	Actor* buttonJump;
	Actor* buttonShoot;

	Actor* message;
	bool pause;
	bool controlContinue = false;

	// Contador de puntos 
	Actor* backgroundPoints;
	Text* textPoints;
	int points;

	// Contador de recolectables recogidos
	Actor* backgroundCollectable;
	Text* textCollectables;
	int numberOfColectables;

	//Check point 
	CheckPoint* checkPoint;

	// Tiles 
	list<Tile*> tiles;
	list<Tile*> jumpingPlatforms;
	list<Tile*> destructibleTiles;

	// Elemento de final de nivel (copa)
	Tile* cup; 

	// Listas de actores
	list<Enemy*> enemies;
	list<Projectile*> projectiles;
	list<Collectable*> collectables;
	list<Door*> doors;

private:
	void createDoor(float x, float y, int id); // Método privado auxiliar para crear una puerta
};


