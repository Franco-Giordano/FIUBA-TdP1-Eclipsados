
#include "Vista.h"
#include "Controlador.h"

int main() {

	//juego no hace mucho, solo encapsula Personaje
	Juego g;


	//solo inicializa variables, no hace nada
	Controlador controlador(&g);


	//vista se crea (ventana) y comienza a loopear para renderizar
	Vista vista(&g, &controlador);

}

