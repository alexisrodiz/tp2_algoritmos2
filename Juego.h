#ifndef JUEGO_H_
#define JUEGO_H_

#include <vector>
#include "Tablero.h"
#include "Jugador.h"
#include "Lista.h"
#include "Mazo.h"
#include "Coordenadas.h"

class Juego {

    private:

    std::vector<char> fichasUtilizadas;

    Lista<Jugador *>* jugadores;

    Mazo* mazo;

    public:


    /*
    * post: Crea un juego
    */
    Juego();


    /*
    * pre: el jugador juega una carta
    * post: procesa la carta segun el tipo y ejecuta las acciones que determinan la misma
    */
    void procesarCarta(Carta* carta, Jugador* jugador);

    /*
    * post: Solicita nombre y ficha para crear y agregar los jugadores a la lista
    */
    void agregarJugadores();

    /*
    * pre: recibe una instancia de tablero como parametro
    * post: Inicia el Juego
    */
    void iniciar(Tablero* tablero);


    /*
    * pre: Haber agregado los jugadores
    * post: Devuelve la lista de jugadores
    */
    Lista<Jugador *>* obtenerJugadores();

    /*
    * pre: que haya jugadores en la lista
    * post: imprime por pantalla la lista de jugadores
    */
    void imprimirJugadores();

    /*
    * post: Destruye el juego
    */
    ~Juego();


};


#endif