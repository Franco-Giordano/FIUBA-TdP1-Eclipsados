
#include "Capa.h"

Capa::Capa() {

}

Capa::~Capa() {

}

void Capa::setDest(int x, int y, int w, int h){
	dest.x=x;
	dest.y=y;
	dest.w=w;
	dest.h=h;

}
void Capa::setSource(int x, int y, int w, int h){
	src.x=x;
	src.y=y;
	src.w=w;
	src.h=h;

}
void Capa::setImage(SDL_Renderer* ren, char const * imagen){

	SDL_Surface* surf = IMG_Load(imagen);
	tex = SDL_CreateTextureFromSurface(ren, surf);

}

void Capa::moverDerecha(){
		src.x +=  velocidad;
}
void Capa::moverIzquierda(){
		src.x -=  velocidad;
}

bool Capa::llegoAlBordeDerecho(){
	if(src.x >= ANCHO_CAPA_PIXELES){
		return true;
	}
	return false;

}
bool Capa::llegoAlBordeIzquierdo(){
	if(src.x <= 0){
		return true;
	}
	return false;
}
