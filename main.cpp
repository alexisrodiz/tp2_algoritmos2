#include "Tablero.h"
#include "Jugador.h"
#include "Mazo.h"
#include <iostream>

int main() {

    int fil = 2;
    int col = 2;
    int prof = 2;
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

    Tablero* nuevoTablero = new Tablero(fil,col,prof);
    nuevoTablero->mostrarTablero();

    std::cout << "Fin" << std::endl;
    
    return 0;
}
