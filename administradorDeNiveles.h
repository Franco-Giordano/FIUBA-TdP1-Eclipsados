
#ifndef ADMINISTRADORDENIVELES_H_
#define ADMINISTRADORDENIVELES_H_

#include <stdio.h>
#include "nivel.h"

class AdministradorDeNiveles {
public:
	AdministradorDeNiveles();
	virtual ~AdministradorDeNiveles();
	void cambiarNivel();

private:
	Nivel nivelActual;
};

#endif /* ADMINISTRADORDENIVELES_H_ */
