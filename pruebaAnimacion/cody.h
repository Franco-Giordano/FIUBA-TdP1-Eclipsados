#ifndef CODY_H
#define CODY_H

#include <vector>
#include "objeto.h"


class Cody : public Object{
public:
	/*setters*/
	Cody() {rev=0;}
	int crearCiclo(int colu, int w, int h, int cant, int vel);
	void setCurrentAnim(int c) {empezar = 0; animActual = c;}
	void updateAnim();
	void reverse(bool r) {rev=r;}
	void reverse(bool r, int nA) {rev=r; nAb=1; nA=newAnim;}
private:
	struct cycle {
		int colu;
		int w;
		int h;
		int cant;
		int vel;
		int tick;
	};
	vector<cycle> animaciones;
	int animActual;
	int empezar;
	bool rev,nAb;
	int newAnim;
};



#endif /* CODY_H */
