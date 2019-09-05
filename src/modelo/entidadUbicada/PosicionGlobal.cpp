/*
 * PosicionGlobal.cpp
 *
 *  Created on: Sep 5, 2019
 *      Author: franco
 */

#include "PosicionGlobal.h"

PosicionGlobal::PosicionGlobal() {
	// TODO Auto-generated constructor stub
	x = 0.0;
	y = 0.0;
	velocidad = 5.0;

}


PosicionGlobal::PosicionGlobal(const PosicionGlobal &pos) {

	x = pos.x;
	y = pos.y;
	velocidad = pos.velocidad;

}

PosicionGlobal::~PosicionGlobal() {
	// TODO Auto-generated destructor stub
}

void PosicionGlobal::moverArriba(){
	y -= velocidad;
}

void PosicionGlobal::moverAbajo(){
	y += velocidad;
}

void PosicionGlobal::moverIzquierda(){
	x -= velocidad;
}

void PosicionGlobal::moverDerecha(){
	x += velocidad;
}

float PosicionGlobal::getVertical() {
	return y;
}

float PosicionGlobal::getHorizontal() {
	return x;
}

