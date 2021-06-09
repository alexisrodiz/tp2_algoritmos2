#include "Tablero.h"
#include "Jugador.h"
#include "Mazo.h"
#include <iostream>

int main() {

    int fil = 2;
    int col = 2;
    int prof = 2;
<<<<<<< HEAD
    unsigned int cantidad;
	std::cout << "Ingrese cantidad de participantes: ";
	std::cin >> cantidad;
	while(cantidad<2){
			std::cout << "Debe ingresar minimo 2 jugadores: ";
			std::cin >> cantidad;
	}
    Jugador* juego = new  Jugador(cantidad);
	Jugadores* ficha = new Jugadores();
	for(unsigned int i = 0; i < cantidad; i++){
		juego->ingresarFicha(ficha,i);
		juego->asignarNumeroDeCartas();
	}
	juego->mostrarJugadores();
=======
    /*
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
    */
>>>>>>> b4a70204883bd2eaa0fe0d892734cf27d7ae10e2

    Tablero* nuevoTablero = new Tablero(fil,col,prof);
    nuevoTablero->mostrarTablero();

    std::cout << "Fin" << std::endl;
    
    return 0;
}
