#include "game.h"



Game::Game(){
	SDL_Init(0);
	//SDL_CreateWindow("Primer Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 360, 240, false);
	SDL_CreateWindowAndRenderer(360, 240, 0, &win, &ren);
	SDL_SetWindowTitle(win, "Primer Juego");
	running=true;
	contx = conty = 0;
	cody.setImage("Cody.png", ren);
	cody.setDest(0, 0, 47, 95);
	parado = cody.crearCiclo(1, 47, 95, 1, 15);
	caminar = cody.crearCiclo(2, 47, 95, 6, 15);
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

		frameStart=SDL_GetTicks();
		static int lastTime;

		render();
		eventHandler();
		update();

		if(frameDelay > lastTime){
			SDL_Delay(frameDelay - lastTime);
		}

	}
}


void Game::render(){
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	SDL_Rect rect;
	rect.x=0;
	rect.y=0;
	rect.w=360;
	rect.h=240;
	SDL_RenderFillRect(ren, &rect);

	draw(cody);

	frameCount++;
	int timerFPS = SDL_GetTicks()-frameStart;
	if(timerFPS < frameDelay){
		SDL_Delay(frameDelay-timerFPS);
	}

	SDL_RenderPresent(ren);


}

void Game::draw(Object o){

	SDL_Rect dest = o.getDest();
	SDL_Rect src = o.getSource();
	SDL_RenderCopy(ren, o.getTex(), &src, &dest);
}

void Game::eventHandler(){
	SDL_Event e;
	while(SDL_PollEvent(&e)){
		if(e.type == SDL_QUIT){
			running =false;
			printf("Exiting");
		}
		if(e.type==SDL_KEYDOWN){
			switch(e.key.keysym.sym)
			{
			case SDLK_ESCAPE: running = false; //Apretas ESC y sale el juego
			break;
			case SDLK_RIGHT:if(accionActual != caminar){
								cody.setCurrentAnim(caminar);	//Apretas flecha derecha y deberia caminar a la der
								accionActual = caminar;
							}
						 	 contx=contx+5;
						 	 update();
			break;
			case SDLK_LEFT: if(accionActual != caminar){		//Apretas flecha a la izq y deberia caminar a la izq
								cody.setCurrentAnim(caminar);
								accionActual = caminar;
							}
							contx=contx-5;
							update();
			break;
			case SDLK_DOWN: if(accionActual != caminar){		//Apretas flecha abajo y deberia caminar para abajo
								cody.setCurrentAnim(caminar);
								accionActual = caminar;
							}
						 	conty=conty+5;
						 	update();
			break;
			case SDLK_UP: if(accionActual != caminar){		//Apretas flecha arriba y deberia caminar para arriba
							cody.setCurrentAnim(caminar);
							accionActual = caminar;
							}
						  conty=conty-5;
						  update();
			break;
			}
		}
		if(e.type==SDL_KEYUP){
			if(e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_DOWN){
				cody.setCurrentAnim(parado);
				accionActual = parado;
			}
		}
	}
}

void Game::update(){
	cody.setDest(contx, conty, 45, 95);
	cody.updateAnim();

}

