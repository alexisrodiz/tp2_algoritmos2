#ifndef TABLERO_H_
#define TABLERO_H_

#include "Lista.h"

typedef Lista< Lista< Lista<int>* >* >* lista; 

class Tablero {

    

    private:

        lista fila;
        unsigned int numeroDeFila;
        unsigned int numeroDeColumna;
        unsigned int numeroDeProfundidad;

    public:

        /* Pre: Recibe datos validos
        *  Pos: Crea un tablero de 3 dimensiones, inicializando los casilleros en 0
        */
        Tablero(unsigned int fila, unsigned int columna, unsigned int profundidad);

        /* Pre:
        *  Pos:
        */
        Tablero();

        /* Pre:
        *  Pos: muestra el tablero por consola
        */
        void mostrarTablero();

};

#endif /* TABLERO_H_ */