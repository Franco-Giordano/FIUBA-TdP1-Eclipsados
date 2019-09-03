#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <stdio.h>
using namespace  std;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "objeto.h"
#include "cody.h"


class Game {
public:
	Game();
	~Game();
	void loop();
	void update();
	void eventHandler();
	void render();
	void draw(Object o);

private:
	SDL_Renderer* ren;
	SDL_Window* win;
	bool running;
	int contx, conty;
	int FPS = 60;
	int frameCount;
	int frameDelay = 1000/FPS;
	int timerFPS;
	Uint32 frameStart;
	Cody cody;
	int caminar;
	int parado;
	int accionActual;
};


#endif /* GAME_H_ */

