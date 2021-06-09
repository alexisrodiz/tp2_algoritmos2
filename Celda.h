#ifndef CELDA_H_
#define CELDA_H_

class Celda {

    private:

        char valorDeLaCelda;
        bool estaVacia;

        /* Posibles valores de:
        *  valorDeLaCelda = " " | Jugador->marca
        *  estaVacia = true | false
        */
        
    public:

        /* Pre: 
        *  Pos: Crea una Celda con valorDeLaCelda = '' y estadoDeLaCelda = 'vacia'
        */
        Celda();

        /* Pre: 
        *  Pos: Cambia el valor actual de la Celda
        */
        void cambiarValorDeCelda(char valorNuevo);

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