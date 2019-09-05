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

	//actualizar el array de estados (para GetKeyboardState)
	SDL_PumpEvents();

	bool running = true;

	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	if(keystates[SDL_SCANCODE_RIGHT]) {
		juego->movimientoDerecha();
	}

	if(keystates[SDL_SCANCODE_LEFT]) {
		juego->movimientoIzquierda();
	}

	if(keystates[SDL_SCANCODE_UP]) {
		juego->movimientoArriba();
	}

	if(keystates[SDL_SCANCODE_DOWN]) {
		juego->movimientoAbajo();
	}

	if(keystates[SDL_SCANCODE_ESCAPE]) {
		running = false;
	}

	return running;
}
