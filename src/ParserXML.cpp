/*
 * ParserXML.cpp
 *
 *  Created on: Sep 17, 2019
 *      Author: franco
 */

#include "ParserXML.h"

using namespace tinyxml2;

/*
Hay distintos tipos de errores:
	- no se puede abrir el archivo custom
	- no existe alguna seccion del xml (FirstChildElement == null)
	- el valor no es del tipo correcto (se esperaba int y dio bool,string,etc)

*/

ParserXML::ParserXML(std::string rutaConfig){

	pConfig = new XMLDocument;

	XMLError eArchivo = pConfig->LoadFile(rutaConfig.c_str());

	//TODO: y si falla en abrir el default?
	XMLError eDefault = configDefault.LoadFile("xmlDefault.xml");

	if (eArchivo != XML_SUCCESS) {
		//usar default, en vez de custom
		pConfig = &configDefault;
	}

	pHandler = new XMLHandle(pConfig);

}

void ParserXML::parsearConfig(int *cantEnemigos, int *cantCuchillos, int *cantCajas, int *cantCanios, int *cantBarriles) {

	//FIXME: viola todos los encapsulamientos conocidos por la raza humana
	std::vector<std::string> *nivel1 = asignador.getNivel1();
	std::vector<std::string> *nivel2 = asignador.getNivel2();
	std::vector<std::string>* sprites = asignador.getSprites();


	if (pConfig == &configDefault) {
		//estoy parseando el default, no debo chequear errores
		//parsearConfigDefault(cantEnemigos, cantCuchillos, cantCajas, cantCanios, cantBarriles, nivel1, nivel2);
	}

	XMLElement* pEscenarioDEFAULT = configDefault.FirstChildElement("configuracion")->FirstChildElement("escenario");

	XMLHandle hRaiz = pHandler->FirstChildElement("configuracion");

	//TODO: settear nivel de config en LOG, chequeando que ToElement != nullptr
	const char* debugLevel = hRaiz.FirstChildElement("debugLevel").ToElement()->GetText();

	XMLHandle hEscenario = hRaiz.FirstChildElement("escenario");


	asignarValor(cantCuchillos, "cuchillo", hEscenario.FirstChildElement("cantidades"), pEscenarioDEFAULT->FirstChildElement("cantidades"));

	asignarValor(cantCajas, "caja", hEscenario.FirstChildElement("cantidades"), pEscenarioDEFAULT->FirstChildElement("cantidades"));

	asignarValor(cantBarriles, "barril", hEscenario.FirstChildElement("cantidades"), pEscenarioDEFAULT->FirstChildElement("cantidades"));

	asignarValor(cantCanios, "canio", hEscenario.FirstChildElement("cantidades"), pEscenarioDEFAULT->FirstChildElement("cantidades"));

	asignarValor(cantEnemigos, "enemigo", hEscenario.FirstChildElement("cantidades"), pEscenarioDEFAULT->FirstChildElement("cantidades"));



	XMLHandle hNiveles = hEscenario.FirstChildElement("niveles");

	XMLElement* eNivel1 = hNiveles.FirstChildElement("nivel1").ToElement();

	if (eNivel1 != nullptr)
		asignarLista(nivel1, eNivel1, "fondo");

	if (nivel1->size() != CANT_CAPAS) {
		//TODO: no existe <nivel1>, o se pasaron fondos de menos o de mas! avisar por log
		nivel1->clear();
		asignarLista(nivel1, pEscenarioDEFAULT->FirstChildElement("niveles")->FirstChildElement("nivel1"), "fondo");
	}


	XMLElement* eNivel2 = hNiveles.FirstChildElement("nivel2").ToElement();

	if (eNivel2 != nullptr)
		asignarLista(nivel2, eNivel2, "fondo");

	if (nivel2->size() != CANT_CAPAS) {
		//TODO: no existe <nivel2>, o se pasaron fondos de menos o de mas! avisar por log
		nivel2->clear();
		asignarLista(nivel2, pEscenarioDEFAULT->FirstChildElement("niveles")->FirstChildElement("nivel2"), "fondo");
	}


	XMLElement* eSprites = hRaiz.FirstChildElement("sprites").ToElement();

	if (eSprites != nullptr) {
		//asume que los sprites estan en orden! ni le da bola a las tags
		asignarLista(sprites, eSprites, "sprite");
	}
	if (sprites->size() != CANT_SPRITES) {
		//TODO: no existe <sprites>, o se pasaron sprites de menos o de mas! avisar por log
		sprites->clear();
		asignarLista(nivel2, pEscenarioDEFAULT->FirstChildElement("niveles")->FirstChildElement("nivel2"), "sprite");
	}

}

ParserXML::~ParserXML() {
	// TODO Auto-generated destructor stub

	delete pHandler;

	delete pConfig;
}

void ParserXML::asignarValor(int* variable, const char* nombre, XMLHandle base, XMLElement* backup) {

	XMLElement* pElemento = base.FirstChildElement(nombre).ToElement();

	XMLError error = XML_SUCCESS;

	if (pElemento)
		error = pElemento->QueryIntText(variable);

	if (!pElemento || error != XML_SUCCESS) {

		//TODO: avisar por log que no esta la categoria/no es de tipo int/no contiene texto
		backup->FirstChildElement(nombre)->QueryIntText(variable);
	}


}

void ParserXML::asignarLista(std::vector<std::string> *lista, XMLElement* eBase, const char * nombreItems) {
	//asume que los fondos estan en orden
	for(XMLElement* e = eBase->FirstChildElement(nombreItems); e != NULL; e = e->NextSiblingElement(nombreItems)) {
	    lista->push_back(e->GetText());
	}
}
