/*
 * FactoryEntidadUbicada.cpp
 *
 *  Created on: Sep 9, 2019
 *      Author: franco
 */

#include "FactoryEntidadUbicada.h"

FactoryEntidadUbicada::FactoryEntidadUbicada() {
	// TODO Auto-generated constructor stub

}

FactoryEntidadUbicada::~FactoryEntidadUbicada() {
	// TODO Auto-generated destructor stub
}


EntidadUbicada* FactoryEntidadUbicada::crearEntidadConPersonaje() {
	Dibujable* personaje = new Personaje;
	return new EntidadUbicada(personaje);
}

EntidadUbicada* FactoryEntidadUbicada::crearEntidadConEnemigo() {
	Dibujable* enemigo = new Enemigo;
	return new EntidadUbicada(enemigo);
}

EntidadUbicada* FactoryEntidadUbicada::crearEntidadConBarril() {
	Dibujable* barril = new Barril;
	return new EntidadUbicada(barril);
}


EntidadUbicada* FactoryEntidadUbicada::crearEntidadConBarril(float horizontal, float vertical) {
	Dibujable* barril = new Barril;
	return new EntidadUbicada(barril, horizontal, vertical);
}

EntidadUbicada* FactoryEntidadUbicada::crearEntidadConCuchillo() {
	Dibujable* cuchillo= new Cuchillo;
	return new EntidadUbicada(cuchillo);
}

EntidadUbicada* FactoryEntidadUbicada::crearEntidadConCanio() {
	Dibujable* canio = new CanioMetalico;
	return new EntidadUbicada(canio);
}


EntidadUbicada* FactoryEntidadUbicada::crearEntidadConCaja() {
	Dibujable* caja = new Caja;
	return new EntidadUbicada(caja);
}
