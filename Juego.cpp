#include <iostream>
#include <algorithm>    // std::find
#include <iomanip>      // std::setw
#include <cmath>
#include "Juego.h"
#include "Jugador.h"
#include "Coordenadas.h"

using namespace std;

Juego::Juego(){

    tablero = new Tablero(2, 2, 2, 4);

    jugadores = new Lista<Jugador*>;

    mazo = new Mazo;

    this->porcentajeQuitarFichas = 5;

}

void Juego::agregarJugadores(){
    int i = 1;
    char agregarOtroJugador;
    string nombre;
    char ficha;
    bool fichaExiste;
    do {
        cout << "Por favor ingrese el nombre del jugador " << i <<  endl;
        cin >> nombre;
        
        do { // Pide una ficha mientras exista en la lista de ficha ya utilizadas
            cout << "Por favor, elija una ficha (letra)" << endl;
            cin >> ficha;

            fichaExiste = (std::find(fichasUtilizadas.begin(), fichasUtilizadas.end(), ficha) != fichasUtilizadas.end());
            if (fichaExiste){
                cout << "La ficha elegida ya existe, por favor elija otra" << endl;
            }
            

        } while ( fichaExiste );
        
        fichasUtilizadas.push_back(ficha);
        
        Jugador * jugador = new Jugador(nombre, ficha, i);
            
        jugadores->agregar(jugador);

        // Si ya se agregaron 2 jugadores, pregunto si se quieren agregar mas
        if (i >= 2) {
            cout << "Desea agregar otro jugador? S: SI, N: NO" << endl;
            cin >> setw(1) >> agregarOtroJugador;
        }
        
        ++i;
    }
    while(i <= 2 || tolower(agregarOtroJugador) == 's');

    this->calcularCantidadFichasPorJugador();
    
}

int Juego::calcularCantidadFichasADevolver(Jugador* jugador){

    return jugador->obtenerCantidadFichas() * (this->porcentajeQuitarFichas / 100);
}

void Juego::calcularCantidadFichasPorJugador(){
    float total;
    unsigned int x, y, z;
    x = this->tablero->obtenerNumeroDeFila();
    y = this->tablero->obtenerNumeroDeColumna();
    z = this->tablero->obtenerNumeroDeProfundidad();
    int cantidadJugadores = this->jugadores->contarElementos();
    total = (x * y * z) / cantidadJugadores;
    this->cantidadFichasPorJugador = floor(total);
}


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
    cout << "Iniciando juego..." << endl;

    bool jugadorGano = false;

    this->tablero->mostrarTablero();

    this->agregarJugadores();

    this->jugadores->iniciarCursor();

    Jugador* jugadorActual = NULL;

    // Ver tema de lista circular para recorrer los jugadores
    while(this->jugadores->avanzarCursor() && jugadorGano == false){
        bool jugadaMarcada;
        int valorCartaJugada;
        char usarCartas;
        bool tieneCartaSeleccionada;

        Coordenadas* coordenadaJugada = NULL;

        Carta* cartaJugada = NULL;

        jugadorActual = this->jugadores->obtenerCursor();

        cout << "TURNO: " << jugadorActual->obtenerNombre() << "(" << jugadorActual->obtenerId() << ")" << endl;
        
        cout << "\nRetirando una carta del mazo..." << endl;
        jugadorActual->sacarCartaMazo(this->mazo);

        cout << "\nTus cartas en mano son: " << endl;
	    jugadorActual->imprimirCartasEnMano();

        cout << "\nUsar alguna carta? S: SI - N: NO" << endl;
        cin >> usarCartas;

        if (tolower(usarCartas) == 's'){

            do {
                cout << "Indique el valor de la carta a utilizar: " << endl;
                cin >> setw(1) >> valorCartaJugada;

                tieneCartaSeleccionada = jugadorActual->verificarSiTieneCartaPorId(valorCartaJugada);
                if (tieneCartaSeleccionada == false){
                    cout << "No tiene esa carta en mano, elija otra por favor" << endl;
                }

            } while (tieneCartaSeleccionada == false);
            
             

            cartaJugada = jugadorActual->obtenerCartaPorValor(valorCartaJugada);

            this->procesarCarta(cartaJugada, jugadorActual);

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

        jugadorGano = this->tablero->jugadorGano(jugadorActual);

    }

    if (jugadorGano){
        cout << "Ha ganado el jugador: " << jugadorActual->obtenerNombre() << endl;
    }

}


void Juego::procesarCarta(Carta* cartaJugada, Jugador* jugadorActual){
    int idJugador;
    switch (cartaJugada->obtenerValor()){
        case 1:
            // Bloquear turno del siguiente jugador (saltea el siguiente) 
            cout << "Bloqueando turno del siguiente jugador!" << endl;
            this->jugadores->avanzarCursor();
            break;
        case 2:
            // Jugar doble 
            cout << "Jugando Doble!" << endl;
            jugadorActual->realizarJugada();
            cout << "Otra vez!" << endl;
            break;
        case 3:
            // Deshacer ultima jugada 
            cout << "Deshaciendo ultima jugada!" << endl;
            this->tablero->borrarUltimaJugada();
            break;
        case 4:
            // Restar n cantidad de fichas a un jugador 
            cout << "Seleccione el ID del jugador al que desea quitarle fichas: " << endl;
            this->imprimirJugadores();
            cin >> idJugador;
            Jugador* jugadorSeleccionado = this->obtenerJugadorPorId(idJugador);

            int cantidadFichas = this->calcularCantidadFichasADevolver(jugadorSeleccionado);

            jugadorSeleccionado->devolverFichas(cantidadFichas);

            break;
    }
}