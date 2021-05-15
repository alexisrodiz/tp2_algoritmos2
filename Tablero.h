#ifndef TABLERO_H_
#define TABLERO_H_

#include "ListaDE.h"

class Tablero {

    private:

        Lista<int>** filaPrincipal;
        unsigned int fila;
        unsigned int columna;

    public:

        Tablero(unsigned int fila, unsigned int columna);


};

#endif /* TABLERO_H_ */