#ifndef CELDA_H_
#define CELDA_H_

#include "Ficha.h"
#include "Coordenadas.h"

class Celda {

    private:

        Ficha* ficha;
        bool estaVacia;
        Coordenadas* coordenadas;
        Celda* vecinas[3][3][3];

        /* Pre: 
        *  Pos: Retorna la Ficha
        */
        Ficha* obtenerFicha();
        
    public:

        /* Pre: 
        *  Pos: Crea una Celda con su Ficha y estaVacia = true
        */
        Celda();

        /* Pre: 
        *  Pos: Cambia el puntero ficha de Null a una Ficha
        */
        void colocarFicha(Ficha* fichaDeJugador);

        /* Pre: 
        *  Pos: Vacia la Celda apuntado ficha a NULL y borrando la Ficha
        */
        void vaciarCelda();

        /* Pre: 
        *  Pos: Retorna el valor de la Celda
        */
        char obtenerValorDeCelda();

        /* Pre: 
        *  Pos: Cambia el estado actual de la Celda
        */
        void cambiarEstadoDeCelda();

        /* Pre: 
        *  Pos: Retorna el estado de la Celda, estaVacia = true | false
        */
        bool obtenerEstaVacia();

        /* Pre: 
        *  Pos: Destruye la Celda
        */
        ~Celda();

};

#endif /* CELDA_H_ */
