#include "Controlador.h"

Controlador::Controlador(Juego* juego) {
	// TODO Auto-generated constructor stub
	this->juego = juego;
	jugador = juego->getJugador();
	spriteFlip = SDL_FLIP_NONE;
	saltando = false;
	golpeando = false;
	agachando = false;

}

Controlador::~Controlador() {
	// TODO Auto-generated destructor stub
}

void Controlador::setAccionActual(int acActual){

	accionActual = acActual;
}

void Controlador::setAcciones(int c, int p, int s, int sPatada, int g, int a, int sV){

	caminar = c;
	parado = p;
	salto = s;
	saltoPatada = sPatada;
	golpear = g;
	agachado = a;
	saltoVertical = sV;
}

void Controlador::resetearAnimaciones(){
	this->golpeando = false;
	this->saltando = false;
	this->agachando = false;
	this->alturaActualSalto = juego->getPosicionJugador()->getVertical();
	this->alturaMaximaSalto = juego->getPosicionJugador()->getVertical()+25;
}

bool Controlador::eventHandler(){

	//actualizar el array de estados (para GetKeyboardState)
	SDL_PumpEvents();

	SDL_Event e;

	SDL_PollEvent(&e);

	bool running = true;

	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	if(!saltando){

		if(keystates[SDL_SCANCODE_RIGHT] && !(keystates[SDL_SCANCODE_SPACE]) && !golpeando && !agachando) {
			juego->movimientoDerecha();
			spriteFlip = SDL_FLIP_NONE;
			if(accionActual != caminar){
				jugador->setAnimacionActual(caminar, spriteFlip);
				accionActual = caminar;
				}
			}

		if(keystates[SDL_SCANCODE_LEFT] && !(keystates[SDL_SCANCODE_SPACE]) && !golpeando && !agachando) {
			juego->movimientoIzquierda();
			spriteFlip = SDL_FLIP_HORIZONTAL;
			if(accionActual != caminar){
				jugador->setAnimacionActual(caminar, spriteFlip);
				accionActual = caminar;
			}
		}

		if(keystates[SDL_SCANCODE_UP] && !golpeando && !agachando) {
			juego->movimientoArriba();
			if(accionActual != caminar){
				jugador->setAnimacionActual(caminar, spriteFlip);
				accionActual = caminar;
			}
		}

		if(keystates[SDL_SCANCODE_DOWN] && !golpeando && !agachando) {
			juego->movimientoAbajo();
			if(accionActual != caminar){
				jugador->setAnimacionActual(caminar, spriteFlip);
				accionActual = caminar;
			}
		}

		if(keystates[SDL_SCANCODE_SPACE] && !golpeando && !agachando) {
			saltando = true;
			tipoSalto = 0;
			alturaActualSalto = juego->getPosicionJugador()->getVertical();
			alturaMaximaSalto = juego->getPosicionJugador()->getVertical()+25;
			if(accionActual != saltoVertical){
				jugador->setAnimacionActual(saltoVertical, spriteFlip);
				accionActual = saltoVertical;
			}
		}

		if(keystates[SDL_SCANCODE_RIGHT] && keystates[SDL_SCANCODE_SPACE] && !(keystates[SDL_SCANCODE_RCTRL]) && !golpeando && !agachando) {
			saltando = true;
			tipoSalto = 1;
			alturaActualSalto = juego->getPosicionJugador()->getVertical();
			alturaMaximaSalto = juego->getPosicionJugador()->getVertical()+25;
			spriteFlip = SDL_FLIP_NONE;
			if(accionActual != salto){
				jugador->setAnimacionActual(salto, spriteFlip);
				accionActual = salto;
			}
		}

		if(keystates[SDL_SCANCODE_RIGHT] && keystates[SDL_SCANCODE_SPACE] && keystates[SDL_SCANCODE_RCTRL] && !golpeando && !agachando) {
			saltando = true;
			tipoSalto = 1;
			alturaActualSalto = juego->getPosicionJugador()->getVertical();
			alturaMaximaSalto = juego->getPosicionJugador()->getVertical()+25;
			spriteFlip = SDL_FLIP_NONE;
			if(accionActual != saltoPatada){
				jugador->setAnimacionActual(saltoPatada, spriteFlip);
				accionActual = saltoPatada;
			}
		}

		if(keystates[SDL_SCANCODE_LEFT] && keystates[SDL_SCANCODE_SPACE] && !(keystates[SDL_SCANCODE_RCTRL]) && !golpeando && !agachando) {
			saltando = true;
			tipoSalto = 2;
			alturaActualSalto = juego->getPosicionJugador()->getVertical();
			alturaMaximaSalto = juego->getPosicionJugador()->getVertical()+25;
			spriteFlip = SDL_FLIP_HORIZONTAL;
			if(accionActual != salto){
				jugador->setAnimacionActual(salto, spriteFlip);
				accionActual = salto;
			}
		}

		if(keystates[SDL_SCANCODE_LEFT] && keystates[SDL_SCANCODE_SPACE] && keystates[SDL_SCANCODE_RCTRL] && !golpeando && !agachando) {
			saltando = true;
			tipoSalto = 2;
			alturaActualSalto = juego->getPosicionJugador()->getVertical();
			alturaMaximaSalto = juego->getPosicionJugador()->getVertical()+25;
			spriteFlip = SDL_FLIP_HORIZONTAL;
			if(accionActual != saltoPatada){
				jugador->setAnimacionActual(saltoPatada, spriteFlip);
				accionActual = saltoPatada;
			}
		}

		if(keystates[SDL_SCANCODE_RSHIFT] && !saltando && !agachando) {
			golpeando = true;
			if(accionActual != golpear){
				jugador->setAnimacionActual(golpear, spriteFlip);
				accionActual = golpear;
			}
		}

		if((7 - jugador->getTicks()) < 0 && golpeando){
			golpeando = false;
			jugador->setAnimacionActual(parado, spriteFlip);
			accionActual = parado;
		}

		if(keystates[SDL_SCANCODE_RALT] && !(keystates[SDL_SCANCODE_SPACE]) && !golpeando) {
				if(accionActual != agachado){
					jugador->setAnimacionActual(agachado, spriteFlip);
					accionActual = agachado;
					agachando = true;
				}
			}
		if((2 - jugador->getTicks()) < 0 && agachando){
				agachando = false;
				jugador->setAnimacionActual(parado, spriteFlip);
				accionActual = parado;
		}

		if(keystates[SDL_SCANCODE_ESCAPE]) {
			running = false;
		}

		if(e.type == SDL_QUIT){
				running =false;
		}

		if(e.type == SDL_KEYUP && !golpeando && !agachando){
			jugador->setAnimacionActual(parado, spriteFlip);
			accionActual = parado;
		}


		return running;
	}
	if(alturaActualSalto < alturaMaximaSalto ){
		juego->movimientoSalto();
		alturaActualSalto = juego->getPosicionJugador()->getVertical();
		switch(tipoSalto){
			case 0: return running;						//Salta en vertical
			break;
			case 1: juego->movimientoDerecha();
			break;
			case 2: juego->movimientoIzquierda();
			break;
		}
		return running;
	}
	juego->terminadoSalto();
	saltando = false;
	accionActual = parado;
	jugador->setAnimacionActual(accionActual, spriteFlip);
	return running;
}
