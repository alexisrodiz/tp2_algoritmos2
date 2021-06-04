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
        *  Pos: Muestra el tablero por consola de la cara YZ
        */
        void marcarTablero(unsigned int columna, unsigned int profundidad, Jugador jugador);

        /* Pre: Recibe el jugador en turno y la posicion valida donde quiere quiere colocar su ficha
        *  Pos: Verifica si un jugador gana
        */
        void verificarGanador(unsigned int fila, unsigned int columna, unsigned int profundidad, Jugador jugador);

        /* Pre:
        *  Pos: Crea un bitmap del tablero
        */
        void crearBitMap();
        
        /* Pre:
        *  Pos: Detruye el tablero
        */
        ~Tablero();

};

#endif /* TABLERO_H_ */