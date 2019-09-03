

#ifndef POSICION_H_
#define POSICION_H_

class Posicion {
public:
	Posicion();
	virtual ~Posicion();

	void moverArriba ();
	void moverAbajo ();
	void moverIzquierda ();
	void moverDerecha ();


private:
	float movimiento;
	float x;
	float y;
};

#endif /* POSICION_H_ */
