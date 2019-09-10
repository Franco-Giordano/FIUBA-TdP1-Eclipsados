#ifndef SRC_MODELO_ENTIDADUBICADA_ENTIDADUBICADA_H_
#define SRC_MODELO_ENTIDADUBICADA_ENTIDADUBICADA_H_

#include "dibujable/Dibujable.h"
#include "PosicionGlobal.h"


class EntidadUbicada {
public:
	EntidadUbicada(Dibujable* entidad);
	EntidadUbicada(Dibujable* entidad, float horizontal, float vertical);

	virtual ~EntidadUbicada();

	void moverIzquierda();
	void moverDerecha();
	void moverArriba();
	void moverAbajo();

	PosicionGlobal getPosicionGlobal();

private:
	Dibujable* entidad;
	PosicionGlobal posicion;
};

#endif /* SRC_MODELO_ENTIDADUBICADA_ENTIDADUBICADA_H_ */
