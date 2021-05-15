#include "Tablero.h"
#include <iostream>

int main() {

    int fila = 6;
    int col = 6;
    Tablero *tablero = new Tablero(fila, col);

    std::cout << "Termino" << std::endl;
    return 0;
}