

#include "posicion.h"

Posicion::Posicion() {
	x = 0.0;
	y = 0.0;
	movimiento = 5.0;

}

Posicion::~Posicion() {
	// TODO Auto-generated destructor stub
}

void Posicion::moverArriba(){
	y -= movimiento;
}

void Posicion::moverAbajo(){
	y += movimiento;
}

void Posicion::moverIzquierda(){
	x -= movimiento;
}

void Posicion::moverDerecha(){
	x += movimiento;
}
