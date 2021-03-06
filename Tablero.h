#ifndef TABLERO_H_
#define TABLERO_H_

#include "Lista.h"
#include "Jugador.h"
#include "Celda.h"
#include "Coordenadas.h"
#include "Plano.h"


class Tablero {

    private:

        Lista< Lista< Lista<Celda*>* >* >* fila;
        unsigned int numeroDeFila;
        unsigned int numeroDeColumna;
        unsigned int numeroDeProfundidad;

        unsigned int longitudDeLineaGanadora;
        unsigned int cantidadDeCeldasVacias; //agrege esto porque podria ser util
        Coordenadas* coordenadasDeUltimaCelda;


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

        /* Pre: Recibe datos validos de dimensiones mayores a 0 y una longitudLineaGanadora mayor a 0
        *  Pos: Crea un tablero de 3 dimensiones, con todas las celdas vacias, y con longitud
        *  de la linea ganadora 'longitudLineaGanadora'
        */
        Tablero(unsigned int fila, unsigned int columna, unsigned int profundidad,
        		unsigned int longitudLineaGanadora);


        /*Pre:
         *Post: Devuelve "true" en caso de haber al menos una celda vacia(no ocupada) en el tablero
         */
        bool hayCeldasVacias();

        /* Pre:
        *  Pos: Muestra el tablero por consola
        *
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
         * Nota: las coordenadas se encuentran
         * en el rango (1,1,1)--> (numeroDeFila, NumeroDeColumna, numeroDeProfundidad)
         */

        bool marcarJugada(Coordenadas* coordenadaJugada, Jugador* jugadorEnTurno);

        /*Pre: Debe haber realizado al menos una jugada en el juego
         *Post:Devuelve las coordenadas de la ultima jugada realizada;
         *Las coordenadas estan el rango (1,1,1)--> (numeroDeFila, NumeroDeColumna, numeroDeProfundidad)
         */

       Coordenadas* obtenerUltimaJugada();

        /*Pre: Debe haber realizado al menos una jugada en el juego
         *Post: Borra todos los datos de la ultima jugada, quedando la celda en estado vacante
         *Nota: el atributo coordenadasDeUltimaCelda no se actualiza.
         */
        void borrarUltimaJugada();


        /* Pre: Recibe el jugador en turno y la posicion valida donde quiere quiere colocar su ficha
        *  Pos: Verifica si un jugador gana
        */
        //void verificarGanador(Jugador jugadorEnTurno);


        /* Pre: Recibe el jugador en turno "jugadorEnturno" inicializado
         * Post: devuelve "true" en caso de que el jugador "jugadorEnTurno"(que contiene sus fichas
         * respectivas internamente) haya ganado la partida, devuelve false en caso de que no haya ganado
         */
        bool jugadorGano(Jugador* jugadorEnTurno);

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
        
        /*Pre:
         *Post: Retorna la longitud de linea ganadora
         */

        unsigned int obtenerLongitudLineaGanadora();


        /*
         *Pre: coordenadas->obtenerX(), coordenadas->obtenerX(), coordenadas->obtenerX()
         *en el rango de las dimensiones del tablero respectivas
         *Post: devuelve el puntero a la celda cuyas "coordenadas" ingresaron como parametro
         */

        Celda* buscarCelda(unsigned int x, unsigned int y, unsigned int z);


        /*Pre: Tablero creado.
         *Post: Crea y devuelve un puntero a Plano con un z elegido, este plano es una representacion de un plano del tablero
         *con Z = 1 unicamente muestra los caracteres que representan a las fichas de los jugadores, y muestra
         *caracteres vacio/s ' ' en aquellas posiciones en donde no hay fichas.
         *
         *El sistema de coordenadas es (x,y)
         *     (8,1)....................(8,8)
         *     .
         *     .
         *     (1,1)....................(1,8)   todo en el plano z = 1
         */
        Plano* generarPlanoXY(int z);

        /*Pre: Tablero creado.
         *Post: Crea y devuelve un puntero a Plano con un x elegido, este plano es una representacion de un plano del tablero
         *con Z = 1 unicamente muestra los caracteres que representan a las fichas de los jugadores, y muestra
         *caracteres vacio/s ' ' en aquellas posiciones en donde no hay fichas.
         *
         *El sistema de coordenadas es (y,z)
         *     (8,1)....................(8,8)
         *     .
         *     .
         *     (1,1)....................(1,8)   todo en el plano z = 1
         */
        Plano* generarPlanoYZ(int x);
        																																					/* Pre:
        *  Pos: Destruye el tablero
        */
        ~Tablero();

};

#endif /* TABLERO_H_ */
