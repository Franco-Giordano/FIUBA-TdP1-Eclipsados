#include "Dibujable.h"

#include "../../../Logger.h"

Dibujable::Dibujable() {
	dest.x = JUGADOR_POSICION_HORIZONTAL_INICIAL;
	dest.y = JUGADOR_POSICION_VERTICAL_INICIAL;
	velocidadSalto = VELOCIDAD_SALTO_INICIAL;
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

void Dibujable::setImage(SDL_Renderer* ren, std::string imagen){

	this->imagen = imagen.c_str();

	SDL_Surface* surf = IMG_Load(this->imagen);

	if (surf == nullptr) {

	    tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 640);

	    Uint32 * pixels = new Uint32[640 * 640];

	    memset(pixels, 255, 640 * 640 * sizeof(Uint32));

	    SDL_UpdateTexture(tex, NULL, pixels, 640 * sizeof(Uint32));

	    Logger::getInstance()->log(ERROR, "No se encuentra el sprite '" + imagen + "', se mostrara una textura erronea.");
	}
	else
		tex = SDL_CreateTextureFromSurface(ren, surf);

}

void Dibujable::moverArriba(){
	if(dest.y > WINDOW_SIZE_VERTICAL - MARGEN_PISO_ARRIBA){
		dest.y -= VELOCIDAD_CODY/2;
	}
}

void Dibujable::moverAbajo(){
	if(dest.y < WINDOW_SIZE_VERTICAL - MARGEN_PISO_ABAJO){
		dest.y += VELOCIDAD_CODY/2;
	}
}

void Dibujable::moverSalto(){
	dest.y = dest.y - velocidadSalto * DELTA_T;
	velocidadSalto = velocidadSalto + DELTA_T * GRAVEDAD;
}

bool Dibujable::estaBordeDerecho(){
	return (dest.x >= WINDOW_SIZE_HORIZONTAL - MARGEN_DERECHO);
}
bool Dibujable::estaBordeIzquierdo(){
	return (dest.x <= MARGEN_IZQUIERDO);
}

