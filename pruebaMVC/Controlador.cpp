/*
 * Controlador.cpp
 *
 *  Created on: Sep 3, 2019
 *      Author: franco
 */

#include "Controlador.h"

Controlador::Controlador(Juego* juego) {
	// TODO Auto-generated constructor stub
	this->juego = juego;
}

Controlador::~Controlador() {
	// TODO Auto-generated destructor stub
}


bool Controlador::eventHandler(){
	bool running = true;
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
			case SDLK_RIGHT: juego->movimientoADerecha();
			break;
			case SDLK_LEFT: juego->movimientoAIzquierda();
						break;
			}
		}

	}

	return running;
}
