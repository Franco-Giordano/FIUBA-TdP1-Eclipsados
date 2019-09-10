#include "PosicionGlobal.h"


PosicionGlobal::PosicionGlobal() {
	// Inicializacion harcodeada para tamaño de cody
	x = 0;
	y = WINDOW_SIZE_VERTICAL - 200;
	velocidad = 2.0;

}

/*
PosicionGlobal::PosicionGlobal(const PosicionGlobal &pos) {

	x = pos.x;
	y = pos.y;
	velocidad = pos.velocidad;

}
*/

PosicionGlobal::~PosicionGlobal() {
	// TODO Auto-generated destructor stub
}

// Todos los valores fueron calculados para el tamaño que ocupa Cody

void PosicionGlobal::moverArriba(){
	if(y > WINDOW_SIZE_VERTICAL - 280){
		y -= velocidad/2;
	}
}

void PosicionGlobal::moverAbajo(){
	if(y < WINDOW_SIZE_VERTICAL - 200){
		y += velocidad/2;
	}
}

void PosicionGlobal::moverIzquierda(){
	if(x > 100){
		x -= velocidad;
	}
}

void PosicionGlobal::moverDerecha(){
	if(x < WINDOW_SIZE_HORIZONTAL - 200){
		x += velocidad;
	}

}

float PosicionGlobal::getVertical() {
	return y;
}

float PosicionGlobal::getHorizontal() {
	return x;
}


float PosicionGlobal::getWindowSizeHorizontal(){
	return WINDOW_SIZE_HORIZONTAL;

}
bool PosicionGlobal::llegoCodyAlBordeDerecho(){
	return (x >= WINDOW_SIZE_HORIZONTAL - 200);
}

bool PosicionGlobal::llegoCodyAlBordeIzquierdo(){
	return (x <= 100);
}


void PosicionGlobal::trasladarA(float horizontal, float vertical) {
	x = horizontal;
	y = vertical;
}
