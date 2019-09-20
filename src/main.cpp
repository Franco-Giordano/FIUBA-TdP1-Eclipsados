#include "vista/Vista.h"
#include "controlador/Controlador.h"
#include "tinyxml2/tinyxml2.h"
#include "Logger.h"

#include "ParserXML.h"

#include <vector>

using namespace tinyxml2;

int main() {

	Logger logger(LogLevel::INFO);
        logger.log(LogLevel::ERROR, "Test ERROR: nivel incluido se logea");
        logger.log(LogLevel::INFO, "Test INFO: nivel incluido se logea");
        logger.log(LogLevel::DEBUG, "Test DEBUG: nivel excluido no se logea");


	int cantCuchillos = 0, cantBarriles = 0, cantEnemigos = 0, cantCanios = 0, cantCajas = 0;

	ParserXML parser("xmlCustom.xml");

	parser.parsearConfig(&cantEnemigos, &cantCuchillos, &cantCajas, &cantCanios, &cantBarriles);

	Juego g(cantCuchillos, cantCajas, cantCanios, cantBarriles, cantEnemigos);

	Controlador controlador(&g);

	AsignadorDeTexturas asignador = parser.getAsignador();
	//vista se crea (ventana) y comienza a loopear para renderizar
	Vista vista(&g, &controlador, asignador);

	return 0;
}

