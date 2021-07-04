#include "Ficha.h"

Ficha::Ficha(Colores* colorDeLaFicha, char valorDeLaFicha) {

    this->colorDeLaFicha = colorDeLaFicha;
    this->valorDeLaFicha = new char[1];
    *this->valorDeLaFicha = valorDeLaFicha;
}

Colores* Ficha::obtenerColorDeLaFicha() {

    return this->colorDeLaFicha;

}

char* Ficha::obtenerValorDeLaFicha() {

    return this->valorDeLaFicha;

}

bool Ficha::valoresFichaIguales(char valorFicha){
	return valorFicha == *this->valorDeLaFicha;
}


Ficha::~Ficha() {

    delete this->colorDeLaFicha;

}
