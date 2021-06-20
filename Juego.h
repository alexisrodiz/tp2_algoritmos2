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

    Tablero* tablero;

    std::vector<char> fichasUtilizadas;

    Lista<Jugador *>* jugadores;

    Mazo* mazo;

    /*
    * pre: Haber agregado los jugadores
    * post: Devuelve la lista de jugadores
    */
    Lista<Jugador *>* obtenerJugadores();

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
    * pre: Que se hayan creado los jugadores
    * post: Calcula la cantidad de fichas que le corresponden a cada jugador y se las asigna
    */
    void asignarCantidadFichasAJugadores();

    /*
    * post: Solicita nombre y ficha para crear y agregar los jugadores a la lista
    */
    void agregarJugadores();

    /*
    * pre: recibe una instancia de tablero como parametro
    * post: Inicia el Juego
    */
    void iniciar();


    /*
    * pre: que exista el jugador
    * post: devuelve una instancia del jugador seleccionado por su id
    */
    Jugador* obtenerJugadorPorId(int id);

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