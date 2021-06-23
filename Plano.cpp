#include "Plano.h"


	Plano:: Plano(int filas, int columnas){

		this->filas = filas;
		this->columnas = columnas;
		this->plano = new bool*[filas];

		for (int i = 0; i < filas ; ++i) {
			this->plano[i] = new bool[columnas];
		}
		for (int i = 0; i < filas; ++i) {
			for (int j = 0; j < columnas; ++j) {
				this->plano[filas][columnas] = false;
			}
		}
	}

	bool Plano:: obtenerValor(int coordenadaX, int coordenadaY){
		return this->plano[coordenadaX][coordenadaY];
	}

	void Plano:: guardarValor(int coordenadaX, int coordenadaY, bool nuevoValor){
		this->plano[coordenadaX][coordenadaY] = nuevoValor;
	}

	Plano::~Plano(){

		for (int i = 0; i < filas ; ++i) {
			delete []this->plano[i];
		}
		delete this->plano;

	}

