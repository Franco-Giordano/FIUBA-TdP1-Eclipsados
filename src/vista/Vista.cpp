#include "Vista.h"

Vista::Vista(Juego* modelo, Controlador* controlador, AsignadorDeTexturas& unAsignador) {
	this->juego = modelo;
	this->controlador = controlador;
	this->asignador = unAsignador;
	this->running = true;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_SIZE_HORIZONTAL, WINDOW_SIZE_VERTICAL, 0, &win, &ren);
	SDL_SetWindowTitle(win, "Final Fight");

	inicializarVistaParaNivel();

	loop();
}

void Vista::inicializarVistaParaNivel(){

	this->jugador = juego->getJugador();


	//personaje, interactua con modelo
	PosicionGlobal* posicionJugador = juego->getPosicionJugador();

	posicionX = posicionJugador->getHorizontal();
	posicionY = posicionJugador->getVertical();

	jugador->setImageWith(asignador,ren);
	jugador->setDest(posicionX, posicionY, JUGADOR_SIZE_HORIZONTAL, JUGADOR_SIZE_VERTICAL); //TODO

	parado = jugador->crearCiclo(1, 85, 120, 1, 10);
	caminar = jugador->crearCiclo(2, 85, 120, 12, 5);
	salto = jugador->crearCiclo(3, 85, 120, 8, 8);
	golpear = jugador->crearCiclo(4, 110, 120, 2, 5);
	saltoPatada = jugador->crearCiclo(5, 120, 120, 6, 12);
	agachado = jugador->crearCiclo(1, 85, 120, 2, 5);
	saltoVertical = jugador->crearCiclo(6, 85, 120, 6, 12);


	accionActual = parado;
	jugador->setAnimacionActual(accionActual, SDL_FLIP_NONE);



	controlador->setAcciones(caminar, parado, salto, saltoPatada, golpear, agachado, saltoVertical);
	controlador->setAccionActual(accionActual);

	//nivel = juego->getNivel();

	capa1 = juego->getCapa1();
	capa2 = juego->getCapa2();
	capa3 = juego->getCapa3();

	prepararCapa(capa3, asignador.getNivel1()->at(2).c_str());
	prepararCapa(capa2, asignador.getNivel1()->at(1).c_str());
	prepararCapa(capa1, asignador.getNivel1()->at(0).c_str());

	//TODO: aca se preparia el segundo nivel? o donde


	elementos = juego->getElementos();
	enemigos = juego->getEnemigos();

	for (uint i = 0; i < elementos.size(); i++) {
		Dibujable* dibujable = elementos[i]->getDibujable();
		PosicionGlobal* posicion = elementos[i]->getPosicionGlobal();

		posicionX = posicion->getHorizontal();
		posicionY = posicion->getVertical();

		dibujable->setImageWith(asignador, ren);

//-->> Ojo que no todos van a tener las mismas dimensiones (source y dest cambian de acuredo al obj)
// -> solucion: cada objeto setea su source y se le pide el ancho y el alto para dibujarlo
		dibujable->setDest(posicionX, posicionY, dibujable->getWidth(),dibujable->getHeight());
		//dibujable->setSource(200, 190, 100, 100);
	}

	for (uint i = 0; i < enemigos.size(); i++) {
		Dibujable* dibujable = enemigos[i]->getDibujable();
		PosicionGlobal* posicion = enemigos[i]->getPosicionGlobal();

		posicionX = posicion->getHorizontal();
		posicionY = posicion->getVertical();

		dibujable->setImageWith(asignador, ren);

//-->> Ojo que no todos van a tener las mismas dimensiones (source y dest cambian de acuredo al obj)
// -> solucion: cada objeto setea su source y se le pide el ancho y el alto para dibujarlo
		dibujable->setDest(posicionX, posicionY, dibujable->getWidth()*2.2,dibujable->getHeight()*2.2);
		//dibujable->setSource(200, 190, 100, 100);

		Enemigo* enemigoActual = (Enemigo*) enemigos[i]->getDibujable();

		int caminarEnemigo = enemigoActual->crearCiclo(2, 100, 100, 6, 5);

		enemigoActual->setAnimacionActual(caminarEnemigo, SDL_FLIP_NONE);
	}
}

void Vista::prepararCapa(Capa* capa,char const* imagen){
	capa->setImage(ren,imagen);
	capa->setSource(0,0,ANCHO_CAPA_PIXELES ,WINDOW_SIZE_VERTICAL+10);
	capa->setDest(0,0,ANCHO_CAPA_PIXELES_ESCALADA,WINDOW_SIZE_VERTICAL+10);
}
void Vista::prepararSegundaCapa(Capa* capa,char const* imagen){
	capa->setImage(ren,imagen);
	capa->setSource(0,0,ANCHO_CAPA_PIXELES ,WINDOW_SIZE_VERTICAL+10);
	capa->setDest(0,0,ANCHO_CAPA_PIXELES_ESCALADA,WINDOW_SIZE_VERTICAL+10);
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

	for (uint i = 0; i < elementos.size(); i++) {
		Dibujable* dibujable = elementos[i]->getDibujable();
		SDL_Rect destinationElemento = dibujable->getDest();
		SDL_Rect sourceElemento = dibujable->getSource();

		SDL_RenderCopy(ren, dibujable->getTexture(), &sourceElemento, &destinationElemento);
	}

	for (uint i = 0; i < enemigos.size(); i++) {
		Dibujable* dibujable = enemigos[i]->getDibujable();
		SDL_Rect destinationEnemigo = dibujable->getDest();
		SDL_Rect sourceEnemigo = dibujable->getSource();
		Enemigo* enemigoActual = (Enemigo*) enemigos[i]->getDibujable();

		SDL_RenderCopyEx(ren, dibujable->getTexture(), &sourceEnemigo, &destinationEnemigo, 0, NULL, enemigoActual->getFlip());
	}

	SDL_RenderCopyEx(ren, jugador->getTexture(), &sourceJugador, &destinationJugador, 0, NULL, jugador->getFlip());
	//TODO: no se como meter la renderizacion de objetos/enemigos aca
	//deberia poderse buscar que objetos estan en la vista actual, y renderizarse solo esos

}


void Vista::update(){

	//PosicionGlobal posicionJugador = juego->getPosicionJugador();
	//posicionX = posicionJugador.getHorizontal();
	//posicionY = posicionJugador.getVertical();
	//jugador->updateDest(posicionX, posicionY);
	jugador->updateAnim();
	for (uint i = 0; i<enemigos.size();i++){
		Enemigo* enemigoActual = (Enemigo*) enemigos[i]->getDibujable();
		enemigoActual->updateAnim();
	}

}


void Vista::loop() {

	//ciclo infinito de renderizacion
	while(running){

		frameStart=SDL_GetTicks();
		static int lastTime;

		render();

		//llamo a controlador a ver si toco alguna tecla
		running = controlador->eventHandler();
		juego->moverEnemigos();

		if(juego->terminoElNivel()){

			juego->cambiarDeNivel();
			inicializarVistaParaNivel();
			prepararSegundaCapa(capa3, asignador.getNivel2()->at(2).c_str());
			prepararSegundaCapa(capa2, asignador.getNivel2()->at(1).c_str());
			prepararSegundaCapa(capa1, asignador.getNivel2()->at(0).c_str());

		}

		update();

		if(frameDelay > lastTime){
			SDL_Delay(frameDelay - lastTime);
		}

	}
}
