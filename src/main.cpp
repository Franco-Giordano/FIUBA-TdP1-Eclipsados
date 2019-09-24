#include "vista/Vista.h"
#include "controlador/Controlador.h"
#include "tinyxml2/tinyxml2.h"
#include "Logger.h"
#include <string.h>
#include <getopt.h>

#include "ParserXML.h"

#include <vector>

using namespace tinyxml2;

int interpret_cmds(int ch);

int main(int argc, char* argv[]) {

  char ch;

  const char *const short_opt = "hdie";
  const struct option long_opt[] = {
            {"help", 0, NULL, 'h'},
            {"debug", 0, NULL, 'd'},
            {"info", 0, NULL, 'i'},
            {"error", 0, NULL, 'e'},
            {NULL, 0, NULL, 0}
  };

  while ((ch = getopt_long(argc, argv, short_opt, long_opt, NULL)) != -1)
    if ( interpret_cmds(ch) )
      return -1;

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

int interpret_cmds(int ch) {

  switch (ch) {
    case 'h':
      printf("Usage:\n"
             "    final-fight\n"
             "    final-fight -h\n"
             "    final-fight -d\n"
             "    final-fight -i\n"
             "    final-fight -e\n"
             "Options:\n"
             "    EMPTY            Load log level from XML.\n"
             "    -h, --help       Print this information and quit.\n"
             "    -d, --debug      Initialize DEBUG log level.\n"
             "    -i, --info       Initialize INFO log level.\n"
             "    -e, --error      Initialize ERROR log level.\n"); return -1;
      break;
    case 'd': Logger::getInstance()->setLevel(DEBUG);
      break;
    case 'i': Logger::getInstance()->setLevel(INFO);
      break;
    case 'e': Logger::getInstance()->setLevel(ERROR);
      break;
    case '?': return -1;
      break;
  }
  return 0;
}
