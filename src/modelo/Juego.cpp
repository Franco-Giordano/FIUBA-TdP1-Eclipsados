/*
 * Juego.cpp
 *
 *  Created on: Sep 3, 2019
 *      Author: franco
 */

#include "Juego.h"

Juego::Juego(int cantCuchillos, int cantCajas, int cantCanios, int cantBarriles, int cantEnemigos) {

	Dibujable*  personaje = new Personaje;
	this->entidad = new EntidadUbicada(personaje);
	nivel = new Nivel(entidad, cantCuchillos, cantCajas, cantCanios, cantBarriles, cantEnemigos);

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
	return nivel->getPersonaje();
}
