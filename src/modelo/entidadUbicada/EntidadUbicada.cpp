/*
 * EntidadUbicada.cpp
 *
 *  Created on: Sep 5, 2019
 *      Author: franco
 */

#include "EntidadUbicada.h"


EntidadUbicada::EntidadUbicada(Dibujable* entidad) {

	this->entidad = entidad;

}


EntidadUbicada::EntidadUbicada(Dibujable* entidad, float horizontal, float vertical) {

	this->entidad = entidad;

	posicion.trasladarA(horizontal, vertical);
}

EntidadUbicada::~EntidadUbicada() {
	// TODO Auto-generated destructor stub
	delete this->entidad;
}

void EntidadUbicada::moverIzquierda() {
	this->posicion.moverIzquierda();
}

void EntidadUbicada::moverDerecha() {
	this->posicion.moverDerecha();
}

void EntidadUbicada::moverArriba() {
	this->posicion.moverArriba();
}

void EntidadUbicada::moverAbajo() {
	this->posicion.moverAbajo();
}

PosicionGlobal EntidadUbicada::getPosicionGlobal() {
	return posicion;
}
