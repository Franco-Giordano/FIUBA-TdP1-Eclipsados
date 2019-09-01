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
	void input();
	void render();
	void draw(Object o);

private:
	SDL_Renderer* ren;
	SDL_Window* win;
	bool running;
	int count;
	int frameCount;
	int timerFPS;
	int lastFrame;
	Cody cody;
	int caminar;
	int parado;
};


#endif /* GAME_H_ */
