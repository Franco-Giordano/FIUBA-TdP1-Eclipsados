#include "vista/Vista.h"
#include "controlador/Controlador.h"
#include "Logger.h"

int main() {

	Logger logger(LogLevel::INFO);
        logger.log(LogLevel::ERROR, "Test ERROR: nivel incluido se logea");
        logger.log(LogLevel::INFO, "Test INFO: nivel incluido se logea");
        logger.log(LogLevel::DEBUG, "Test DEBUG: nivel excluido no se logea");

	//juego no hace mucho, solo encapsula Personaje
	Juego g;


	//solo inicializa variables, no hace nada
	Controlador controlador(&g);


	//vista se crea (ventana) y comienza a loopear para renderizar
	Vista vista(&g, &controlador);

	return 0;
}

