#ifndef EXPORTAR_TABLERO_BMP_H_
#define EXPORTAR_TABLERO_BMP_H_

#include "EasyBMP.h"
#include "EasyBMP_Geometry.h"
#include "EasyBMP_Font.h"
#include "Lista.h"
#include "Tablero.h"
#include "Coordenadas.h"
#include "Ficha.h"
#include "Celda.h"

class ExportarTableroBMP{
    private:
    unsigned int paddingX;
    unsigned int paddingY;
    unsigned int ancho;
    unsigned int alto;
    unsigned int profundidadColor;
    unsigned int margenX;
    unsigned int margenY;
    unsigned int distanciaEntreFichas;
    unsigned int alturaFicha;
    unsigned int anchoFicha;
    std::string nombreArchivo;
    Lista< Lista< Lista<Celda*>* >* >* filaTablero;
    Tablero* tablero;

    public:

    /*
    * post: Crea la instancia para exportar el tablero en formato BMP
    */
    ExportarTableroBMP(
        unsigned int ancho, 
        unsigned int alto, 
        unsigned int profundidadColor, 
        unsigned int margenX,
        unsigned int margenY,
        Tablero* tablero
        );


    /*
    * pre: existir el objeto Tablero
    * post: Exporta el tablero en un archivo formato BMP. Vista superior
    */
    void exportarTableroXY(int id);



    
};

#endif