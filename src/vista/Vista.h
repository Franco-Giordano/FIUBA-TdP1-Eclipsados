#ifndef VISTA_H_
#define VISTA_H_

#define WINDOW_SIZE_HORIZONTAL 800
#define WINDOW_SIZE_VERTICAL 800


#include "../modelo/Juego.h"
#include "../controlador/Controlador.h"


class Vista {
public:
	Vista(Juego* modelo, Controlador* controlador);
	virtual ~Vista();
	void update();
	void render();
	void Draw();
	void loop();

private:

	Juego* juego;
	Controlador* controlador;
	Personaje* jugador;
	SDL_Renderer* ren;
	SDL_Window* win;
	bool running;
	int FPS = 60;
	int frameCount;
	int frameDelay = 1000/FPS;
	int timerFPS;
	Uint32 frameStart;
	int posicionActual;
	int accionActual;
	int parado;
	int caminar;
	float posicionX;
	float posicionY;
};

#endif /* VISTA_H_ */
