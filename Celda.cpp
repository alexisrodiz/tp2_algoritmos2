#include "Celda.h"

Celda::Celda() {

    this->valorDeLaCelda = " ";
    this->estadoDeLaCelda = "vacia";

}

std::string Celda::obtenerValorDeCelda() {

    return this->valorDeLaCelda;

}

std::string Celda::obtenerEstadoDeCelda() {

    return this->estadoDeLaCelda;    

}

Celda::~Celda() {}