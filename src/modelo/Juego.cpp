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
	nivel = new Nivel(entidad);

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
	nivel->movimientoArriba();
}

void Juego::movimientoSalto() {
	nivel->movimientoSalto();
}

void Juego::movimientoAbajo() {
	nivel->movimientoAbajo();
}

void Juego::movimientoCaida() {
	nivel->movimientoCaida();
}

void Juego::movimientoDerecha() {
	nivel->movimientoDerecha();
}


void Juego::movimientoIzquierda() {
	nivel->movimientoIzquierda();
}

Personaje* Juego::getJugador() {
	return (Personaje*)personaje;
}
