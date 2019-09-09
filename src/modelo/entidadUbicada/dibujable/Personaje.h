#ifndef PERSONAJE_H_
#define PERSONAJE_H_
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace  std;
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#define SPEED 10

#include "Dibujable.h"

class Personaje : public Dibujable {
private:
	struct cycle {
		int fil;
		int w;
		int h;
		int cantSprites;
		int vel;
		int tick;
	};
	vector<cycle> animaciones;
	SDL_Texture* tex;
	SDL_Rect dest;
	SDL_Rect src;
	int animActual;
	int empezar;
	bool rev,nAb;
	int newAnim;

public:
	Personaje();
	virtual ~Personaje();

	int crearCiclo(int f, int w, int h, int cant, int vel);
	void setAnimacionActual(int c) {empezar = 0; animActual = c;}
	void updateAnim();
	void updateDest(int x, int y);
	SDL_Rect getDest() const {return dest;}
	SDL_Rect getSource() const {return src;}
	SDL_Texture* getTexture() const {return tex;}
	void setDest(int x, int y, int w, int h);
	void setSource(int x, int y, int w, int h);
	void setImage(SDL_Renderer *ren);
	//void reverse(bool reverse){rev = reverse;}
	//void reverse(bool reverse, int animDefault){rev = reverse;}
};

#endif /* PERSONAJE_H_ */
