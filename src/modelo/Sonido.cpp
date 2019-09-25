#include "Sonido.h"
#include "../Logger.h"


Sonido::Sonido() {

    Logger::getInstance()->log(INFO, "Inicializando subsistema de sonido...");
		if ( SDL_Init(SDL_INIT_AUDIO) != 0)
        Logger::getInstance()->log(ERROR, SDL_GetError());

    Logger::getInstance()->log(INFO, "Inicializando mezclador...");
		if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        Logger::getInstance()->log(ERROR, Mix_GetError());

    Logger::getInstance()->log(INFO, "Cargando música de fondo: nivel 1...");
		musicaFondoNivel1 = Mix_LoadMUS( "/musica/Nivel1-musica.mp3" );
    if ( !musicaFondoNivel1 )
        Logger::getInstance()->log(ERROR, Mix_GetError());
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

  Logger::getInstance()->log(INFO, "Reproduciendo música de fondo: nivel 1...");
	if ( Mix_PlayMusic(musicaFondoNivel1, -1) == -1)
    Logger::getInstance()->log(ERROR, Mix_GetError());
}

