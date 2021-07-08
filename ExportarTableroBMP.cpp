#include <iostream>
#include "ExportarTableroBMP.h"

using namespace std;

ExportarTableroBMP::ExportarTableroBMP(
        unsigned int ancho, 
        unsigned int alto, 
        unsigned int profundidadColor, 
        unsigned int margenX,
        unsigned int margenY,
        Tablero* tablero
        ) {
    BMP imagen;
    this->ancho = ancho;
    this->alto = alto;
    this->profundidadColor = profundidadColor;
    this->margenX = margenX;
    this->margenY = margenY;
    this->tablero = tablero;
    this->alturaFicha = 15;
    this->imagen.SetSize(this->ancho, this->alto);
    this->imagen.SetBitDepth(this->profundidadColor);
    this->filaTablero = new Lista< Lista< Lista<Celda*>* >* >();
}

void ExportarTableroBMP::exportarTableroXY(){
    Ficha* ficha;
    RGBApixel color; // ver de usar ficha->obtenerColorDeLaFicha()
    color.Red = 50; color.Green = 50; color.Blue = 192; color.Alpha = 0;
    this->filaTablero = this->tablero->obtenerFila();
    this->filaTablero->iniciarCursor();
    while (this->filaTablero->avanzarCursor()) {
        
        Lista< Lista<Celda*>* >* columna = this->filaTablero->obtenerCursor();
        columna->iniciarCursor();
        while (columna->avanzarCursor()) {
            
            Lista<Celda*>* profundidad = columna->obtenerCursor();
            profundidad->iniciarCursor();

            //profundidad->avanzarCursor();

            Celda* celda = NULL;
            while(profundidad->avanzarCursor()){
                celda = profundidad->obtenerCursor();
                //verificar que se obtiene la ultima celda apilada en Z
            }

            //ficha = celda->obtenerFicha();
            char* letra = new char;
            //letra[0] = ficha->obtenerValorDeLaFicha();
            letra[0] = celda->obtenerValorDeCelda();

            PrintString(this->imagen,
                        letra, 
                        profundidad->obtenerCursor()->obtenerCoordenadas()->obtenerX(),
                        profundidad->obtenerCursor()->obtenerCoordenadas()->obtenerY(), 
                        this->alturaFicha,
                        color );

            /*DrawArc(this->imagen,
                    profundidad->obtenerCursor()->obtenerCoordenadas()->obtenerX(),
                    profundidad->obtenerCursor()->obtenerCoordenadas()->obtenerY(),
                    5, 
                    0,
                    360,
                    Temp);*/

            /*this->imagen.SetPixel(
                profundidad->obtenerCursor()->obtenerCoordenadas()->obtenerX(),
                profundidad->obtenerCursor()->obtenerCoordenadas()->obtenerY(),
                Temp);*/
        };
        
        this->imagen.WriteToFile("archivo.bmp");

    };
}