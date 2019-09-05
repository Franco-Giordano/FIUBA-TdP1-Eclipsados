/*
 * PosicionGlobal.h
 *
 *  Created on: Sep 5, 2019
 *      Author: franco
 */

#ifndef SRC_MODELO_ENTIDADUBICADA_POSICIONGLOBAL_H_
#define SRC_MODELO_ENTIDADUBICADA_POSICIONGLOBAL_H_

class PosicionGlobal {
public:
	PosicionGlobal();
	virtual ~PosicionGlobal();

	//constructor de copia, no hace falta pero por las dudas
	PosicionGlobal(const PosicionGlobal &pos);

	void moverArriba();
	void moverAbajo();
	void moverIzquierda();
	void moverDerecha();

	//TODO: de momento seran gets, despues se puede usar una funcion que no viole encapsulamiento
	float getHorizontal();
	float getVertical();

private:
	float velocidad;
	float x;
	float y;
};

#endif /* SRC_MODELO_ENTIDADUBICADA_POSICIONGLOBAL_H_ */
