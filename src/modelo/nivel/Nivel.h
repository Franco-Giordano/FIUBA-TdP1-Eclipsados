#ifndef NIVEL_H_
#define NIVEL_H_



#include <stdio.h>
#include <vector>
#include "../Sonido.h"
#include "../entidadUbicada/EntidadUbicada.h"
#include "../entidadUbicada/FactoryEntidadUbicada.h"
#include "../nivel/Capa.h"

//#include "cody.h"

class Nivel {
public:
	Nivel(EntidadUbicada* jugador);
	virtual ~Nivel();
	void ubicarEnemigosYElementos(int cantEnemigos, int cantElementos);

	void setImagesCapas(SDL_Renderer *ren, char const* imagen1, char const* imagen2, char const* imagen3);

	void movimientoArriba();
	void movimientoAbajo();
	void movimientoIzquierda();
	void movimientoDerecha();
	void movimientoSalto();
	void movimientoCaida();

	Capa* getCapa1(){return &capa1;}
	Capa* getCapa2(){return &capa2;}
	Capa* getCapa3(){return &capa3;}

	vector<EntidadUbicada*> getElementos(){return elementos;}

private:
	void moverCapasDerecha();
	void moverCapasIzquierda();
	void moverElementosIzquierda();
	void moverElementosDerecha();

	void inicializarCapa(Capa capa);

	FactoryEntidadUbicada factory;

	std::vector<EntidadUbicada*> enemigos;
	std::vector<EntidadUbicada*> elementos;

	EntidadUbicada* cody;

	Capa capa1;
	Capa capa2;
	Capa capa3;
	//Cody cody;

	int pos_borde_izquierda = 0;
	int pos_borde_derecha = WINDOW_SIZE_HORIZONTAL;

	Sonido *musicaFondo;


};
#endif /* NIVEL_H_ */
