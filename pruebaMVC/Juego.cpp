/*
 * Juego.cpp
 *
 *  Created on: Sep 3, 2019
 *      Author: franco
 */

#include "Juego.h"

Juego::Juego() {
	// TODO Auto-generated constructor stub
	Personaje personaje();

}

Juego::~Juego() {
	// TODO Auto-generated destructor stub

}

int Juego::getPosicionJugador() {
	return personaje.posicionActual();
}



void Juego::movimientoADerecha() {
	personaje.moverDerecha();
}


void Juego::movimientoAIzquierda() {
	personaje.moverIzquierda();
}
