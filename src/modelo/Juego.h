#ifndef JUEGO_H_
#define JUEGO_H_

#include "entidadUbicada/EntidadUbicada.h"
#include "entidadUbicada/dibujable/Personaje.h"
#include "Nivel.h"

class Juego {
public:
	Juego();
	virtual ~Juego();

	void movimientoDerecha();
	void movimientoIzquierda();
	void movimientoArriba();
	void movimientoAbajo();

	Personaje* getJugador();

	PosicionGlobal getPosicionJugador();

	Nivel* getNivel(){return nivel;}

private:
	EntidadUbicada* entidad;
	Dibujable* personaje;
	Nivel* nivel;
};

#endif /* JUEGO_H_ */
