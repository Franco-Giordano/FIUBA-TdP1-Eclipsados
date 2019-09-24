

#include "Nivel.h"

Nivel::Nivel(EntidadUbicada* jugador, int cantCuchillos, int cantCajas, int cantCanios, int cantBarriles, int cantEnemigos) {

	musicaFondo = new Sonido();
//	(*musicaFondo).play();

	cody = jugador;

	capa1.setVelocidad(VELOCIDAD_CODY);
	capa2.setVelocidad(2);
	capa3.setVelocidad(1);

	this->movimientoEnemigos = 0;


	this->ubicarEnemigosYElementos(cantCuchillos, cantCajas, cantCanios, cantBarriles, cantEnemigos);
}

Nivel::~Nivel() {
	//delete cody;
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

void Nivel::moverEnemigosIzquierda(){
	for (uint i = 0; i < enemigos.size(); i++){
		enemigos[i]->moverLocalIzquierda();
	}
}
void Nivel::moverEnemigosDerecha(){

	for (uint i = 0; i < enemigos.size(); i++){
		enemigos[i]->moverLocalDerecha();
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

void Nivel::terminoSalto(){
	cody->terminoLocalSalto();
	cody->terminoGlobalSalto();
}

void Nivel::movimientoAbajo(){
	cody->moverLocalAbajo();
	cody->moverGlobalAbajo();
}

void Nivel::movimientoIzquierda(){
	if (!cody->llegoBordeGlobalIzquierdo()){
		if (cody->llegoBordeLocalIzquierdo()){
			pos_borde_izquierda -= VELOCIDAD_CODY;
			pos_borde_derecha -= VELOCIDAD_CODY;
			moverCapasDerecha();
			moverElementosDerecha();
			moverEnemigosDerecha();
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
			moverEnemigosIzquierda();
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
/*
	EntidadUbicada* barril = factory.crearEntidadConBarril(300, JUGADOR_POSICION_VERTICAL_INICIAL+140);
	EntidadUbicada* caja = factory.crearEntidadConCaja(500, JUGADOR_POSICION_VERTICAL_INICIAL+140);
	EntidadUbicada* canio = factory.crearEntidadConCanio(700, JUGADOR_POSICION_VERTICAL_INICIAL+190);
	EntidadUbicada* cuchillo = factory.crearEntidadConCuchillo(900, JUGADOR_POSICION_VERTICAL_INICIAL+190);

	elementos.push_back(barril);
	elementos.push_back(caja);
	elementos.push_back(canio);
	elementos.push_back(cuchillo);
*/
	for(int i=0; i<cantCuchillos; i++){
		EntidadUbicada* cuchillo = factory.crearEntidadConCuchillo((200 + 20*i), JUGADOR_POSICION_VERTICAL_INICIAL+190);
		elementos.push_back(cuchillo);
	}
	for(int i=0; i<cantCanios; i++){
		EntidadUbicada* canio = factory.crearEntidadConCanio((400 + 20*i), JUGADOR_POSICION_VERTICAL_INICIAL+190);
		elementos.push_back(canio);
	}
	for(int i=0; i<cantCajas; i++){
		EntidadUbicada* caja = factory.crearEntidadConCaja((800 + 110*i), JUGADOR_POSICION_VERTICAL_INICIAL+140);
		elementos.push_back(caja);
	}

	for(int i=0; i<cantBarriles; i++){
		EntidadUbicada* barril = factory.crearEntidadConBarril((1500 + 110*i), JUGADOR_POSICION_VERTICAL_INICIAL+140);
		elementos.push_back(barril);
	}

	for(int i=0; i<cantEnemigos; i++){
		EntidadUbicada* enemigo = factory.crearEntidadConEnemigo((1000 + 300*i), JUGADOR_POSICION_VERTICAL_INICIAL);
		enemigos.push_back(enemigo);
	}
}

void Nivel::moverEnemigos(){
	if (movimientoEnemigos < 100){
		for (int i =0; i<enemigos.size(); i++){
			if (!enemigos[i]->llegoBordeGlobalIzquierdo()){

				enemigos[i]->moverGlobalIzquierda();
				enemigos[i]->moverLocalIzquierda();
			}
		}
		movimientoEnemigos+=1;
	}
	else{
		if(movimientoEnemigos >=100 && movimientoEnemigos <200){

			for (int i =0; i<enemigos.size(); i++){
				if (!enemigos[i]->llegoBordeGlobalDerecho()){

					enemigos[i]->moverGlobalDerecha();
					enemigos[i]->moverLocalDerecha();
				}
			}
			movimientoEnemigos++;
			}
		else{
			movimientoEnemigos = 0;
		}

	}



}
Personaje* Nivel::getPersonaje() {
	return (Personaje*)this->cody->getDibujable();
}

bool Nivel::terminoElNivel(){
	return cody->llegoBordeGlobalDerecho();
}

