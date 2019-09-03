/*
 * Juego.h
 *
 *  Created on: Sep 3, 2019
 *      Author: franco
 */

#ifndef JUEGO_H_
#define JUEGO_H_

#include "Personaje.h"

class Juego {
public:
	Juego();
	virtual ~Juego();
	void movimientoADerecha();
	void movimientoAIzquierda();
	int getPosicionJugador();
private:
	Personaje personaje;
};

#endif /* JUEGO_H_ */
