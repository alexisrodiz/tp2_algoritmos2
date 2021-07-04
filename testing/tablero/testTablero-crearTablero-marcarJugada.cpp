#include <iostream>
#include "Tablero.h"
#include "Jugador.h"
#include "Coordenadas.h"

void accionCorrecta (std::string accion){
	std::cout << "Se pudo : "<<accion << " correctamente" << std::endl;
}

void error (std::string accion){
	std::cout << "error: No se pudo  " << accion <<std::endl;
}

void resultadoAccion(bool resultadoDeAccion, std::string accion){
	if (resultadoDeAccion){
		accionCorrecta(accion);
	}
	else{
		error(accion);
	}
}

int main() {

	/**************Parametros tablero****************/
	int filas = 8;
	int columnas = 8;
	int profundidad = 8;
	int lineaGanadora = 4;
	/*************************************************/

	/*********Coordenadas Primera Ficha***************/
	int coordX = 1;
	int coordY = 3;
	int coordZ = 1;

	/*************************************************/

	/*********Variables usadas en la prueba***********/
	bool sePudoMarcarJugada = false;

	Celda* celdaAux = NULL;

	Coordenadas* coordenadaPrueba = new Coordenadas(coordX,coordY,coordZ);

	Jugador* jugadorNuevo = new Jugador("A",'x',1);


	Tablero* tableroNuevo = new Tablero(filas, columnas, profundidad, lineaGanadora);

	/****************************************************/

	/*********Prueba# 1: Agregar una ficha y comprobar si se guardo en la pos indicada*/
	/*********Nota: El tablero esta vacio**********************************************/

	std::cout << "1. Agregar una ficha y comprobar si se guardo en la pos indicada" << std::endl <<std::endl;
	sePudoMarcarJugada = tableroNuevo->marcarJugada(coordenadaPrueba, jugadorNuevo);

	resultadoAccion(sePudoMarcarJugada, "marcar Jugada");

	celdaAux = tableroNuevo->buscarCelda(1,3,1); //primera posicion;

	std::cout <<"agregada la ficha: " <<celdaAux->obtenerFicha()->obtenerValorDeLaFicha() << std::endl;

	//impresion lista profundidad

	for (int i = 8; i >= 1; --i) {

		for (unsigned int j = 1; j <= 8; ++j) {

			celdaAux = tableroNuevo->buscarCelda(1,j,i);

			if (celdaAux->obtenerFicha()!= NULL){
				std::cout  <<celdaAux->obtenerFicha()->obtenerValorDeLaFicha();
				}
			else{
				std::cout << "." ;
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	/***********************************************************************************/


	/*********Prueba# 2: Agregar 7 fichas mas en la misma profundidad hasta llenarla****/
	std::cout << "2. Agregar 7 fichas mas en la misma lista profundidad hasta llenarla" << std::endl <<std::endl;

	for (unsigned int i = 2; i <= 8; ++i) {
		sePudoMarcarJugada = tableroNuevo->marcarJugada(coordenadaPrueba, jugadorNuevo);
		resultadoAccion(sePudoMarcarJugada, "marcar Jugada");
		celdaAux = tableroNuevo->buscarCelda(1,3,i);
		std::cout <<"agregada la ficha: " <<celdaAux->obtenerFicha()->obtenerValorDeLaFicha() << std::endl;
	}

	std::cout << std::endl;

	for (int i = 8; i >= 1; --i) {

		for (unsigned int j = 1; j <= 8; ++j) {

			celdaAux = tableroNuevo->buscarCelda(1,j,i);

			if (celdaAux->obtenerFicha()!= NULL){
				std::cout  <<celdaAux->obtenerFicha()->obtenerValorDeLaFicha();
				}
			else{
				std::cout << "." ;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	/***********************************************************************************/

	/*********Prueba# 3: Agregar 1 fichas mas en la misma profundidad ya llena**********/
	std::cout << "3. Agregar 1 fichas mas en la misma profundidad ya llena" << std::endl <<std::endl;

	std::cout << std::endl;
	sePudoMarcarJugada = tableroNuevo->marcarJugada(coordenadaPrueba, jugadorNuevo);
	resultadoAccion(sePudoMarcarJugada, "marcar Jugada");

	std::cout << "Fin programa" << std::endl;
	std::cout << std::endl;



	/************************************************************************************/


    return 0;
}
