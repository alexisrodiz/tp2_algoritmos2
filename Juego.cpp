#include <iostream>
#include <algorithm>
#include "Juego.h"
#include "Jugador.h"
#include "Coordenadas.h"

using namespace std;

Juego::Juego(){

    tablero = new Tablero(2, 2, 2, 4);

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
        
        Jugador * jugador = new Jugador(nombre, ficha, i);
            
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

/*
Lista<Jugador *>* Juego::obtenerJugadores(){
    return this->jugadores;
}
*/
void Juego::imprimirJugadores(){
    jugadores->iniciarCursor();
    while (jugadores->avanzarCursor())
    {
        Jugador* jugador = jugadores->obtenerCursor();
        cout << "ID: " << jugador->obtenerId() << endl;
        cout << "Nombre: " << jugador->obtenerNombre() << endl;
        cout << "Ficha elegida: " << jugador->obtenerFicha() << "\n" << endl;
    }
}

Jugador* Juego::obtenerJugadorPorId(int id){
    Jugador* jugador = NULL;
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		if (this->jugadores->obtenerCursor()->obtenerId() == id){
			jugador = this->jugadores->obtenerCursor();
		}
	}
	return jugador;
};

void Juego::iniciar(){

    this->tablero->mostrarTablero();

    this->agregarJugadores();

    this->jugadores->iniciarCursor();

    Jugador* jugadorActual, * jugadorSeleccionado = NULL;

    // Ver tema de lista circular para recorrer los jugadores
    while(this->jugadores->avanzarCursor()){
        bool jugadaMarcada;
        int numeroJugador;
        int valorCartaJugada;
        int usarCartas = 0;

        Coordenadas* coordenadaJugada = NULL;

        Carta* cartaJugada = NULL;

        jugadorActual = this->jugadores->obtenerCursor();
        
        cout << "Retirando una carta del mazo..." << endl;
        jugadorActual->sacarCartaMazo(this->mazo);

        cout << "Tus cartas en mano son: " << endl;
	    jugadorActual->imprimirCartasEnMano();

        cout << "Usar carta? 1: SI - 0: NO" << endl;
        cin >> usarCartas;

        if (usarCartas == 1){
            cout << "Indique el valor de la carta a utilizar: " << endl;
            cin >> valorCartaJugada; // falta chequear que el valor esté entre los aceptados (1-4)

            cartaJugada = jugadorActual->obtenerCartaPorValor(valorCartaJugada);

            //this->procesarCarta(cartaJugada, jugador);

            switch (cartaJugada->obtenerValor()){
                case 1:
                    /* Bloquear turno del siguiente jugador (saltea el siguiente) */
                    cout << "¡Bloqueando turno del siguiente jugador!" << endl;
                    this->obtenerJugadores()->avanzarCursor();
                    break;
                case 2:
                    /* Jugar doble */
                    cout << "¡Jugando Doble!" << endl;
                    jugadorActual->realizarJugada();
                    break;
                case 3:
                    /* Deshacer ultima jugada */
                    this->tablero->borrarUltimaJugada();
                    break;
                case 4:
                    /* Restar n cantidad de fichas a un jugador */
                    cout << "Seleccione el ID del jugador al que desea quitarle las fichas: " << endl;
                    this->imprimirJugadores();
                    cin >> numeroJugador;
                    jugadorSeleccionado = this->obtenerJugadorPorId(numeroJugador);

                    jugadorSeleccionado->devolverFichas(5); // Calcular porcentaje fichas a quitar
                    break;
            }

        }

        do {
            coordenadaJugada = jugadorActual->realizarJugada();

            jugadaMarcada = tablero->marcarJugada(coordenadaJugada, jugadorActual);
            if (jugadaMarcada == false){
                cout << "No hay espacio en las coordenadas seleccionadas, elija otras" << endl;
            }
            
        }
        while(jugadaMarcada == false);



        
        this->tablero->mostrarTablero();

    }
}

/*
void Juego::procesarCarta(Carta* carta, Jugador* jugador){
    switch (carta->obtenerValor()){
        case 1:
            // Bloquear turno del siguiente jugador (saltea el siguiente) 
            cout << "¡Bloqueando turno del siguiente jugador!" << endl;
            this->jugadores->avanzarCursor();
            break;
        case 2:
            // Jugar doble 
            cout << "¡Jugando Doble!" << endl;
            jugador->realizarJugada();
            break;
        case 3:
            // Deshacer ultima jugada 

            break;
        case 4:
            // code 
            break;
    }
}*/