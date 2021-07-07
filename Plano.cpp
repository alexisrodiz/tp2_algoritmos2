#include "Plano.h"


	Plano:: Plano(unsigned int filas, unsigned int columnas){

		this->filas = filas;
		this->columnas = columnas;
		this->plano = new char*[filas];

		for (int unsigned i = 0; i < filas ; ++i) {
			this->plano[i] = new char[columnas];
		}
		for (int unsigned i = 0; i < filas; ++i) {
			for (int unsigned j = 0; j < columnas; ++j) {
				this->plano[filas][columnas] = ' ';
			}
		}
	}

	char Plano:: obtenerValor(int coordenadaX, int coordenadaY){
		return this->plano[coordenadaX][coordenadaY];
	}

	void Plano:: guardarValor(int coordenadaX, int coordenadaY, char nuevoValor){
		this->plano[coordenadaX][coordenadaY] = nuevoValor;
	}

	Plano::~Plano(){

		for (int i = 0; i < filas ; ++i) {
			delete []this->plano[i];
		}
		delete this->plano;

	}

