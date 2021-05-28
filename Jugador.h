/*
 * Jugador.h
 *
 *  Created on: 28 may. 2021
 *      Author: caroj
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>

class Jugador{

private:
	unsigned int nroJugador;
	std::string fichaAsignada[2];
	std::string carta;
	unsigned int cantidadFichas;

public:
	Jugador();

	void establecerJugador(unsigned int jugador);
	void establecerFichasTotal();
	void ingresarFicha();
	unsigned int obtenerJugador();
	unsigned int obtenerFichasTotal();
	std::string obtenerFicha();
	bool controlFicha(std::string ficha[2]);
	void imprimirJugador();
};



#endif /* JUGADOR_H_ */
