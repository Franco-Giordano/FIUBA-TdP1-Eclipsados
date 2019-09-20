/*
 * Enemigo.h
 *
 *  Created on: Sep 5, 2019
 *      Author: franco
 */

#ifndef SRC_MODELO_ENTIDADUBICADA_DIBUJABLE_ENEMIGO_H_
#define SRC_MODELO_ENTIDADUBICADA_DIBUJABLE_ENEMIGO_H_

#include "Dibujable.h"


class Enemigo : public Dibujable {
public:
	Enemigo();
	virtual ~Enemigo();

	void setImageWith(AsignadorDeTexturas& asignador, SDL_Renderer* ren);
};

#endif /* SRC_MODELO_ENTIDADUBICADA_DIBUJABLE_ENEMIGO_H_ */
