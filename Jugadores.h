/*
 * Jugadores.h
 *
 *  Created on: 8 jun. 2021
 *      Author: caroj
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_


class Jugadores {

    private:

        char valorDeFicha;

        /* Posibles valores de:
        *  valorDeFicha = " " | Jugador->ficha elegida
        */

    public:

        /* Pre:
        *  Pos: Crea una Celda con valorDeLaCelda = '' y estadoDeLaCelda = 'vacia'
        */
        Jugadores();

        /* Pre:
        *  Pos: Retorna el valor de la Celda
        */
        char obtenerValorDelJugador();

        bool verificarFicha(char ficha);
        void asignarFicha(char ficha);

        /* Pre:
        *  Pos: Destruye la Celda
        */
        ~Jugadores();

};



#endif /* JUGADORES_H_ */
