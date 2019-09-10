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

EntidadUbicada::~EntidadUbicada() {
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

//Las siguientes dos funciones estan diseñadas solo para Cody --> generalizar
bool EntidadUbicada::llegoAlBordeDerecho(){
	return posicion.llegoCodyAlBordeDerecho();
}

bool EntidadUbicada::llegoAlBordeIzquierdo(){
	return posicion.llegoCodyAlBordeIzquierdo();
}
