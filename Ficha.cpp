#include "Ficha.h"

Ficha::Ficha(Colores* colorDeLaFicha, char valorDeLaFicha) {

    this->colorDeLaFicha = colorDeLaFicha;
    this->valorDeLaFicha = valorDeLaFicha;

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