#ifndef CARTA_H_
#define CARTA_H_
#include <string>
#include "Lista.h"

class Carta {
	
	private:
		
		int valor;
		
		std::string tipo;
		
	public:
		
		Carta(int valor, std::string tipo);
		
		
		/*
		* Pre:
		* Post: Devuelve el valor de la carta
		*/
		int obtenerValor();
		
		
		/*
		* Pre:
		* Post: Devuelve el nombre de la carta
		*/
		std::string obtenerTipo();

	
};

#endif  /* CARTA_H_ */



