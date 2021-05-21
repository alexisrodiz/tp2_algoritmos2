#ifndef TABLERO_H_
#define TABLERO_H_

#include "Lista.h"

class Tablero {

    private:

        Lista<int>** filaPrincipal;
        int fila;
        int columna;

    public:

        Tablero(int fila, int columna);
        Tablero();


};

#endif /* TABLERO_H_ */