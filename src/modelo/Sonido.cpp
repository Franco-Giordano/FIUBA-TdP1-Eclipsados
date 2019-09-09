#include "Sonido.h"


Sonido::Sonido() {

		SDL_Init(SDL_INIT_AUDIO);
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		musicaFondoNivel1 = Mix_LoadMUS( "musica de fondo nivel 1.mp3" );

}

Sonido::~Sonido() {

    //Libero los efectos de sonido
    /*Mix_FreeChunk( gScratch );
    Mix_FreeChunk( gHigh );
    Mix_FreeChunk( gMedium );
    Mix_FreeChunk( gLow );*/

    //Libero la musica de fondo
    Mix_FreeMusic(musicaFondoNivel1);
    Mix_Quit();

}

void Sonido::play(){

	Mix_PlayMusic(musicaFondoNivel1, -1);
}

