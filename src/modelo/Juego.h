/*
 * Juego.h
 *
 *  Created on: Sep 3, 2019
 *      Author: franco
 */

#ifndef JUEGO_H_
#define JUEGO_H_

#include "entidadUbicada/EntidadUbicada.h"
#include "entidadUbicada/dibujable/Personaje.h"


class Juego {
public:
	Juego();
	virtual ~Juego();

	void movimientoDerecha();
	void movimientoIzquierda();
	void movimientoArriba();
	void movimientoAbajo();

	PosicionGlobal getPosicionJugador();
private:
	EntidadUbicada* entidad;
};

#endif /* JUEGO_H_ */
