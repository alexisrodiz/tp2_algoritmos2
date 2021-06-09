/*
 * Jugadores.cpp
 *
 *  Created on: 8 jun. 2021
 *      Author: caroj
 */
#include "Jugadores.h"

Jugadores::Jugadores(){
    this->valorDeFicha = ' ';
}

char Jugadores::obtenerValorDelJugador(){
    return this->valorDeFicha;
}

void Jugadores::asignarFicha(char ficha){
	this->valorDeFicha = ficha;
}

bool Jugadores::verificarFicha(char ficha){
	bool validez = false;
	while(ficha!=this->valorDeFicha){
		asignarFicha(ficha);
		validez = true;
	}
	return validez;
}

Jugadores::~Jugadores(){}
