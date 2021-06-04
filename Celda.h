#ifndef CELDA_H_
#define CELDA_H_

#include <string>

class Celda {

    private:

        std::string valorDeLaCelda;
        std::string estadoDeLaCelda;

        /* Posibles valores de:
        *  valorDeLaCelda = " " | Jugador->marca
        *  estadoDeLaCelda = "vacia" | "llena"
        */
        
    public:

        /* Pre: 
        *  Pos: Crea una Celda con valorDeLaCelda = '' y estadoDeLaCelda = 'vacia'
        */
        Celda();

        /* Pre: 
        *  Pos: Retorna el valor de la Celda
        */
        std::string obtenerValorDeCelda();

        /* Pre: 
        *  Pos: Retorna el estado de la Celda
        */
        std::string obtenerEstadoDeCelda();

        /* Pre: 
        *  Pos: Destruye la Celda
        */
        ~Celda();

};

#endif /* CELDA_H_ */