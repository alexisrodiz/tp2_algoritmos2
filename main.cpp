#include "Tablero.h"
#include "Jugador.h"
#include <iostream>

int main() {

    int fil = 2;
    int col = 2;
    int prof = 2;
    unsigned jugador1 = 1;
    unsigned jugador2 = 2;

    Jugador nroJugador;

    nroJugador.establecerJugador(jugador1);
    nroJugador.imprimirJugador();
    nroJugador.establecerJugador(jugador2);
    nroJugador.imprimirJugador();


    Tablero* nuevoTablero = new Tablero(fil,col,prof);
    nuevoTablero->mostrarTablero();

    std::cout << "Fin" << std::endl;
    
    return 0;
}
