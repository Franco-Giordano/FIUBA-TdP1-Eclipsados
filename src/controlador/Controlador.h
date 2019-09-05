/*
 * Controlador.h
 *
 *  Created on: Sep 3, 2019
 *      Author: franco
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_


#include "../modelo/Juego.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Controlador {
public:
	Controlador(Juego* juego);
	~Controlador();
	bool eventHandler();

private:
	Juego* juego;
};

#endif /* CONTROLADOR_H_ */
