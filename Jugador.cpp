/*
 * Jugador.cpp
 *
 *  Created on: 28 may. 2021
 *      Author: caroj
 */

#include "Jugador.h"
#include <iostream>

using namespace std;
/*
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
*/

Jugador::Jugador(string nombre, char ficha){
	this->cartas = new Lista<Carta*>;
	this->fichaAsignada = ficha;
	this->nombre = nombre;
	cantidadFichas = 0;
}

void Jugador::sacarCartaMazo(Mazo* mazo){
	if (cartas->contarElementos() < cantidadMaximaCartas)
	{
		Carta* carta = mazo->sacarCarta();
		cartas->agregar(carta);
	}
}

Lista<Carta*>* Jugador::obtenerCartas(){
	return this->cartas;
}

string Jugador::obtenerNombre(){
	return this->nombre;
}

char Jugador::obtenerFicha(){
	return this->fichaAsignada;
}

void Jugador::realizarJugada(){
	/* **** */ 
}

/*
void Jugador::ingresarFicha(Jugadores* ficha,unsigned int i){
	std::cout << "Ingrese ficha jugador " << i+1 << ": ";
	std::cin >> fichaAsignada;
	while(!ficha->verificarFicha(fichaAsignada)){
		std::cout << "Ficha ya usada, ingrese otra: ";
		std::cin >> fichaAsignada;
	}
	this->jugadores->agregar(ficha,i);

}
*/
/*
void Jugador::mostrarJugadores(){
	for(unsigned int i=0; i<this->cantidadJugadores;i++){
		std::cout << "Jugador: " << i+1 << this->jugadores->obtener(i) << " Ficha: " << this->jugadores->obtener(i) << std::endl;
	}
}
*/
/*
void Jugador::asignarNumeroDeCartas(){
	int maximo = 3;
	Carta* carta = new Carta(maximo,this->carta);
	std::cout << "Carta: " << carta->obtenerTipo() << std::endl;
	std::cout << " Tipo: " << carta->obtenerValor() << std::endl;
	this->cartas->agregar(carta);
	this->cartas->obtener(maximo);
}
*/

