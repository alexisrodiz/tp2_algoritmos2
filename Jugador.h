#ifndef JUGADOR_H_
#define JUGADOR_H_

//#include "Jugadores.h"
#include "Carta.h"
#include "Lista.h"
#include "Mazo.h"



const int cantidadMaximaCartas = 3;

class Jugador{

private:

	Lista<Carta*>* cartas;

	unsigned int cantidadFichas;

	char fichaAsignada;

	std::string nombre;

	

		/*
	 * pre: tener cartas
	 * Post: devuelve la lista de cartas que tiene el jugador
	 */
	Lista<Carta*>* obtenerCartas();


public:

	Jugador(std::string nombre, char ficha);

	// Metodos
	//void establecerFichasTotal();
	/*
	 * Pre: existir jugadores
	 * Post: Se asigna la ficha
	 */
	//void ingresarFicha(Jugadores* ficha, unsigned int i);


	/*
	 * Pre: existir mazo
	 * Post: saca una carta del mazo y la guarda (si hay lugar)
	 */
	void sacarCartaMazo(Mazo* mazo);	

	/*
	 * Pre:
	 * Post: puede o no usar una carta y colocar la ficha en el tablero
	 */
	void realizarJugada();

	/*
	 * Post: devuelve el nombre del jugador
	 */
	std::string obtenerNombre();

	/*
	 * Post: devuelve la ficha que eligió el jugador
	 */
	char obtenerFicha();



	/*
	 * Post: muestra en pantalla las cartas en mano del jugador
	 */
	void imprimirCartasEnMano();

	/*
	 * Post: devuelve la carta en mano segun el valor pasado por parametro
	 */
	Carta* obtenerCartaPorValor(int valor);

};



#endif /* JUGADOR_H_ */


/*
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
	//void establecerJugador(unsigned int jugador);
	/*
	 * Pre:
	 * Post: Se establece la cantidad de fichas en total por jugador
	 */
	//void establecerFichasTotal();
	/*
	 * Pre: existir jugadores
	 * Post: Se asigna la ficha
	 */
	//void ingresarFicha();
	/*
	 * Pre: existir un jugador
	 * Post: se devuelve el numero del jugador correspondiente
	 */
	//unsigned int obtenerJugador();
	/*
	 * Pre: establecer las fichas totales
	 * Post: Devolver las fichas totales
	 */
	//unsigned int obtenerFichasTotal();
	/*
	 * Pre: Establecer ficha al jugador
	 * Post: Devuelve la ficha correspondiente al jugador indicado
	 */
	//std::string obtenerFicha();
	/*
	 * Pre: Asignaci�n de ficha
	 * Post: Controla que la ficha del 2do jugador no sea igual
	 * 		a la del primero
	 */
	/*
	bool controlFicha(std::string ficha[2]);
	void imprimirJugador();
};
*/

