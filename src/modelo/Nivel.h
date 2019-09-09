

#ifndef NIVEL_H_
#define NIVEL_H_



#include <stdio.h>
#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Capa.h"
#include "entidadUbicada/EntidadUbicada.h"
#include "entidadUbicada/FactoryEntidadUbicada.h"

//#include "cody.h"

class Nivel {
public:
	Nivel();
	virtual ~Nivel();
	void inicializarObjetos();

	void setImagesCapas(SDL_Renderer *ren, char const* imagen1, char const* imagen2, char const* imagen3);

	void movimientoArriba();
	void movimientoAbajo();
	void movimientoIzquierda();
	void movimientoDerecha();

	Capa* getCapa1(){return &capa1;}
	Capa* getCapa2(){return &capa2;}
	Capa* getCapa3(){return &capa3;}

private:
	void moverCapasDerecha();
	void moverCapasIzquierda();

	void inicializarCapa(Capa capa);

	FactoryEntidadUbicada factory;

	std::vector<EntidadUbicada> entidades;
	EntidadUbicada* cody;
	Capa capa1;
	Capa capa2;
	Capa capa3;
	//Cody cody;


};
#endif /* NIVEL_H_ */
