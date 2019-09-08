#ifndef SRC_VISTA_CAPA_H_
#define SRC_VISTA_CAPA_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Capa {
public:
	Capa();
	virtual ~Capa();

	SDL_Rect getDest() const {return dest;}
	SDL_Rect getSource() const {return src;}
	SDL_Texture* getTexture() const {return tex;}

	void setDest(int x, int y, int w, int h);
	void setSource(int x, int y, int w, int h);
	void setImage(SDL_Renderer *ren, char* imagen);

private:
	SDL_Rect dest;
	SDL_Rect src;
	SDL_Texture* tex;

	//char** imagenes = {"Nivel1-fondo1.png","Nivel1-fondo2.png","Nivel1-fondo3.png"};
};

#endif /* SRC_VISTA_CAPA_H_ */
