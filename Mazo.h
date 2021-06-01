#ifndef MAZO_H_
#define MAZO_H_

#include "Lista.h"
#include "Carta.h"


class Mazo {
	
	private:
		
		Lista<Carta *>* listaCartas;

		
	public:
		
		/*
		* Post: Mazo creado con cuatro cartas especiales
		*/
		Mazo();
		
		/*
		* post: devuelve una carta aleatoria del mazo
		*/
		Carta* sacarCarta();
		
	
};

#endif  /* MAZO_H_ */



