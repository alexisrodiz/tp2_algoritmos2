#include "Colores.h"



	Colores::Colores(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul){
		this->estructuraDeColor = new RGBApixel;
		this->estructuraDeColor->Red = rojo;
		this->estructuraDeColor->Green = verde;
		this->estructuraDeColor->Blue = azul;
	}

	Colores::~Colores(){
		delete this->estructuraDeColor;
	}

	void Colores::guardarTonalidadRojo(ebmpBYTE nuevaTonalidadDeRojo){
		this->estructuraDeColor->Red = nuevaTonalidadDeRojo;
	}


	void Colores::guardarTonalidadVerde(ebmpBYTE nuevaTonalidadDeVerde){
		this->estructuraDeColor->Green = nuevaTonalidadDeVerde;
	}

	void Colores::guardarTonalidadAzul(ebmpBYTE nuevaTonalidadDeAzul){
		this->estructuraDeColor->Blue = nuevaTonalidadDeAzul;
	}


	ebmpBYTE Colores::devolverTonalidadRojo(){
		return this->estructuraDeColor->Red;
	}

	ebmpBYTE Colores::devolverTonalidadVerde(){
		return this->estructuraDeColor->Green;

	}

	ebmpBYTE Colores::devolverTonalidadAzul(){
		return this->estructuraDeColor->Blue;
	}





