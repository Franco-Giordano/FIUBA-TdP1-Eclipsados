#ifndef VISTA_H_
#define VISTA_H_

#include "../defs.h"
#include "../modelo/Juego.h"
#include "../controlador/Controlador.h"
#include "../modelo/nivel/Capa.h"
#include "../modelo/nivel/Nivel.h"

class Vista {
public:
	Vista(Juego* modelo, Controlador* controlador);
	virtual ~Vista();
	void update();
	void render();
	void Draw();
	void loop();

private:
	void prepararCapa(Capa* capa,char const* imagen);

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
	int salto;
	int saltoPatada;
	int golpear;
	int agachado;
	float posicionX;
	float posicionY;

	Capa* capa1;
	Capa* capa2;
	Capa* capa3;
	vector<EntidadUbicada*> elementos;
	//Nivel* nivel;

};

#endif /* VISTA_H_ */
