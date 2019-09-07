#include "Vista.h"

Vista::Vista(Juego* modelo, Controlador* controlador) {

	juego = modelo;
	this->controlador = controlador;
	this->jugador = juego->getJugador();

	SDL_Init(0);
	//SDL_CreateWindow("Final Fight", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 360, 240, false);
	SDL_CreateWindowAndRenderer(WINDOW_SIZE_HORIZONTAL, WINDOW_SIZE_VERTICAL, 0, &win, &ren);
	SDL_SetWindowTitle(win, "Final Fight");

	//personaje, interactua con modelo
	PosicionGlobal posicionJugador = juego->getPosicionJugador();

	posicionX = posicionJugador.getHorizontal();
	posicionY = posicionJugador.getVertical();

	jugador->setImage(ren);
	jugador->setDest(posicionX, WINDOW_SIZE_VERTICAL / 3 + posicionY, 47, 98);
	jugador->setSource(posicionX, posicionY, 47, 98);
	parado = jugador->crearCiclo(1, 47, 98, 1, 15);
	caminar = jugador->crearCiclo(2, 47, 98, 6, 15);
	accionActual = parado;
	jugador->setAnimacionActual(accionActual);
	controlador->setAcciones(caminar, parado);
	controlador->setAccionActual(accionActual);

	loop();
}

Vista::~Vista() {
	// TODO Auto-generated destructor stub
}

void Vista::render() {

	//fondo
	SDL_SetRenderDrawColor(ren, 100, 100, 100, 255);
	SDL_Rect rect;
	rect.x=0;
	rect.y=0;
	rect.w=WINDOW_SIZE_HORIZONTAL;
	rect.h=WINDOW_SIZE_VERTICAL;
	SDL_RenderFillRect(ren, &rect);


	Draw();

	//por que se necesita este loop? ya hay otro similar en loop()
	frameCount++;
	int timerFPS = SDL_GetTicks()-frameStart;
	if(timerFPS < frameDelay){
		SDL_Delay(frameDelay-timerFPS);
	}

	SDL_RenderPresent(ren);


}

void Vista::Draw(){

	SDL_Rect dest = jugador->getDest();
	SDL_Rect src = jugador->getSource();
	SDL_RenderCopy(ren, jugador->getTexture(), &src, &dest);

}


void Vista::update(){
	// ?????????????????????????????
	// en este ejemplo no tiene sentido
	PosicionGlobal posicionJugador= juego->getPosicionJugador();
	posicionX = posicionJugador.getHorizontal();
	posicionY = posicionJugador.getVertical();
	jugador->setDest(posicionX, posicionY, 45, 95);
	jugador->updateAnim();

}


void Vista::loop() {

	//ciclo infinito de renderizacion
	while(running){

		frameStart=SDL_GetTicks();
		static int lastTime;

		render();

		//llamo a controlador a ver si toco alguna tecla
		running = controlador->eventHandler();

		update();

		if(frameDelay > lastTime){
			SDL_Delay(frameDelay - lastTime);
		}

	}
}


