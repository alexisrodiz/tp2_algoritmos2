#ifndef TABLERO_H_
#define TABLERO_H_

#include "Lista.h"
#include "Jugador.h"
#include "Celda.h"

class Tablero {

    private:

        Lista< Lista< Lista<Celda*>* >* >* fila;
        unsigned int numeroDeFila;
        unsigned int numeroDeColumna;
        unsigned int numeroDeProfundidad;


        /*  Ver para uso recursivo
        *   Discutir el tema de un tablero espejo para recorrer con la misma 
        *   funcion verificarDiagonal el las diagonales de derecha a izquierda
        */

        /* Pre: Recibe posiciones finales validas y el jugador en turno
        *  Pos: Recorre una cara del tablero y verifica fichas horizontalmente
        */
        void verificarHorizontal(unsigned int posicionFinalHorizontal, unsigned int posicionFinalVertical, Jugador jugador);

        /* Pre: Recibe posiciones finales validas y el jugador en turno
        *  Pos: Recorre una cara del tablero y verifica fichas verticalmente
        */
        void verificarVertical(unsigned int posicionFinalVertical, unsigned int posicionFinalHorizontal, Jugador jugador);

        /* Pre: Recibe posiciones finales validas y el jugador en turno
        *  Pos: Recorre una cara del tablero y verifica fichas en diagonal
        */
        void verificarDiagonal(unsigned int posicionFinalHorizontal, unsigned int posicionFinalVertical, Jugador jugador);

    public:

        /* Pre: Recibe datos validos
        *  Pos: Crea un tablero de 3 dimensiones, inicializando los casilleros en 0
        */
        Tablero(unsigned int fila, unsigned int columna, unsigned int profundidad);

        /* Pre:
        *  Pos: Muestra el tablero por consola
        *
        *  Es solo de prueba -> borrar luego
        */
        void mostrarTablero();
        

       /* Pre:
        *  Pos: Muestra el tablero por consola de la cara XY
        */
        void mostrarTableroXY();

        /* Pre:
        *  Pos: Muestra el tablero por consola de la cara YZ
        */
        void mostrarTableroYZ();

        /* Pre: Recibe el jugador en turno y la posicion valida donde quiere quiere colocar su ficha
        *  Pos: Marca en el tablero la ficha correspondiente al jugador
        */
        void marcarTablero(unsigned int fila, unsigned int columna, unsigned int profundidad, Jugador jugadorEnTurno);

        /* Pre: Recibe el jugador en turno y la posicion valida donde quiere quiere colocar su ficha
        *  Pos: Verifica si un jugador gana
        */
        void verificarGanador(Jugador jugadorEnTurno);

        /* Pre:
        *  Pos: Crea un bitmap del tablero
        */
        void crearBitMap();

        /* Pre:
        *  Pos: Retorna la fila principal del Tablero
        */
        Lista< Lista< Lista<Celda*>* >* >* obtenerFila();

        /* Pre:
        *  Pos: Retorna el numero de fila
        */
        unsigned int obtenerNumeroDeFila();

        /* Pre:
        *  Pos: Retorna el numero de columna
        */
        unsigned int obtenerNumeroDeColumna();

        /* Pre:
        *  Pos: Retorna el numero de profundidad
        */
        unsigned int obtenerNumeroDeProfundidad();
        
        /* Pre:
        *  Pos: Detruye el tablero
        */
        ~Tablero();

};

#endif /* TABLERO_H_ */