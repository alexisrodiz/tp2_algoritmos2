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

	Coordenadas* coordUltimaJugada = NULL;

	Jugador* jugadorNuevo = new Jugador("A",'x',1);
	Jugador* jugadorNuevo2 = new Jugador("B",'o',2);


	Tablero* tableroNuevo = new Tablero(filas, columnas, profundidad, lineaGanadora);

	int coordenadaX;
	int coordenadaY;
	bool elJugadorGano = false;
	Coordenadas* coordenadaJugada = new Coordenadas(0,0,0);

	while (!elJugadorGano){
		std::cout <<"Jugador 1"<<std::endl<<std::endl;
		std::cout << "ingrese la coordenada X: ";
		std::cin >> coordenadaX;
		std::cout << std::endl;
		coordenadaJugada->guardarX(coordenadaX);


		std::cout << "ingrese la coordenada Y: ";
		std::cin >> coordenadaY;
		std::cout << std::endl;
		coordenadaJugada->guardarY(coordenadaY);

		tableroNuevo->marcarJugada(coordenadaJugada,jugadorNuevo);

		std::cout << std::endl;

		for (int j = 1; j <= 8; ++j) {

			for (unsigned int k = 1; k <= 8; ++k) {

				celdaAux = tableroNuevo->buscarCelda(1,j,k);

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

		//tableroNuevo->mostrarTableroXY();

		coordUltimaJugada = tableroNuevo->obtenerUltimaJugada();

		std::cout << "Ultima Jugada coordenadas: ";
		std::cout << coordUltimaJugada->obtenerX() << " ";
		std::cout << coordUltimaJugada->obtenerY() << " ";
		std::cout << coordUltimaJugada->obtenerZ() << " "<< std::endl;
		elJugadorGano = tableroNuevo->jugadorGano(jugadorNuevo);


		if (elJugadorGano){
			std::cout << " El jugador 1 gano" << std::endl;
			return 0;
		}
		/*************************************************/
		std::cout <<"Jugador 2"<<std::endl<<std::endl;

		std::cout << "ingrese la coordenada X: ";
		std::cin >> coordenadaX;
		std::cout << std::endl;
		coordenadaJugada->guardarX(coordenadaX);


		std::cout << "ingrese la coordenada Y: ";
		std::cin >> coordenadaY;
		std::cout << std::endl;
		coordenadaJugada->guardarY(coordenadaY);

		tableroNuevo->marcarJugada(coordenadaJugada,jugadorNuevo2);

		std::cout << std::endl;

		for (int j = 1; j <= 8; ++j) {

			for (unsigned int k = 1; k <= 8; ++k) {

				celdaAux = tableroNuevo->buscarCelda(1,j,k);

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

		//tableroNuevo->mostrarTableroXY();

		coordUltimaJugada = tableroNuevo->obtenerUltimaJugada();

		std::cout << "Ultima Jugada coordenadas: ";
		std::cout << coordUltimaJugada->obtenerX() << " ";
		std::cout << coordUltimaJugada->obtenerY() << " ";
		std::cout << coordUltimaJugada->obtenerZ() << " "<< std::endl;
		elJugadorGano = tableroNuevo->jugadorGano(jugadorNuevo2);


		if (elJugadorGano){
			std::cout << " El jugador 2 gano" << std::endl;
			return 0;
		}
	}

	//delete tableroNuevo;

    return 0;
}
