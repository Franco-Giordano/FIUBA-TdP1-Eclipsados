

#ifndef NIVEL_H_
#define NIVEL_H_

#include <stdio.h>
#include <vector>
#include "entidadUbicada/EntidadUbicada.h"
//#include "cody.h"

class Nivel {
public:
	Nivel();
	virtual ~Nivel();
	void inicializarObjetos();


private:
	std::vector<EntidadUbicada> entidades;
	//Cody cody;

};
#endif /* NIVEL_H_ */
