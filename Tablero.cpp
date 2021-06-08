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
                std::cout << "profundidad " << profundidad->obtener(z) << std::endl;
                std::cout << std::endl;
            }
            
            columna->agregar(profundidad,y);
            std::cout << "columna " << columna->obtener(y) << std::endl;
            std::cout << std::endl;
                
        }

        this->fila->agregar(columna,x);
        std::cout << "fila " << this->fila->obtener(x) << std::endl;
        std::cout << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << std::endl;

    }
    
};

void Tablero::mostrarTablero() {

    for (int x = 1; x <= this->numeroDeColumna; x++) {
        
        for (int y = 1; y <= this->numeroDeFila; y++) {
            
            for (int z = 1; z <= this->numeroDeProfundidad; z++) {

                std::cout << this->fila->obtener(x)->obtener(y)->obtener(z) << std::endl;
            }
            
        }
        
    }

};