#include "cody.h"


int Cody::crearCiclo(int c, int w, int h, int cant, int vel){
	cycle tmp;
	tmp.colu=c-1;
	tmp.w=w;
	tmp.cant=cant;
	tmp.vel=vel;
	tmp.tick=0;
	animaciones.push_back(tmp);
	return animaciones.size()-1;
}
void Cody::updateAnim(){
	setSource(animaciones[animActual].w*animaciones[animActual].tick, animaciones[animActual].colu*animaciones[animActual].h, animaciones[animActual].w, animaciones[animActual].h);
	if(empezar>animaciones[animActual].vel){
		if(!rev)animaciones[animActual].tick++;
		if(rev)animaciones[animActual].tick--;
		empezar=0;
	}
	empezar++;
	if(animaciones[animActual].tick >= animaciones[animActual].cant) {
		animaciones[animActual].tick=0;
	}
	if(animaciones[animActual].tick <= 0){
		if(nAb){
			animActual=newAnim;
			nAb=0;
			rev=0;
		}else{
			animaciones[animActual].tick=0;
		}
	}
}



