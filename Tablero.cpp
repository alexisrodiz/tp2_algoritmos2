#include "Tablero.h"
#include <iostream>

Tablero::Tablero(unsigned int fila, unsigned int columna) {

    this->fila = fila;
    this->columna = columna;
    int valor;

    Lista<int>* columnaPrincipal = new Lista<int>();
    *this->filaPrincipal = new Lista<int>();

    for (int i = 0; i < fila; i++)
    {
        this->filaPrincipal[i]->agregar(*columnaPrincipal);
    }

    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < j; j++)
        {
            this->filaPrincipal[i]->asignar(8,j);
        }
        
    }
    
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < j; j++)
        {
            std::cout << this->filaPrincipal[i]->obtener(j) << std::endl;
        }
        
    }
    

}