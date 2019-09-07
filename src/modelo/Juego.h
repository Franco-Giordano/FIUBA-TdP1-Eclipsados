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
	Personaje* getJugador();

	PosicionGlobal getPosicionJugador();
private:
	EntidadUbicada* entidad;
	Dibujable* personaje;
	Personaje jugador;
};

#endif /* JUEGO_H_ */
