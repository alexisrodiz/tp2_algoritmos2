#include "Tablero.h"
#include <iostream>

Tablero::Tablero(int fila, int columna) {

    this->fila = fila;
    this->columna = columna;
    int valor;

    Lista<int> *columnaPrincipal = new Lista<int>();
    this->filaPrincipal = new Lista<int>*();

    for (int i = 0; i < fila; i++)
    {
        this->filaPrincipal[i]->agregar(*columnaPrincipal);
    }

    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            this->filaPrincipal[i]->obtener(j);
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

Tablero::Tablero() {

    this->fila = 2;
    this->columna = 2;
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