#include <iostream>
#include "Carta.h"

Carta::Carta(int valor, std::string tipo){
	this->valor = valor;
	this->tipo = tipo;
}

int Carta::obtenerValor(){
	return this->valor;
};

std::string Carta::obtenerTipo(){
	return this->tipo;
};
