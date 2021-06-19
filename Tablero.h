#ifndef TABLERO_H_
#define TABLERO_H_

#include "Lista.h"
#include "Jugador.h"
#include "Celda.h"
#include "Coordenadas.h"

class Tablero {

    private:

        Lista< Lista< Lista<Celda*>* >* >* fila;
        unsigned int numeroDeFila;
        unsigned int numeroDeColumna;
        unsigned int numeroDeProfundidad;

        unsigned int cantidadDeCeldasVacias; //agrege esto porque podria ser util


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


        /*Pre:
         *Post: Devuelve "true" en caso de haber al menos una celda vacia(no ocupada) en el tablero
         */
        bool hayCeldasVacias();

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
       //void marcarTablero(unsigned int fila, unsigned int columna, unsigned int profundidad, Jugador jugadorEnTurno);


        /* Pre: Recibe las coordenadas en donde el jugador quiere apilar su ficha
         * asi, como el Jugador en turno.
         * Pos: Devuelve "true" si pudo agregar la ficha al tablero exitosamente, devuelve false si
         * no hay espacio disponible, y por ende no pudo agregar la ficha al tablero, (Nota: las fichas
         * se agregan en forma apilada las fichas de cada jugador en la posicion
         * (coordenadaJugada->obtenerX(), coordenadaJugada->obtenerY(),z) del volumen del tablero, siendo
         * z la primera celda no ocupada contando desde abajo hacia arriba)
         */

        bool marcarJugada(Coordenadas* coordenadaJugada, Jugador* jugadorEnTurno);

        /* Pre: Recibe el jugador en turno y la posicion valida donde quiere quiere colocar su ficha
        *  Pos: Verifica si un jugador gana
        */
        //void verificarGanador(Jugador jugadorEnTurno);


        /* Pre: Recibe el jugador en turno "jugadorEnturno" y la longitud de la linea a chequear
         * "longitudDeLineaAChequear", esta ultima debe ser un valor mayor a 1
         * Post: devuelve "true" en caso de que el jugador "jugadorEnTurno"(que contiene sus fichas
         * respectivas internamente) haya ganado la partida, devuelve false en caso de que no haya ganado
         */
        bool jugadorGano(Jugador* jugadorEnTurno, unsigned int longitudDeLineaAChequear);

        /*Nota: No usar, el metodo valido es: marcarJugada
         *Pre: coordenadas de posicion validas, ficha valida
         *Post: Si hay espacio, es decir se pueden seguir apilando fichas en la columna tridimensional cuya
         base es: (fila,columna,0) se agrega "ficha" en el primer espacio disponible en esa columna tridimensional
         contando desde abajo hacia arriba y se devuelve "true", en caso de no haber espacio libre, no se agrega nada
         y se devuelve "false"
         */
        bool agregarFicha(unsigned int fila, unsigned int columna, char ficha);

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
