/*
 * Jugador.h
 *
 *  Created on: 28 may. 2021
 *      Author: caroj
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

class Jugador{

private:
	unsigned int nroJugador;

public:
	Jugador();
	unsigned int establecerJugador(unsigned int jugador);
	void imprimirJugador();
};



#endif /* JUGADOR_H_ */
