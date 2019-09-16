#include "Vista.h"


Vista::Vista(Juego* modelo, Controlador* controlador) {

	juego = modelo;
	this->controlador = controlador;
	this->jugador = juego->getJugador();

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_SIZE_HORIZONTAL, WINDOW_SIZE_VERTICAL, 0, &win, &ren);
	SDL_SetWindowTitle(win, "Final Fight");

	//personaje, interactua con modelo
	PosicionGlobal posicionJugador = juego->getPosicionJugador();

	posicionX = posicionJugador.getHorizontal();
	posicionY = posicionJugador.getVertical();

	jugador->setImage(ren);
	jugador->setDest(posicionX, WINDOW_SIZE_VERTICAL / 3 + posicionY, JUGADOR_SIZE_HORIZONTAL, JUGADOR_SIZE_VERTICAL);
	//jugador->setSource(posicionX, posicionY, 47, 98);

	parado = jugador->crearCiclo(1, 85, 120, 1, 10);
	caminar = jugador->crearCiclo(2, 85, 120, 12, 5);
	salto = jugador->crearCiclo(3, 85, 120, 8, 5);
	golpear = jugador->crearCiclo(4, 110, 120, 2, 5);
	saltoPatada = jugador->crearCiclo(5, 120, 120, 6, 5);


	accionActual = parado;
	jugador->setAnimacionActual(accionActual, SDL_FLIP_NONE);

	controlador->setAcciones(caminar, parado, salto, saltoPatada, golpear);
	controlador->setAccionActual(accionActual);

	//nivel = juego->getNivel();

	capa1 = juego->getCapa1();
	capa2 = juego->getCapa2();
	capa3 = juego->getCapa3();

	prepararCapa(capa1,"Nivel1-fondo1.png");
	prepararCapa(capa2,"Nivel1-fondo2.png");
	prepararCapa(capa3,"Nivel1-fondo3.png");

	loop();
}

void Vista::prepararCapa(Capa* capa,char const* imagen){
	capa->setImage(ren,imagen);
	capa->setSource(0,0,WINDOW_SIZE_HORIZONTAL -350,WINDOW_SIZE_VERTICAL);
	capa->setDest(0,0,WINDOW_SIZE_HORIZONTAL,WINDOW_SIZE_VERTICAL);
}

Vista::~Vista() {

	Mix_Quit();
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
    IMG_Quit();
	SDL_Quit();
}

void Vista::render() {

	SDL_RenderClear(ren);

	Draw();

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
	SDL_RenderCopyEx(ren, jugador->getTexture(), &sourceJugador, &destinationJugador, NULL, NULL, jugador->getFlip());

	//TODO: no se como meter la renderizacion de objetos/enemigos aca
	//deberia poderse buscar que objetos estan en la vista actual, y renderizarse solo esos

}


void Vista::update(){

	PosicionGlobal posicionJugador = juego->getPosicionJugador();
	posicionX = posicionJugador.getHorizontal();
	posicionY = posicionJugador.getVertical();
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


