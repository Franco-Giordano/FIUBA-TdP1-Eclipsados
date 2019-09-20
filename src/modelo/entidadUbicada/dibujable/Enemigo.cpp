/*
 * Enemigo.cpp
 *
 *  Created on: Sep 5, 2019
 *      Author: franco
 */

#include "Enemigo.h"

Enemigo::Enemigo() {
	// TODO Auto-generated constructor stub

}

Enemigo::~Enemigo() {
	// TODO Auto-generated destructor stub
}

void Enemigo::setImageWith(AsignadorDeTexturas& asignador, SDL_Renderer* ren) {
	asignador.setTexture(*this, ren);
}


