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
	nivel = new Nivel;
	this->entidad = new EntidadUbicada(personaje);


}

Juego::~Juego() {
	// TODO Auto-generated destructor stub
	delete entidad;
	delete nivel;
}

PosicionGlobal Juego::getPosicionJugador() {
	return entidad->getPosicionGlobal();
}

void Juego::movimientoArriba() {
	entidad->moverArriba();
	nivel->movimientoArriba();
}


void Juego::movimientoAbajo() {
	entidad->moverAbajo();
	nivel->movimientoAbajo();
}

void Juego::movimientoDerecha() {
	entidad->moverDerecha();
	nivel->movimientoDerecha();
}


void Juego::movimientoIzquierda() {
	entidad->moverIzquierda();
	nivel->movimientoIzquierda();
}

Personaje* Juego::getJugador() {
	return (Personaje*)personaje;
}
