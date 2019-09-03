/*
 * Vista.cpp
 *
 *  Created on: Sep 3, 2019
 *      Author: franco
 */

#include "Vista.h"

Vista::Vista(Juego* modelo, Controlador* controlador) {

	juego = modelo;
	this->controlador = controlador;

	SDL_Init(0);
	//SDL_CreateWindow("Primer Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 360, 240, false);
	SDL_CreateWindowAndRenderer(WINDOW_SIZE_HORIZONTAL, WINDOW_SIZE_VERTICAL, 0, &win, &ren);
	SDL_SetWindowTitle(win, "Primer Juego");

	loop();
}

Vista::~Vista() {
	// TODO Auto-generated destructor stub
}

void Vista::render() {

	//fondo
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	SDL_Rect rect;
	rect.x=0;
	rect.y=0;
	rect.w=WINDOW_SIZE_HORIZONTAL;
	rect.h=WINDOW_SIZE_VERTICAL;
	SDL_RenderFillRect(ren, &rect);


	//personaje, interactuo con modelo
	int posicionH= juego->getPosicionJugador();

	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
	SDL_Rect jugador;
	jugador.h=80;
	jugador.w=20;
	jugador.x= WINDOW_SIZE_HORIZONTAL /2 + posicionH;
	jugador.y= WINDOW_SIZE_VERTICAL / 2;
	SDL_RenderFillRect(ren, &jugador);


	//por que se necesita este loop? ya hay otro similar en update()
	frameCount++;
	int timerFPS = SDL_GetTicks()-frameStart;
	if(timerFPS < frameDelay){
		SDL_Delay(frameDelay-timerFPS);
	}

	SDL_RenderPresent(ren);


}


void Vista::update(){
	// ?????????????????????????????
	// en este ejemplo no tiene sentido
}


void Vista::loop() {

	//ciclo infinito de renderizacion
	while(running){

		frameStart=SDL_GetTicks();
		static int lastTime;

		render();

		//llamo a controlador a ver si toco alguna tecla
		running = controlador->eventHandler();

		update();

		if(frameDelay > lastTime){
			SDL_Delay(frameDelay - lastTime);
		}

	}
}


