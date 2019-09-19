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
	void setAcciones(int c, int p, int s, int sPatada, int g, int a);

private:
	Juego* juego;
	Personaje* jugador;
	SDL_RendererFlip spriteFlip;
	int caminar;
	int parado;
	int salto;
	int saltoPatada;
	int golpear;
	int agachado;
	int accionActual;
	bool saltando;
	bool saltandoDerecha;
	float alturaActualSalto;
	float alturaActualCaida;
	float alturaMaximaSalto;
	float alturaMaximaCaida;
};

#endif /* CONTROLADOR_H_ */
