/*
 * Dibujable.h
 *
 *  Created on: Sep 5, 2019
 *      Author: franco
 */

#ifndef SRC_MODELO_DIBUJABLE_H_
#define SRC_MODELO_DIBUJABLE_H_

class Dibujable {
public:
	virtual ~Dibujable() {};
	virtual int getPosicionGlobal() = 0;
	virtual void moverDerecha() = 0;
	virtual void moverIzquierda() = 0;
};

#endif /* SRC_MODELO_DIBUJABLE_H_ */
