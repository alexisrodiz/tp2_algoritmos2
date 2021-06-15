#include <iostream>
#include <algorithm>
#include "Juego.h"
#include "Jugador.h"

using namespace std;

Juego::Juego(){

    jugadores = new Lista<Jugador*>;

}

void Juego::agregarJugadores(){
    int i = 1;
    int agregarOtroJugador = 0;
    string nombre;
    char ficha;
    do {
        cout << "Por favor ingrese el nombre del jugador" << endl;
        cin >> nombre;
        
        do
        { // Pide una ficha mientras exista en la lista de ficha ya utilizadas
            cout << "Por favor, elija una ficha (letra)" << endl;
            cin >> ficha;

        } while ( std::find(fichasUtilizadas.begin(), fichasUtilizadas.end(), ficha) != fichasUtilizadas.end() );
        
        fichasUtilizadas.push_back(ficha);
        
        Jugador * jugador = new Jugador(nombre, ficha);
            
        jugadores->agregar(jugador);

        cout << "Desea agregar otro jugador? 1: SI, 0: NO" << endl;
        cin >> agregarOtroJugador;

        ++i;
    }
    while(i <= 2 || agregarOtroJugador != 0);
    
}


Lista<Jugador *>* Juego::obtenerJugadores(){
    return this->jugadores;
}

void Juego::imprimirJugadores(){
    jugadores->iniciarCursor();
    while (jugadores->avanzarCursor())
    {
        Jugador* jugador = jugadores->obtenerCursor();
        cout << "Nombre: " << jugador->obtenerNombre() << endl;
        cout << "Ficha elegida: " << jugador->obtenerFicha() << "\n" << endl;
    }
    

}