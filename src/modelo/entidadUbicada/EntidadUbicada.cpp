#include "EntidadUbicada.h"


EntidadUbicada::EntidadUbicada(Dibujable* entidad) {
	this->entidad = entidad;

}


EntidadUbicada::EntidadUbicada(Dibujable* entidad, float horizontal, float vertical) {

	this->entidad = entidad;

	posicion.trasladarA(horizontal, vertical);
}

EntidadUbicada::~EntidadUbicada() {
	//delete this->entidad;
}



PosicionGlobal EntidadUbicada::getPosicionGlobal() {
	return posicion;
}

//Las siguientes dos funciones estan diseñadas solo para Cody --> generalizar

