#ifndef FICHA_H_
#define FICHA_H_

#include "Colores.h"

class Ficha {

    private:
    
        Colores* colorDeLaFicha;
        char valorDeLaFicha;

    public:

        /* Pre: Recibe un color
        *  Pos: Crea una Ficha con valorDeLaFicha = ' ' y con su color
        */
        Ficha(Colores* colorDeLaFicha, char valorDeLaFicha);

        /* Pre: 
        *  Pos: Retorna el color de la ficha
        */
        Colores* obtenerColorDeLaFicha();

        /* Pre: 
        *  Pos: Retorna el valor de la ficha
        */
        char obtenerValorDeLaFicha();

        /* Pre: 
        *  Pos: Destruye la Ficha
        */
        ~Ficha();

};

#endif /* Ficha_H_ */