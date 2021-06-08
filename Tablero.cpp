#include "Tablero.h"
#include <iostream>

Tablero::Tablero(unsigned int fila, unsigned int columna, unsigned int profundidad) {

    this->numeroDeFila = fila;
    this->numeroDeColumna = columna;
    this->numeroDeProfundidad = profundidad;

    this->fila = new Lista< Lista< Lista<Celda*>* >* >();

    for (int x = 1; x <= this->numeroDeColumna; x++) {
        
        Lista< Lista<Celda*>* >* columna = new Lista< Lista<Celda*>* >();
        

        for (int y = 1; y <= this->numeroDeFila; y++) {

            Lista<Celda*>* profundidad = new Lista<Celda*>();

            for (int z = 1; z <= this->numeroDeProfundidad; z++) {
                
                Celda* celda = new Celda();
                profundidad->agregar(celda,z);

            }
            
            columna->agregar(profundidad,y);
                
        }

        this->fila->agregar(columna,x);
    }
    
};

void Tablero::mostrarTablero() {

    for (int x = 1; x <= obtenerNumeroDeColumna(); x++) {
        
        for (int y = 1; y <= obtenerNumeroDeFila(); y++) {
            
            for (int z = 1; z <= obtenerNumeroDeProfundidad(); z++) {

                std::cout << this->fila->obtener(x)->obtener(y)->obtener(z)->obtenerValorDeCelda() << std::endl;
            }
            
        }
        
    }

};

void Tablero::mostrarTableroXY() {

    unsigned int posicionFinalEnZ = obtenerNumeroDeProfundidad();
    unsigned int posicionInicialEnZ = 1;

    for (int x = 1; x <= obtenerNumeroDeColumna(); x++) {
        
        for (int y = 1; y <= obtenerNumeroDeFila(); y++) {

            bool filaLlena = false;
            std::string valorDeLaCelda;
            
            while (filaLlena == false || posicionInicialEnZ <= posicionFinalEnZ) {

                valorDeLaCelda = this->fila->obtener(x)->obtener(y)->obtener(posicionInicialEnZ)->obtenerValorDeCelda();
                valorDeLaCelda == " " ? posicionInicialEnZ++ : filaLlena = true;

            };

            std::cout << valorDeLaCelda << std::endl;
            
        }
        
    }

};

void Tablero::mostrarTableroYZ() {

    unsigned int posicionFinalEnX = 1;
    unsigned int posicionInicialEnX = obtenerNumeroDeColumna();

    for (int z = 1; z <= obtenerNumeroDeProfundidad(); z++) {

        for (int y = 1; y <= obtenerNumeroDeFila(); y++) {

            bool filaLlena = false;
            std::string valorDeLaCelda;

            while (filaLlena == false || posicionInicialEnX < posicionFinalEnX) {

                valorDeLaCelda = this->fila->obtener(posicionFinalEnX)->obtener(y)->obtener(z)->obtenerValorDeCelda();
                valorDeLaCelda == " " ? posicionInicialEnX-- : filaLlena = true;

            };

            std::cout << valorDeLaCelda << std::endl;

        }
        
    }
    
};

Lista< Lista< Lista<Celda*>* >* >* Tablero::obtenerFila() {

    return this->fila;

}

unsigned int Tablero::obtenerNumeroDeFila() {

    return this->numeroDeFila;

}

unsigned int Tablero::obtenerNumeroDeColumna() {

    return this->numeroDeColumna;

}

unsigned int Tablero::obtenerNumeroDeProfundidad() {

    return this->numeroDeProfundidad;

}