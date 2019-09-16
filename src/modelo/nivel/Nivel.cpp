

#include "Nivel.h"

Nivel::Nivel(EntidadUbicada* jugador) {

	musicaFondo = new Sonido();
//	(*musicaFondo).play();

	cody = jugador;

	capa1.setVelocidad(3);
	capa2.setVelocidad(2);
	capa3.setVelocidad(1);

	this->ubicarEnemigosYElementos(8, 10);
}

Nivel::~Nivel() {
	delete cody;
	delete musicaFondo;

	for (uint i = 0; i < elementos.size(); i++) {
		delete elementos[i];
	}
}

void Nivel::movimientoArriba(){
	cody->moverArriba();
}

void Nivel::movimientoAbajo(){
	cody->moverAbajo();
}

void Nivel::movimientoIzquierda(){
	cody->moverIzquierda();
	if(cody->llegoAlBordeIzquierdo()){
		moverCapasIzquierda();
	}
}

void Nivel::movimientoDerecha(){
	cody->moverDerecha();
	if(cody->llegoAlBordeDerecho()){
		moverCapasDerecha();
	}
}

void Nivel::setImagesCapas(SDL_Renderer *ren, char const* imagen1, char const* imagen2, char const* imagen3){
	capa1.setImage(ren,imagen1);
	capa2.setImage(ren,imagen2);
	capa3.setImage(ren,imagen3);
}


void Nivel::moverCapasDerecha(){
	if(!capa1.llegoAlBordeDerecho()){
		capa1.moverDerecha();
		capa2.moverDerecha();
		capa3.moverDerecha();
	}
}
void Nivel::moverCapasIzquierda(){
	if(!capa1.llegoAlBordeIzquierdo()){
		capa1.moverIzquierda();
		capa2.moverIzquierda();
		capa3.moverIzquierda();
	}
}

void Nivel::ubicarEnemigosYElementos(int cantEnemigos, int cantElementos){
	//cody = Cody();
/*
	for (int i = 0; i < (cantEnemigos + cantElementos); i++) {

	}*/

	FactoryEntidadUbicada factory;

	EntidadUbicada* barril = factory.crearEntidadConBarril(100, 100);
	EntidadUbicada* barril2 = factory.crearEntidadConBarril(75, 100);

	elementos.push_back(barril);
}

