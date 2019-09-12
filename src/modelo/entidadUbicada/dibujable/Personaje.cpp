#include "Personaje.h"

Personaje::Personaje() {
	// TODO Auto-generated constructor stub

}


Personaje::~Personaje() {
	SDL_DestroyTexture(tex);
}


int Personaje::crearCiclo(int f, int w, int h, int cantSprites, int vel){
	cycle tmp;
	tmp.fil=f-1;
	tmp.w=w;
	tmp.cantSprites=cantSprites;
	tmp.vel=vel;
	tmp.tick=0;
	tmp.h = h;
	animaciones.push_back(tmp);
	return animaciones.size()-1;
}

void Personaje::setDest(int x, int y, int w, int h){
	dest.x=x;
	dest.y=y;
	dest.w=w;
	dest.h=h;

}

void Personaje::updateDest(int x, int y){
	dest.x=x;
	dest.y=y;
}
void Personaje::setSource(int x, int y, int w, int h){
	src.x=x;
	src.y=y;
	src.w=w;
	src.h=h;

}

void Personaje::setImage(SDL_Renderer* ren){

	SDL_Surface* surf = IMG_Load("SpriteCodyCompleto.png");
	tex = SDL_CreateTextureFromSurface(ren, surf);

}

void Personaje::updateAnim(){

	setSource(animaciones[animActual].w*animaciones[animActual].tick, animaciones[animActual].fil*animaciones[animActual].h, animaciones[animActual].w, animaciones[animActual].h);
	if(empezar>animaciones[animActual].vel){
		animaciones[animActual].tick++;
		empezar=0;
	}
	empezar++;
	if(animaciones[animActual].tick >= animaciones[animActual].cantSprites) {
		animaciones[animActual].tick = 0;
	}
}

bool Personaje::llegoAlBorde(int Xpos, int WindowSizeHorizontal){
	bool llegoAlBorde = false;

	if(Xpos <= 100){
		llegoAlBorde = false;
	}
	else if(Xpos >= WindowSizeHorizontal - 200 ){
		llegoAlBorde = false;
	}

	return llegoAlBorde;
}
