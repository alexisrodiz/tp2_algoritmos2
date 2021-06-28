#include "Celda.h"

Celda::Celda() {

    this->ficha = NULL;
    this->estaVacia = true;

}

Ficha* Celda::obtenerFicha() {

    return this->ficha;

}

void Celda::colocarFicha(Ficha* fichaDeJugador) {

    Ficha* ficha = obtenerFicha();
    ficha = fichaDeJugador;

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

Celda::~Celda() {

    delete this->ficha;

}
