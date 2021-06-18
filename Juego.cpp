#include <iostream>
#include <algorithm>
#include "Juego.h"
#include "Jugador.h"
#include "Coordenadas.h"

using namespace std;

Juego::Juego(){

    jugadores = new Lista<Jugador*>;

    mazo = new Mazo;

}

void Juego::agregarJugadores(){
    int i = 1;
    int agregarOtroJugador = 0;
    string nombre;
    char ficha;
    do {
        cout << "Por favor ingrese el nombre del jugador " << i <<  endl;
        cin >> nombre;
        
        do
        { // Pide una ficha mientras exista en la lista de ficha ya utilizadas
            cout << "Por favor, elija una ficha (letra)" << endl;
            cin >> ficha;

        } while ( std::find(fichasUtilizadas.begin(), fichasUtilizadas.end(), ficha) != fichasUtilizadas.end() );
        
        fichasUtilizadas.push_back(ficha);
        
        Jugador * jugador = new Jugador(nombre, ficha);
            
        jugadores->agregar(jugador);

        // Si ya se agregaron 2 jugadores, pregunto si se quieren agregar mas
        if (i >= 2)
        {
            cout << "Desea agregar otro jugador? 1: SI, 0: NO" << endl;
            cin >> agregarOtroJugador;
        }
        
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

void Juego::iniciar(Tablero* tablero){

    this->agregarJugadores();

    this->obtenerJugadores()->iniciarCursor();

    // Ver tema de lista circular para recorrer los jugadores
    while(this->obtenerJugadores()->avanzarCursor()){
        int valorCartaJugada;
        int usarCartas = 0;

        Coordenadas* coordenadasJugada = NULL;

        Carta* cartaJugada = NULL;

        Jugador* jugador = this->obtenerJugadores()->obtenerCursor();
        
        cout << "Retirando una carta del mazo..." << endl;
        jugador->sacarCartaMazo(this->mazo);

        cout << "Tus cartas en mano son: " << endl;
	    jugador->imprimirCartasEnMano();

        cout << "Usar carta? 1: SI - 0: NO" << endl;
        cin >> usarCartas;

        if (usarCartas == 1)
        {
            cout << "Indique el valor de la carta a utilizar: " << endl;
            cin >> valorCartaJugada; // falta chequear que el valor esté entre los aceptados (1-4)

            cartaJugada = jugador->obtenerCartaPorValor(valorCartaJugada);

            this->procesarCarta(cartaJugada, jugador);

        }

        coordenadasJugada = jugador->realizarJugada();

        //tablero->marcarJugada()

    }
}

void Juego::procesarCarta(Carta* carta, Jugador* jugador){
    switch (carta->obtenerValor()){
        case 1:
            /* Bloquear turno del siguiente jugador (saltea el siguiente) */
            this->jugadores->avanzarCursor();
            break;
        case 2:
            jugador->realizarJugada();
            break;
        case 3:
            /* Deshacer jugada del jugador anterior */
            break;
        case 4:
            /* code */
            break;
    }
}