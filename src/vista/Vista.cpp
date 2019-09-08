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

	//En el constructor se llama a una funcion interna que corre todo el tiempo?
	loop();
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

	//Toda la parte del fondo se va a poner en un objeto externo

	//Primera capa
	SDL_Rect destinationFondo1;
	destinationFondo1.x=0;
	destinationFondo1.y= 0;
	destinationFondo1.w= WINDOW_SIZE_HORIZONTAL;
	destinationFondo1.h= WINDOW_SIZE_VERTICAL;

	SDL_Rect sourceFondo1;
	sourceFondo1.x=50;
	sourceFondo1.y=0;
	sourceFondo1.w= WINDOW_SIZE_HORIZONTAL -350;
	sourceFondo1.h= WINDOW_SIZE_VERTICAL;

	SDL_Texture * fondoTexture1;
	SDL_Surface* tmpsurf1 = IMG_Load("Nivel1-fondo1.png");
	fondoTexture1 = SDL_CreateTextureFromSurface(ren, tmpsurf1);
	SDL_FreeSurface(tmpsurf1);


/*

	//Segunda capa
	SDL_Rect destinationFondo2;
	destinationFondo2.x=0;
	destinationFondo2.y= 0;
	destinationFondo2.w= WINDOW_SIZE_HORIZONTAL;
	destinationFondo2.h= WINDOW_SIZE_VERTICAL;

	SDL_Rect sourceFondo2;
	sourceFondo2.x=50;
	sourceFondo2.y=0;
	sourceFondo2.w= WINDOW_SIZE_HORIZONTAL -350;
	sourceFondo2.h= WINDOW_SIZE_VERTICAL;

	SDL_Texture * fondoTexture2;
	SDL_Surface* tmpsurf2 = IMG_Load("Nivel1-fondo2.png");
	fondoTexture2 = SDL_CreateTextureFromSurface(ren, tmpsurf2);
	SDL_FreeSurface(tmpsurf2);



	//Tercera Capa
	SDL_Rect destinationFondo3;
	destinationFondo3.x=0;
	destinationFondo3.y= 0;
	destinationFondo3.w= WINDOW_SIZE_HORIZONTAL;
	destinationFondo3.h= WINDOW_SIZE_VERTICAL;

	SDL_Rect sourceFondo3;
	sourceFondo3.x=50;
	sourceFondo3.y=0;
	sourceFondo3.w= WINDOW_SIZE_HORIZONTAL -350;
	sourceFondo3.h= WINDOW_SIZE_VERTICAL;

	SDL_Texture * fondoTexture3;
	SDL_Surface* tmpsurf3 = IMG_Load("Nivel1-fondo3.png");
	fondoTexture3 = SDL_CreateTextureFromSurface(ren, tmpsurf3);
	SDL_FreeSurface(tmpsurf3);

*/

	// Cody
	SDL_Rect destinationJugador = jugador->getDest();
	SDL_Rect sourceJugador = jugador->getSource();

	//SDL_RenderCopy(ren, fondoTexture3, &sourceFondo3, &destinationFondo3);
	//SDL_RenderCopy(ren, fondoTexture2, &sourceFondo2, &destinationFondo2);
	SDL_RenderCopy(ren, fondoTexture1, &sourceFondo1, &destinationFondo1);
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


