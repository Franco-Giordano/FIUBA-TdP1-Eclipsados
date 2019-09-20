#ifndef SRC_MODELO_ENTIDADUBICADA_ENTIDADUBICADA_H_
#define SRC_MODELO_ENTIDADUBICADA_ENTIDADUBICADA_H_

#include "dibujable/Dibujable.h"
#include "PosicionGlobal.h"


class EntidadUbicada {
public:
	EntidadUbicada(Dibujable* entidad);
	EntidadUbicada(Dibujable* entidad, float horizontal, float vertical);

	virtual ~EntidadUbicada();


	void moverGlobalIzquierda(){posicion.moverIzquierda();}
	void moverGlobalDerecha(){posicion.moverDerecha();}
	void moverGlobalArriba(){posicion.moverArriba();}
	void moverGlobalAbajo(){posicion.moverAbajo();}
	void moverGlobalSalto(){posicion.moverSalto();}
	void moverGlobalCaida(){posicion.moverCaida();}

	void moverLocalIzquierda(){entidad->moverIzquierda();}
	void moverLocalDerecha(){entidad->moverDerecha();}
	void moverLocalArriba(){entidad->moverArriba();}
	void moverLocalAbajo(){entidad->moverAbajo();}
	void moverLocalSalto(){entidad->moverSalto();}
	void moverLocalCaida(){entidad->moverCaida();}

	PosicionGlobal getPosicionGlobal();

	bool llegoBordeLocalDerecho(){return entidad->estaBordeDerecho();}
	bool llegoBordeLocalIzquierdo(){return entidad->estaBordeIzquierdo();}

	bool llegoBordeGlobalIzquierdo(){return posicion.estaBordeIzquierdo();}
	bool llegoBordeGlobalDerecho(){return posicion.estaBordeDerecho();}

	Dibujable* getDibujable(){return entidad;}

	int getHorizontalGlobal(){return posicion.getHorizontal();}

private:

	Dibujable* entidad;
	PosicionGlobal posicion;
};

#endif /* SRC_MODELO_ENTIDADUBICADA_ENTIDADUBICADA_H_ */
