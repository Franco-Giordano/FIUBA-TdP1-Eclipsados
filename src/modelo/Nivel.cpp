

#include "Nivel.h"

Nivel::Nivel() {

	musicaFondo = new Sonido();
	(*musicaFondo).play();

	cody = factory.crearEntidadConPersonaje();

	capa1.setVelocidad(3);
	capa2.setVelocidad(2);
	capa3.setVelocidad(1);


}

Nivel::~Nivel() {
	delete cody;
	delete musicaFondo;
}

void Nivel::movimientoArriba(){
	cody->moverArriba();
}

void Nivel::movimientoAbajo(){
	cody->moverAbajo();
}

void Nivel::movimientoIzquierda(){
	cody->moverIzquierda();
	moverCapasIzquierda();
}

void Nivel::movimientoDerecha(){
	cody->moverDerecha();
	moverCapasDerecha();
}

void Nivel::setImagesCapas(SDL_Renderer *ren, char const* imagen1, char const* imagen2, char const* imagen3){
	capa1.setImage(ren,imagen1);
	capa2.setImage(ren,imagen2);
	capa3.setImage(ren,imagen3);
}


void Nivel::moverCapasDerecha(){
	capa1.moverDerecha();
	capa2.moverDerecha();
	capa3.moverDerecha();
}
void Nivel::moverCapasIzquierda(){
	capa1.moverIzquierda();
	capa2.moverIzquierda();
	capa3.moverIzquierda();
}

void Nivel::inicializarObjetos(){
	//cody = Cody();
}

