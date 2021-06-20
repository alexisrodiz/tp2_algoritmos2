#include "Mazo.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

Mazo::Mazo(){
	
	this->listaCartas = new Lista<Carta*>;
	
	this->listaCartas->agregar(new Carta(1, "Bloquear Turno"));
	this->listaCartas->agregar(new Carta(2, "Jugar Doble"));
	this->listaCartas->agregar(new Carta(3, "Deshacer Ultima Jugada"));
	this->listaCartas->agregar(new Carta(4, "Quitar Fichas a un Jugador"));
	
}

Carta* Mazo::sacarCarta(){
	// Uso srand(time(0)) para generar numeros distintos con rand()
	srand(time(0));
	// Devuelve entre 1 y 4 inclusive
	return this->listaCartas->obtener(1 + rand() % 4); 
}

