/*
 * EntidadUbicada.cpp
 *
 *  Created on: Sep 5, 2019
 *      Author: franco
 */

#include "EntidadUbicada.h"


EntidadUbicada::EntidadUbicada(Dibujable* entidad) {
	// TODO Auto-generated constructor stub
	this->entidad = entidad;

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
