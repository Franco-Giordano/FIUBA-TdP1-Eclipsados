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

	//juego no hace mucho, solo encapsula Personaje
	Juego g;


	int cantCuchillos = 0, cantBarriles = 0, cantEnemigos = 0, cantCanios = 0, cantCajas = 0;

	ParserXML parser("xmlDefault.xml");

	parser.parsearConfig(&cantEnemigos, &cantCuchillos, &cantCajas, &cantCanios, &cantBarriles);


	//********** TESTEO
	std::cout << cantBarriles << cantCajas << cantCanios << cantCuchillos << cantEnemigos << std::endl;
	//********* FIN TESTEO


	Juego g(cantCuchillos, cantCajas, cantCanios, cantBarriles, cantEnemigos);

	Controlador controlador(&g);

	AsignadorDeTexturas asignador = parser.getAsignador();
	//vista se crea (ventana) y comienza a loopear para renderizar
	Vista vista(&g, &controlador, asignador);

	return 0;
}

