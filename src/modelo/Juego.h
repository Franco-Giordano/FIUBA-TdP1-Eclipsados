#ifndef JUEGO_H_
#define JUEGO_H_

#include "entidadUbicada/EntidadUbicada.h"
#include "entidadUbicada/dibujable/Personaje.h"
#include "nivel/Nivel.h"

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


	Capa* getCapa1(){return nivel->getCapa1();}
	Capa* getCapa2(){return nivel->getCapa2();}
	Capa* getCapa3(){return nivel->getCapa3();}

private:
	EntidadUbicada* entidad;
	Dibujable* personaje;
	Nivel* nivel;
};

#endif /* JUEGO_H_ */
