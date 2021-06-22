#ifndef JUGADOR_H_
#define JUGADOR_H_

//#include "Jugadores.h"
#include <vector>
#include "Carta.h"
#include "Lista.h"
#include "Mazo.h"
#include "Coordenadas.h"




class Jugador{

private:
	int idJugador;

	Lista<Carta*>* cartas;

	int cantidadFichas;

	char fichaAsignada;

	std::string nombre;

	int cantidadMaximaCartas;

		/*
	 * pre: tener cartas
	 * Post: devuelve la lista de cartas que tiene el jugador
	 */
	Lista<Carta*>* obtenerCartas();


public:

	Jugador(std::string nombre, char ficha, int numeroJugador);

	/*
	 * Pre: existir mazo
	 * Post: saca una carta del mazo y la guarda (si hay lugar)
	 */
	void sacarCartaMazo(Mazo* mazo);

	
	/*
	 * Pre: tener cartas
	 * Post: Devuelve un vector de ids correspondientes a las cartas
	 * en mano del jugador
	 */
	std::vector<int> obtenerIdsCartas();

	/*
	 * Pre: tener cartas
	 * Post: Determina si el jugador tiene en mano la carta
	 * pasada por parametro (idCarta)
	 */
	bool verificarSiTieneCartaPorId(int idCarta);

	/*
	 * Pre:
	 * Post: solicita al jugador las coordenadas para colocar su ficha.
	 * Admite un parametro para personalizar el mensaje mostrado en pantalla
	 */
	Coordenadas* realizarJugada();

	/*
	 * Post: devuelve el nombre del jugador
	 */
	std::string obtenerNombre();

	/*
	 * Post: devuelve el id del jugador
	 */
	int obtenerId();

	/*
	 * Post: devuelve la ficha que eligió el jugador
	 */
	char obtenerFicha();

	/*
	 * pre: Tener fichas
	 * Post: Resta una unidad a la cantidad de fichas disponibles
	 */
	bool usarUnaFicha();

	/*
	 * Post: Quita n cantidad de fichas al jugador. Si se llega a 0, 
	 * no se quitan mas fichas
	 */
	void devolverFichas(int cantidadFichas);

	/*
	 * Post:
	 */
	int obtenerCantidadFichas();

	/*
	 * Pre:
	 * Post: Se establece la cantidad de fichas en total por jugador
	 */
	void establecerFichasIniciales(int cantidadFichasIniciales);


	/*
	 * Post: muestra en pantalla las cartas en mano del jugador
	 */
	void imprimirCartasEnMano();

	/*
	 * Post: devuelve la carta en mano segun el valor pasado por parametro
	 */
	Carta* obtenerCartaPorValor(int valor);



	~Jugador();

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

