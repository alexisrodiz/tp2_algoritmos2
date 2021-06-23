
#ifndef SRC_PLANO_H_
#define SRC_PLANO_H_
#include "Coordenadas.h"
/*Un plano es una estructura que representa una agrupacion de elementos en una distribucion plana,
 *cada elemento solo admite dos estados "true", "false", el plano se caracteriza por su largo y ancho,
 *cada el plano se crea con cada elemento en estado "false"
 */


class Plano{

	private:

	bool** plano;
	int columnas;
	int filas;
	//Coordenadas coordenadasElementoRaiz; //elemento raiz a partir del cual se analiza si el jugador gano

	/*
	 * Pre: largo > 0, ancho > 0
	 * Post: TDA Plano creado, con parametros: largo, ancho, y todos sus elementos en estado "false"
	 */
	Plano(int filas, int columnas);

	/*
	 * Pre:
	 * Post:
	 */
	bool obtenerValor(int coordenadaX, int coordenadaY);
	/*
	 *Pre: coordenadaX > 0, coordenadaY > 0
	 *Post:
	 */
	void guardarValor(int coordenadaX, int coordenadaY, bool nuevoValor);

	/*Pre: Existe el TDA plano
	 *Post: Libera los recursos del sistema
	 */
	~Plano();

};


#endif /* SRC_PLANO_H_ */
