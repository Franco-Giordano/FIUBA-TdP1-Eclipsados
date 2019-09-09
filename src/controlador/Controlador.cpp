#include "Controlador.h"

Controlador::Controlador(Juego* juego) {
	// TODO Auto-generated constructor stub
	this->juego = juego;
	jugador = juego->getJugador();

}

Controlador::~Controlador() {
	// TODO Auto-generated destructor stub
}

void Controlador::setAccionActual(int acActual){

	accionActual = acActual;
}

void Controlador::setAcciones(int c, int p, int s, int sPatada, int g){

	caminar = c;
	parado = p;
	salto = s;
	saltoPatada = sPatada;
	golpear = g;
}


bool Controlador::eventHandler(){

	//actualizar el array de estados (para GetKeyboardState)
	SDL_PumpEvents();

	SDL_Event e;

	SDL_PollEvent(&e);

	bool running = true;

	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	if(keystates[SDL_SCANCODE_RIGHT]) {
		juego->movimientoDerecha();
		if(accionActual != caminar){
			jugador->setAnimacionActual(caminar);
		}
	}

	if(keystates[SDL_SCANCODE_LEFT]) {
		juego->movimientoIzquierda();
		if(accionActual != caminar){
			jugador->setAnimacionActual(caminar);
		}
	}

	if(keystates[SDL_SCANCODE_UP]) {
		juego->movimientoArriba();
		if(accionActual != caminar){
			jugador->setAnimacionActual(caminar);
		}
	}

	if(keystates[SDL_SCANCODE_DOWN]) {
		juego->movimientoAbajo();
		if(accionActual != caminar){
			jugador->setAnimacionActual(caminar);
		}
	}

	if(keystates[SDL_SCANCODE_DOWN]) {
		juego->movimientoAbajo();
		if(accionActual != caminar){
			jugador->setAnimacionActual(caminar);
		}
	}

	if(keystates[SDL_SCANCODE_RSHIFT]) {
		jugador->setAnimacionActual(golpear);
	}

	if(e.type == SDL_QUIT){
			running =false;
	}

	if(e.type == SDL_KEYUP){
		jugador->setAnimacionActual(parado);
	}

	return running;
}
