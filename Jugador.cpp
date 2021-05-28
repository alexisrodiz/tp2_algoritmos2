/*
 * Jugador.cpp
 *
 *  Created on: 28 may. 2021
 *      Author: caroj
 */

#include "Jugador.h"
#include <iostream>
#define MAX_FICHAS 50

Jugador::Jugador(){
	nroJugador = 0;
	for(int i = 1; i <= 2;i++){
		fichaAsignada[i] = "";
	}
	carta = "";
	cantidadFichas = 0;
}

void Jugador::establecerJugador(unsigned int jugador){
	nroJugador = jugador;
}

void Jugador::establecerFichasTotal(){
	cantidadFichas = MAX_FICHAS;
}

void Jugador::ingresarFicha(){
	std::cout << "Ingrese ficha jugador " << nroJugador << " : ";
	if(nroJugador == 1){
		std::cin >> fichaAsignada[0];
	}else{
		std::cin >> fichaAsignada[1];
		while(controlFicha(fichaAsignada)){
			std::cout << "Debe elegir otra ficha jugador " << nroJugador << " : ";
			std::cin >> fichaAsignada[1];
		}
	}

}

bool Jugador::controlFicha(std::string ficha[2]){
	bool validez = false;
	if(ficha[0] == ficha[1]){
		validez = true;
	}
	return validez;
}

unsigned int Jugador::obtenerJugador(){
	return nroJugador;
}

unsigned int Jugador::obtenerFichasTotal(){
	std::cout << "El jugador " << nroJugador << " tiene " << cantidadFichas << std::endl;
	return cantidadFichas;
}

std::string Jugador::obtenerFicha(){
	std::cout << "El jugador " << nroJugador << " tiene la ficha " << fichaAsignada[nroJugador-1] << std::endl;
	return fichaAsignada[nroJugador-1];
}

void Jugador::imprimirJugador(){
	std::cout << "Jugador " << nroJugador << " tu turno"<< std::endl;
}
