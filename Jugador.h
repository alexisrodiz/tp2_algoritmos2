#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <vector>
#include "Carta.h"
#include "Lista.h"
#include "Mazo.h"
#include "Coordenadas.h"
#include "Ficha.h"



class Jugador{

private:
	int idJugador;

	Lista<Carta*>* cartas;

	Ficha* ficha;

	int cantidadFichas;

	std::string nombre;

	int cantidadMaximaCartas;

	/*
	 * pre: tener cartas
	 * Post: devuelve la lista de cartas que tiene el jugador
	 */
	Lista<Carta*>* obtenerCartas();


public:

	Jugador(std::string nombre, Ficha* ficha, int numeroJugador);

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
	 * Post: Crea la coordenada de la jugada y la retorna
	 */
	Coordenadas* realizarJugada(int x, int y);

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
	Ficha* obtenerFicha();

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