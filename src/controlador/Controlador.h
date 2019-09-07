#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_


#include "../modelo/Juego.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Controlador {
public:
	Controlador(Juego* juego);
	~Controlador();
	bool eventHandler();

	void setAccionActual(int acActual);
	void setAcciones(int c, int p);

private:
	Juego* juego;
	Personaje* jugador;
	int caminar;
	int parado;
	int accionActual;
};

#endif /* CONTROLADOR_H_ */
