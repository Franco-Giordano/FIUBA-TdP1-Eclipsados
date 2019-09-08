#ifndef SRC_MODELO_ENTIDADUBICADA_POSICIONGLOBAL_H_
#define SRC_MODELO_ENTIDADUBICADA_POSICIONGLOBAL_H_

// Los mismos includes en PosicionGlobal y Vista !!!! arreglar posque puden quedar distintos

#define WINDOW_SIZE_HORIZONTAL 800
#define WINDOW_SIZE_VERTICAL 500


class PosicionGlobal {
public:
	PosicionGlobal();
	virtual ~PosicionGlobal();

	//constructor de copia, no hace falta pero por las dudas
	PosicionGlobal(const PosicionGlobal &pos);

	void moverArriba();
	void moverAbajo();
	void moverIzquierda();
	void moverDerecha();

	//TODO: de momento seran gets, despues se puede usar una funcion que no viole encapsulamiento
	float getHorizontal();
	float getVertical();

private:
	float velocidad;
	float x=0;
	float y=0;
};

#endif /* SRC_MODELO_ENTIDADUBICADA_POSICIONGLOBAL_H_ */
