#include "Celda.h"

Celda::Celda() {

    this->valorDeLaCelda = (char)' ';
    this->estaVacia = false;

}

void Celda::cambiarValorDeCelda(char nuevoValor) {

    this->valorDeLaCelda = nuevoValor;

}

char Celda::obtenerValorDeCelda() {

    return this->valorDeLaCelda;

}

void Celda::cambiarEstadoDeCelda() {

    this->estaVacia = !estaVacia; //aca lo cambie porque devolvia siempre falso

}

bool Celda::obtenerEstaVacia() {

    return this->estaVacia;    

}

Celda::~Celda() {}
