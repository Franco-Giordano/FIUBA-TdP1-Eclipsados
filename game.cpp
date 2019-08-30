#include "game.h"

Game::Game(){
	SDL_Init(0);
	SDL_CreateWindow("Primer Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
	/*SDL_SetWindowTitle(win, "Primer Juego");*/
	running=true;
	count=0;
	loop();
}

Game::~Game(){
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

void Game::loop(){

	while(running){

		lastFrame=SDL_GetTicks();
		static int lastTime;
		if(lastFrame >= (lastTime+1000)){
			lastTime=lastFrame;
			frameCount=0;
			count++;
		}

		render();
		input();
		update();

		if (count>3) running=false;
	}
}


void Game::render(){
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	SDL_Rect rect;
	rect.x=rect.y=0;
	rect.w=700;
	rect.h=500;
	SDL_RenderFillRect(ren, &rect);

	frameCount++;
	int timerFPS = SDL_GetTicks()-lastFrame;
	if(timerFPS < (1000/60)){
		SDL_Delay((1000/60)-timerFPS);
	}

	SDL_RenderPresent(ren);

}
