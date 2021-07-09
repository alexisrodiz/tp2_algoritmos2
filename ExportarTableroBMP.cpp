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
    //BMP imagen;
    this->ancho = ancho;
    this->alto = alto;
    this->profundidadColor = profundidadColor;
    this->margenX = margenX;
    this->margenY = margenY;
    this->tablero = tablero;
    this->alturaFicha = 25;
    this->anchoFicha = 25;
    this->paddingX = 30;
    this->paddingY = 30;
    
    this->filaTablero = new Lista< Lista< Lista<Celda*>* >* >();
}

void ExportarTableroBMP::exportarTableroXY(int id){
    BMP imagen;
    imagen.SetSize(this->ancho, this->alto);
    imagen.SetBitDepth(this->profundidadColor);
    char nombreArchivo[20];
    Ficha* ficha;
    sprintf(nombreArchivo, "tablero%i.bmp", id);
    //cout << "archivo: " << nombreArchivo << endl;
    RGBApixel colorLineas;
    colorLineas.Red = 0; colorLineas.Green = 0; colorLineas.Blue = 0; colorLineas.Alpha = 0;
    RGBApixel color; // ver de usar ficha->obtenerColorDeLaFicha()
    color.Red = 50; color.Green = 50; color.Blue = 192; color.Alpha = 0;
    this->filaTablero = this->tablero->obtenerFila();


    for (int i = 0; i <= this->tablero->obtenerNumeroDeFila() ; i++) {
        // Horizontales
        DrawLine(imagen, 
            this->margenX, // fromX
            this->margenY + (this->alturaFicha + this->paddingY) * i , //fromY
            this->margenX + this->tablero->obtenerNumeroDeColumna() * (this->anchoFicha + this->paddingX ), // toX
            this->margenY + (this->alturaFicha + this->paddingY) * i, // toY
            colorLineas);
       for (int j = 0; j <= this->tablero->obtenerNumeroDeColumna() ; j++) {
           // Verticales
            DrawLine(imagen, 
                this->margenX + (this->anchoFicha + this->paddingX) * j, // fromX
                this->margenY, //fromY
                this->margenX + (this->anchoFicha + this->paddingX) * j, // toX
                this->margenY + this->tablero->obtenerNumeroDeFila() * (this->alturaFicha + this->paddingY), // toY
                colorLineas);
       }
       
    }


    this->filaTablero->iniciarCursor();
    while (this->filaTablero->avanzarCursor()) {

        Lista< Lista<Celda*>* >* columna = this->filaTablero->obtenerCursor();
        columna->iniciarCursor();
        while (columna->avanzarCursor()) {
            Lista<Celda*>* profundidad = columna->obtenerCursor();
            profundidad->iniciarCursor();
            // Ultima celda apilada en profundidad (eje z)
            Celda* celdaTope = NULL;
            while(profundidad->avanzarCursor() && 
                profundidad->obtenerCursor()->obtenerValorDeCelda() != ' ') {
                celdaTope = profundidad->obtenerCursor();
            }

            if (celdaTope != NULL) {
                char* letra = NULL;
                letra = new char;
                letra[0] = celdaTope->obtenerValorDeCelda();
                PrintString(imagen,
                letra,
                (profundidad->obtenerCursor()->obtenerCoordenadas()->obtenerY()-1) * (this->alturaFicha + this->paddingY) + this->margenY + 15, 
                (profundidad->obtenerCursor()->obtenerCoordenadas()->obtenerX()-1) * (this->anchoFicha + this->paddingX) + this->margenX + 15,
                this->alturaFicha,
                color );
            }
            

            
        };
        
        imagen.WriteToFile(nombreArchivo);
        
    };

}
