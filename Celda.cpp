#include "Celda.h"
#include <iostream>
Celda::Celda() {

    this->ficha = NULL;
    this->estaVacia = true;
    for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				this->vecinas[i][j][k] = NULL;
			}
		}
	}
    this->coordenadas = new Coordenadas(0,0,0);

}

Ficha* Celda::obtenerFicha() {

    return this->ficha;

}

void Celda::colocarFicha(Ficha* fichaDeJugador) {

    Ficha* ficha = obtenerFicha();
    ficha = fichaDeJugador;

}

void Celda::vaciarCelda() {

    Ficha* fichaAuxiliar = obtenerFicha();
    this->ficha = NULL;
    delete fichaAuxiliar;

}

char Celda::obtenerValorDeCelda() {

    return obtenerEstaVacia() ? (char)' ' : obtenerFicha()->obtenerValorDeLaFicha();

}

void Celda::cambiarEstadoDeCelda() {

    bool estadoDelaCelda = obtenerEstaVacia();
    estadoDelaCelda = !estaVacia;

}

bool Celda::obtenerEstaVacia() {

    return this->estaVacia;    

}

Coordenadas* Celda::obtenerCoordenadas(){
	return this->coordenadas;
}

void Celda::guardarVecina(Celda* celdaVecina, int x, int y, int z){
	this->vecinas[x][y][z] = celdaVecina;
}

Celda* Celda::obtenerVecina(int x, int y, int z){
	return this->vecinas[x][y][z];
}

Celda::~Celda() {

    if(!obtenerEstaVacia()) {

        delete obtenerFicha();

    }

}
