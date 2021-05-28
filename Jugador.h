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

	// Metodos
	/*
	 * Pre: indicar el numero del jugador
	 * Post: establece el numero al jugador correspondiente
	 */
	void establecerJugador(unsigned int jugador);
	/*
	 * Pre:
	 * Post: Se establece la cantidad de fichas en total por jugador
	 */
	void establecerFichasTotal();
	/*
	 * Pre: existir jugadores
	 * Post: Se asigna la ficha
	 */
	void ingresarFicha();
	/*
	 * Pre: existir un jugador
	 * Post: se devuelve el numero del jugador correspondiente
	 */
	unsigned int obtenerJugador();
	/*
	 * Pre: establecer las fichas totales
	 * Post: Devolver las fichas totales
	 */
	unsigned int obtenerFichasTotal();
	/*
	 * Pre: Establecer ficha al jugador
	 * Post: Devuelve la ficha correspondiente al jugador indicado
	 */
	std::string obtenerFicha();
	/*
	 * Pre: Asignación de ficha
	 * Post: Controla que la ficha del 2do jugador no sea igual
	 * 		a la del primero
	 */
	bool controlFicha(std::string ficha[2]);
	void imprimirJugador();
};



#endif /* JUGADOR_H_ */
