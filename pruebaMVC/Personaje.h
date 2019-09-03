/*
 * Personaje.h
 *
 *  Created on: Sep 3, 2019
 *      Author: franco
 */

#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#define SPEED 10

class Personaje {
private:
	int posicion;
public:
	Personaje();
	virtual ~Personaje();
	void moverDerecha();
	void moverIzquierda();
	int posicionActual();
};

#endif /* PERSONAJE_H_ */
