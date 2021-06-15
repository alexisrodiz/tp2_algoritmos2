#ifndef JUEGO_H_
#define JUEGO_H_

#include <vector>
#include "Jugador.h"
#include "Lista.h"

class Juego {

    private:

    std::vector<char> fichasUtilizadas;

    Lista<Jugador *>* jugadores;

    public:


    /*
    * post: Crea un juego
    */
    Juego();


    /*
    * post: Solicita nombre y ficha para crear y agregar los jugadores a la lista
    */
    void agregarJugadores();

    /*
    * post: Inicia el Juego
    */
    void iniciar();


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