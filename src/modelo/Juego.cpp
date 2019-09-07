/*
 * Juego.cpp
 *
 *  Created on: Sep 3, 2019
 *      Author: franco
 */

#include "Juego.h"

Juego::Juego() {
	// TODO Auto-generated constructor stub

	personaje = new Personaje;

	this->entidad = new EntidadUbicada(personaje);


}

Juego::~Juego() {
	// TODO Auto-generated destructor stub
	delete entidad;
}

PosicionGlobal Juego::getPosicionJugador() {
	return entidad->getPosicionGlobal();
}

void Juego::movimientoArriba() {
	entidad->moverArriba();
}


void Juego::movimientoAbajo() {
	entidad->moverAbajo();
}

void Juego::movimientoDerecha() {
	entidad->moverDerecha();
}


void Juego::movimientoIzquierda() {
	entidad->moverIzquierda();
}

Personaje* Juego::getJugador() {
	return &jugador;
}
