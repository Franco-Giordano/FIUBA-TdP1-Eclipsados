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
	//jugador->setDest(posicionX, WINDOW_SIZE_VERTICAL / 3 + posicionY, 47, 98);
	jugador->setDest(posicionX, WINDOW_SIZE_VERTICAL / 3 + posicionY, JUGADOR_SIZE_HORIZONTAL, JUGADOR_SIZE_VERTICAL);
	jugador->setSource(posicionX, posicionY, 47, 98);
	parado = jugador->crearCiclo(1, 47, 98, 1, 15);
	caminar = jugador->crearCiclo(2, 47, 98, 6, 15);
	accionActual = parado;
	jugador->setAnimacionActual(accionActual);
	controlador->setAcciones(caminar, parado);
	controlador->setAccionActual(accionActual);

	nivel = juego->getNivel();

	capa1 = nivel->getCapa1();
	capa2 = nivel->getCapa2();
	capa3 = nivel->getCapa3();

	prepararCapa(capa1,"Nivel1-fondo1.png");
	prepararCapa(capa2,"Nivel1-fondo2.png");
	prepararCapa(capa3,"Nivel1-fondo3.png");

	loop();
}

void Vista::prepararCapa(Capa* capa,char const* imagen){
	capa->setImage(ren,imagen);
	capa->setSource(50,0,WINDOW_SIZE_HORIZONTAL -350,WINDOW_SIZE_VERTICAL);
	capa->setDest(0,0,WINDOW_SIZE_HORIZONTAL,WINDOW_SIZE_VERTICAL);
}

Vista::~Vista() {
	// TODO Auto-generated destructor stub
}

void Vista::render() {
	SDL_RenderClear(ren);

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

	// Capa1
	SDL_Rect destinationFondo1 = capa1->getDest();
	SDL_Rect sourceFondo1 = capa1->getSource();

	// Capa2
	SDL_Rect destinationFondo2 = capa2->getDest();
	SDL_Rect sourceFondo2 = capa2->getSource();

	// Capa3
	SDL_Rect destinationFondo3 = capa3->getDest();
	SDL_Rect sourceFondo3 = capa3->getSource();

	// Cody
	SDL_Rect destinationJugador = jugador->getDest();
	SDL_Rect sourceJugador = jugador->getSource();


	SDL_RenderCopy(ren, capa3->getTexture(), &sourceFondo3, &destinationFondo3);
	SDL_RenderCopy(ren, capa2->getTexture(), &sourceFondo2, &destinationFondo2);
	SDL_RenderCopy(ren, capa1->getTexture(), &sourceFondo1, &destinationFondo1);
	SDL_RenderCopy(ren, jugador->getTexture(), &sourceJugador, &destinationJugador);

}


void Vista::update(){
	// ?????????????????????????????
	// en este ejemplo no tiene sentido
	PosicionGlobal posicionJugador= juego->getPosicionJugador();
	posicionX = posicionJugador.getHorizontal();
	posicionY = posicionJugador.getVertical();
	//jugador->setDest(posicionX, posicionY, 45, 95);
	jugador->updateDest(posicionX, posicionY);
	jugador->updateAnim();

}


void Vista::loop() {

	//El loop deberia estar fuera de su propia clase!!! -> la clase se 'automaneja'

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


