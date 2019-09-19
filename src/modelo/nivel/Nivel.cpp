

#include "Nivel.h"

Nivel::Nivel(EntidadUbicada* jugador, int cantCuchillos, int cantCajas, int cantCanios, int cantBarriles, int cantEnemigos) {

	musicaFondo = new Sonido();
//	(*musicaFondo).play();

	cody = jugador;

	capa1.setVelocidad(VELOCIDAD_CODY);
	capa2.setVelocidad(2);
	capa3.setVelocidad(1);

	this->ubicarEnemigosYElementos(cantCuchillos, cantCajas, cantCanios, cantBarriles, cantEnemigos);
}

Nivel::~Nivel() {
	delete cody;
	delete musicaFondo;

	for (uint i = 0; i < elementos.size(); i++) {
		delete elementos[i];
	}
}

void Nivel::moverElementosDerecha(){

	for (uint i = 0; i < elementos.size(); i++){
		elementos[i]->moverLocalDerecha();
	}
}
void Nivel::moverElementosIzquierda(){

	for (uint i = 0; i < elementos.size(); i++){
		elementos[i]->moverLocalIzquierda();
	}
}

void Nivel::movimientoArriba(){
	cody->moverLocalArriba();
	cody->moverGlobalArriba();
}

void Nivel::movimientoSalto(){
	cody->moverLocalSalto();
	cody->moverGlobalSalto();
}

void Nivel::movimientoAbajo(){
	cody->moverLocalAbajo();
	cody->moverGlobalAbajo();
}

void Nivel::movimientoCaida(){
	cody->moverLocalCaida();
	cody->moverGlobalCaida();
}

void Nivel::movimientoIzquierda(){
	if (!cody->llegoBordeGlobalIzquierdo()){
		if (cody->llegoBordeLocalIzquierdo()){
			pos_borde_izquierda -= VELOCIDAD_CODY;
			pos_borde_derecha -= VELOCIDAD_CODY;
			moverCapasDerecha();
			moverElementosDerecha();
		}else{
			cody->moverLocalIzquierda();
		}
		cody->moverGlobalIzquierda();


	}

}

void Nivel::movimientoDerecha(){
	if (!cody->llegoBordeGlobalDerecho()){
		if (cody->llegoBordeLocalDerecho()){
			pos_borde_derecha += VELOCIDAD_CODY;
			pos_borde_izquierda += VELOCIDAD_CODY;
			moverCapasIzquierda();
			moverElementosIzquierda();
		}else{
			cody->moverLocalDerecha();
		}

		cody->moverGlobalDerecha();


	}

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

void Nivel::ubicarEnemigosYElementos(int cantCuchillos, int cantCajas, int cantCanios, int cantBarriles, int cantEnemigos){

	FactoryEntidadUbicada factory;

	EntidadUbicada* barril = factory.crearEntidadConBarril(300, JUGADOR_POSICION_VERTICAL_INICIAL+140);
	EntidadUbicada* caja = factory.crearEntidadConCaja(500, JUGADOR_POSICION_VERTICAL_INICIAL+140);
	EntidadUbicada* canio = factory.crearEntidadConCanio(700, JUGADOR_POSICION_VERTICAL_INICIAL+190);
	EntidadUbicada* cuchillo = factory.crearEntidadConCuchillo(900, JUGADOR_POSICION_VERTICAL_INICIAL+190);

	elementos.push_back(barril);
	elementos.push_back(caja);
	elementos.push_back(canio);
	elementos.push_back(cuchillo);
}

Personaje* Nivel::getPersonaje() {
	return (Personaje*)this->cody->getDibujable();
}
