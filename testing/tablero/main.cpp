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


	Tablero* tableroNuevo = new Tablero(filas, columnas, profundidad, lineaGanadora);

	int coordenadaX;
	int coordenadaY;
	bool elJugadorGano = false;
	Coordenadas* coordenadaJugada = new Coordenadas(0,0,0);

	while (!elJugadorGano){
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

		coordUltimaJugada = tableroNuevo->obtenerUltimaJugada();

		std::cout << "Ultima Jugada coordenadas: ";
		std::cout << coordUltimaJugada->obtenerX() << " ";
		std::cout << coordUltimaJugada->obtenerY() << " ";
		std::cout << coordUltimaJugada->obtenerZ() << " "<< std::endl;
		elJugadorGano = tableroNuevo->jugadorGano(jugadorNuevo);


		if (elJugadorGano){
			std::cout << " El jugador gano" << std::endl;
		}

	}

    return 0;
}
