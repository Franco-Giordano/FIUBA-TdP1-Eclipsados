#include "Controlador.h"

Controlador::Controlador(Juego* juego) {
	// TODO Auto-generated constructor stub
	this->juego = juego;
	jugador = juego->getJugador();
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

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

	if(keystates[SDL_SCANCODE_RIGHT] && !(keystates[SDL_SCANCODE_SPACE])) {
		juego->movimientoDerecha();
		spriteFlip = SDL_FLIP_NONE;
		if(accionActual != caminar){
			jugador->setAnimacionActual(caminar, spriteFlip);
			accionActual = caminar;
		}
	}

	if(keystates[SDL_SCANCODE_LEFT] && !(keystates[SDL_SCANCODE_SPACE])) {
		juego->movimientoIzquierda();
		spriteFlip = SDL_FLIP_HORIZONTAL;
		if(accionActual != caminar){
			jugador->setAnimacionActual(caminar, spriteFlip);
			accionActual = caminar;
		}
	}

	if(keystates[SDL_SCANCODE_UP]) {
		juego->movimientoArriba();
		//spriteFlip = SDL_FLIP_NONE;
		if(accionActual != caminar){
			jugador->setAnimacionActual(caminar, spriteFlip);
			accionActual = caminar;
		}
	}

	if(keystates[SDL_SCANCODE_DOWN]) {
		juego->movimientoAbajo();
		//spriteFlip = SDL_FLIP_NONE;
		if(accionActual != caminar){
			jugador->setAnimacionActual(caminar, spriteFlip);
			accionActual = caminar;
		}
	}

	if(keystates[SDL_SCANCODE_RIGHT] && keystates[SDL_SCANCODE_SPACE] && !(keystates[SDL_SCANCODE_RCTRL])) {
		juego->movimientoDerecha();
		spriteFlip = SDL_FLIP_NONE;
		if(accionActual != salto){
			jugador->setAnimacionActual(salto, spriteFlip);
			accionActual = salto;
		}
	}

	if(keystates[SDL_SCANCODE_RIGHT] && keystates[SDL_SCANCODE_SPACE] && keystates[SDL_SCANCODE_RCTRL]) {
		juego->movimientoDerecha();
		spriteFlip = SDL_FLIP_NONE;
		if(accionActual != saltoPatada){
			jugador->setAnimacionActual(saltoPatada, spriteFlip);
			accionActual = saltoPatada;
		}
	}

	if(keystates[SDL_SCANCODE_LEFT] && keystates[SDL_SCANCODE_SPACE] && !(keystates[SDL_SCANCODE_RCTRL])) {
		juego->movimientoIzquierda();
		spriteFlip = SDL_FLIP_HORIZONTAL;
		if(accionActual != salto){
			jugador->setAnimacionActual(salto, spriteFlip);
			accionActual = salto;
		}
	}

	if(keystates[SDL_SCANCODE_LEFT] && keystates[SDL_SCANCODE_SPACE] && keystates[SDL_SCANCODE_RCTRL]) {
		juego->movimientoIzquierda();
		spriteFlip = SDL_FLIP_HORIZONTAL;
		if(accionActual != saltoPatada){
			jugador->setAnimacionActual(saltoPatada, spriteFlip);
			accionActual = saltoPatada;
		}
	}

	if(keystates[SDL_SCANCODE_RSHIFT]) {
		if(accionActual != golpear){
			jugador->setAnimacionActual(golpear, spriteFlip);
			accionActual = golpear;
		}
	}

	if(keystates[SDL_SCANCODE_ESCAPE]) {
		running = false;
	}

	if(e.type == SDL_QUIT){
			running =false;
	}

	if(e.type == SDL_KEYUP){
		jugador->setAnimacionActual(parado, spriteFlip);
		accionActual = parado;
	}


	return running;
}
