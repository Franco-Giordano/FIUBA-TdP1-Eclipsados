#include "game.h"



Game::Game(){
	SDL_Init(0);
	/*SDL_CreateWindow("Primer Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);*/
	SDL_CreateWindowAndRenderer(360, 240, 0, &win, &ren);
	SDL_SetWindowTitle(win, "Primer Juego");
	running=true;
	count=0;
	cody.setImage("Cody.png", ren);
	cody.setDest(100, 100, 47, 75);
	parado = cody.crearCiclo(1, 47, 45, 1, 0);
	caminar = cody.crearCiclo(2, 47, 45, 6, 20);
	cody.setCurrentAnim(parado);
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
		}

		render();
		input();
		update();
	}
}


void Game::render(){
	/*SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	SDL_Rect rect;
	rect.x=100;
	rect.y=100;
	rect.w=1000;
	rect.h=990;
	SDL_RenderFillRect(ren, &rect);*/

	draw(cody);

	frameCount++;
	int timerFPS = SDL_GetTicks()-lastFrame;
	if(timerFPS < (1000/60)){
		SDL_Delay((1000/60)-timerFPS);
	}

	SDL_RenderPresent(ren);


}

void Game::draw(Object o){

	SDL_Rect dest = o.getDest();
	SDL_Rect src = o.getSource();
	SDL_RenderCopyEx(ren, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

void Game::input(){
	SDL_Event e;
	while(SDL_PollEvent(&e)){
		if(e.type == SDL_QUIT){
			running =false;
			printf("Exiting");
		}
		if(e.type==SDL_KEYDOWN){
			switch(e.key.keysym.sym)
			{
			case SDLK_ESCAPE: running =false;
			case SDLK_w: cody.setCurrentAnim(caminar);
			}
		}
		if(e.type==SDL_KEYUP){
			if(e.key.keysym.sym == SDLK_w){
				/*player1.reverse(1,parado);*/
				cody.setCurrentAnim(parado);
			}
		}
	}
}

void Game::update(){
	cody.updateAnim();
}

