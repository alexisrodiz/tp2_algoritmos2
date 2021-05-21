#include "Tablero.h"
#include <iostream>

int main() {

    int fil = 6;
    int col = 6;
    int prof = 6;
    //Tablero *tablero = new Tablero(fila, col);

    //std::cout << "Termino" << std::endl;

    Lista< Lista< Lista<int> > > *fila = new Lista< Lista< Lista<int> > >();
    
    

    //creo tablero
    for (int x = 0; x < col; x++)
    {
        Lista< Lista<int> > *columna = new Lista< Lista<int> >();
        fila->agregar(*columna,x);

        for (int y = 0; y < fil; y++)
        {
            Lista<int> *profundidad = new Lista<int>();
            fila->obtener(x).agregar(*profundidad,y);
                
        }
        
    }

    //relleno tablero
    for (int x = 0; x < fil; x++)
    {
        
        for (int y = 0; y < col; y++)
        {
            for (int z = 0; z < prof; z++)
            {
                fila->obtener(x).obtener(y).asignar(8,z);
            }
            
        }
        
    }

    //muestro tablero
    for (int x = 0; x < fil; x++)
    {
        
        for (int y = 0; y < col; y++)
        {
            for (int z = 0; z < prof; z++)
            {
                std::cout << fila->obtener(x).obtener(y).obtener(z) << std::endl;
            }
            
        }
        
    }

    std::cout << "Fin" << std::endl;
    
    return 0;
}