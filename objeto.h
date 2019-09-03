#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
#include <stdio.h>
using namespace  std;
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "posicion.h"

class Object{
private:
		SDL_Rect dest;
		SDL_Rect src;
		SDL_Texture* tex;

		Posicion posicion;
public:
		Object(){}
			SDL_Rect getDest() const {return dest;}
			SDL_Rect getSource() const {return src;}
			SDL_Texture* getTex() const {return tex;}
			void setDest(int x, int y, int w, int h);
			void setSource(int x, int y, int w, int h);
			void setImage(string arch, SDL_Renderer *ren);

};

#endif //OBJETO_H


