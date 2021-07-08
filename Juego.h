#ifndef JUEGO_H_
#define JUEGO_H_

#include "Tablero.h"
#include "Jugador.h"
#include "Lista.h"
#include "Mazo.h"
#include "Coordenadas.h"
#include "EasyBMP_BMP.h"
#include "ExportarTableroBMP.h"
#include "Colores.h"
#include "Ficha.h"


class Juego {

    private:

    Tablero* tablero;

    ExportarTableroBMP* exportarTablero;

    Lista<Jugador *>* jugadores;

    Lista<Ficha*>* fichasUtilizadas;

    Lista<Colores*>* coloresGenerados;

    Mazo* mazo;

    unsigned int cantidadFichasPorJugador;

    unsigned int porcentajeQuitarFichas;

    unsigned int cantidadFichasADevolverJugador;

    unsigned int nEnLinea;


    public:


    /*
    * post: Crea un juego
    */
    Juego();

    /*
    * pre: jugadores crados
    * post: calcula la cantidad de fichas que le corresponde a cada jugador, teniendo
    * en cuenta la cantidad de jugadores y el tamaño del tablero
    */
    void calcularCantidadFichasPorJugador();

    /*
    * pre: jugadores crados
    * post: calcula la cantidad de fichas que deberia devolver un jugador en base a un
    * porcentaje fijado, cuando usan en su contra la carta "Devolver fichas"
    */
    int calcularCantidadFichasADevolverJugador();

    /*
    * pre: jugadores crados
    * post: chequea si el valor de la ficha ya fue utilizada en el juego
    */
    bool verificarFichaValorFueUtilizada(char ficha);
    
    /*
    * post: Chequea que las coordenadas sean validas y si es asi marca el tablero
    */
    void inicarJugada(Jugador* jugadorActual);

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
    * post: Solicita nombre y ficha para crear y agregar los jugadores a la lista
    */
    void agregarTablero();

    /*
    * post: Recorre la lista de jugadores y si llega al final, la inicia de nuevo
    */
    void recorrerListaDeJugadores();

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