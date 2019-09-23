#include "vista/Vista.h"
#include "controlador/Controlador.h"
#include "tinyxml2/tinyxml2.h"
#include "Logger.h"

#include "ParserXML.h"

#include <vector>

using namespace tinyxml2;

int main() {

	Logger::getInstance()->setLevel(DEBUG);

	int cantCuchillos = 0, cantBarriles = 0, cantEnemigos = 0, cantCanios = 0, cantCajas = 0;

	ParserXML parser("xmlCustom.xml");

	parser.parsearConfig(&cantEnemigos, &cantCuchillos, &cantCajas, &cantCanios, &cantBarriles);

	Juego game(cantCuchillos, cantCajas, cantCanios, cantBarriles, cantEnemigos);

	Controlador controlador(&game);

	AsignadorDeTexturas asignador = parser.getAsignador();

	Vista vista(&game, &controlador, asignador);


	delete Logger::getInstance();

	return 0;
}

