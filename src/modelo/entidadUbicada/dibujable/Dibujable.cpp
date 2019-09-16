#include "Dibujable.h"

Dibujable::Dibujable() {
	// TODO Auto-generated constructor stub

}



void Dibujable::setDest(int x, int y, int w, int h){
	dest.x=x;
	dest.y=y;
	dest.w=w;
	dest.h=h;

}

void Dibujable::updateDest(int x, int y){
	dest.x=x;
	dest.y=y;
}
void Dibujable::setSource(int x, int y, int w, int h){
	src.x=x;
	src.y=y;
	src.w=w;
	src.h=h;

}

void Dibujable::setImage(SDL_Renderer* ren){

	SDL_Surface* surf = IMG_Load("SpriteCodyCompleto.png");
	tex = SDL_CreateTextureFromSurface(ren, surf);

}
