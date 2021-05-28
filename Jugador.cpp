/*
 * Jugador.cpp
 *
 *  Created on: 28 may. 2021
 *      Author: caroj
 */

#include "Jugador.h"
#include <iostream>

Jugador::Jugador(){
	nroJugador = 0;
}

unsigned int Jugador::establecerJugador(unsigned int jugador){
	nroJugador = jugador;
	return nroJugador;
}

void Jugador::imprimirJugador(){
	std::cout << "Jugador " << nroJugador << " tu turno: " << std::endl;
}
