/*
 * Personaje.cpp
 *
 *  Created on: Sep 3, 2019
 *      Author: franco
 */

#include "Personaje.h"

Personaje::Personaje() {
	// TODO Auto-generated constructor stub
	posicion = 0;

}

void Personaje::moverDerecha() {
	posicion+= SPEED;
}

void Personaje::moverIzquierda() {
	posicion-= SPEED;
}

int Personaje::posicionActual() {
	return posicion;
}


Personaje::~Personaje() {
	// TODO Auto-generated destructor stub
}

