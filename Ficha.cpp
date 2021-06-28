#include "Ficha.h"

Ficha::Ficha(Colores* colorDeLaFicha) {

    this->colorDeLaFicha = colorDeLaFicha;
    this->valorDeLaFicha = (char)' ';

}

Colores* Ficha::obtenerColorDeLaFicha() {

    return this->colorDeLaFicha;

}

char Ficha::obtenerValorDeLaFicha() {

    return this->valorDeLaFicha;

}

Ficha::~Ficha() {

    delete this->colorDeLaFicha;

}