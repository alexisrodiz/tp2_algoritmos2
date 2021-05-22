#include "Tablero.h"
#include <iostream>

int main() {

    int fil = 2;
    int col = 2;
    int prof = 2;

    Tablero* nuevoTablero = new Tablero(fil,col,prof);
    nuevoTablero->mostrarTablero();

    std::cout << "Fin" << std::endl;
    
    return 0;
}