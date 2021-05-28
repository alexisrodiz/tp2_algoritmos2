#include "Tablero.h"
#include "Jugador.h"
#include <iostream>

int main() {

    int fil = 2;
    int col = 2;
    int prof = 2;
    unsigned jugador1 = 1;
    unsigned jugador2 = 2;
    unsigned fichasTotal;
    std::string fichasJugador1;
    std::string fichasJugador2;

    Jugador nroJugador;

    nroJugador.establecerJugador(jugador1);
    nroJugador.establecerFichasTotal();
    nroJugador.ingresarFicha();
    jugador1 = nroJugador.obtenerJugador();
    fichasTotal = nroJugador.obtenerFichasTotal();
    fichasJugador1 = nroJugador.obtenerFicha();

    nroJugador.establecerJugador(jugador2);
	nroJugador.establecerFichasTotal();
	nroJugador.ingresarFicha();
	jugador2 = nroJugador.obtenerJugador();
	fichasTotal = nroJugador.obtenerFichasTotal();
	fichasJugador2 = nroJugador.obtenerFicha();


    Tablero* nuevoTablero = new Tablero(fil,col,prof);
    nuevoTablero->mostrarTablero();

    std::cout << "Fin" << std::endl;
    
    return 0;
}
