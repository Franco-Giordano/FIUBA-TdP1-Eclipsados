#include "Personaje.h"

Personaje::Personaje() {
	// TODO Auto-generated constructor stub
	posicion = 0;

}

void Personaje::moverDerecha() {
	posicion+= SPEED;
}

void Personaje::moverIzquierda() {
	posicion-= SPEED;
}

int Personaje::getPosicionGlobal() {
	return posicion;
}


Personaje::~Personaje() {
	// TODO Auto-generated destructor stub
}

int Personaje::crearCiclo(int f, int w, int h, int cantSprites, int vel){
	cycle tmp;
	tmp.fil=f-1;
	tmp.w=w;
	tmp.cantSprites=cantSprites;
	tmp.vel=vel;
	tmp.tick=0;
	animaciones.push_back(tmp);
	return animaciones.size()-1;
}

void Personaje::setDest(int x, int y, int w, int h){
	dest.x=x;
	dest.y=y;
	dest.w=w;
	dest.h=h;

}
void Personaje::setSource(int x, int y, int w, int h){
	src.x=x;
	src.y=y;
	src.w=w;
	src.h=h;

}

void Personaje::setImage(SDL_Renderer* ren){

	SDL_Surface* surf = IMG_Load("/home/notebook/eclipse-workspace/TP_Taller_Eclipsados/src/Cody.png");
	tex = SDL_CreateTextureFromSurface(ren, surf);

}

void Personaje::updateAnim(){

	setSource(animaciones[animActual].w*animaciones[animActual].tick, animaciones[animActual].fil*animaciones[animActual].h, animaciones[animActual].w, animaciones[animActual].h);
	if(empezar>animaciones[animActual].vel){
		empezar=0;
	}
	empezar++;
	if(animaciones[animActual].tick >= animaciones[animActual].cantSprites) {
		animaciones[animActual].tick = 0;
	}
	if(animaciones[animActual].tick <= 0){
		if(nAb){
			animActual = newAnim;
			nAb = 0;
			rev = 0;
		}else{
			animaciones[animActual].tick = 0;
		}
	}

}

