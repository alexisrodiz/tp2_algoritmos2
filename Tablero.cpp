#include "Tablero.h"
#include <iostream>

Tablero::Tablero(unsigned int fila, unsigned int columna, unsigned int profundidad) {

    this->numeroDeFila = fila;
    this->numeroDeColumna = columna;
    this->numeroDeProfundidad = profundidad;

    this->cantidadDeCeldasVacias = (this->numeroDeFila)*(this->numeroDeColumna)*(this->numeroDeProfundidad);

    this->fila = new Lista< Lista< Lista<Celda*>* >* >();
1
    for (int x = 1; x <= this->numeroDeColumna; x++) {
        
        Lista< Lista<Celda*>* >* columna = new Lista< Lista<Celda*>* >();
        

        for (int y = 1; y <= this->numeroDeFila; y++) {

            Lista<Celda*>* profundidad = new Lista<Celda*>();

            for (int z = 1; z <= this->numeroDeProfundidad; z++) {
                
                Celda* celda = new Celda();
                profundidad->agregar(celda,z);

            };
            
            columna->agregar(profundidad,y);
                
        };

        this->fila->agregar(columna,x);
    };
    
};

bool Tablero:: hayCeldasVacias(){
	return this->cantidadDeCeldasVacias > 0;
}


void Tablero::mostrarTablero() {

    for (int x = 1; x <= obtenerNumeroDeColumna(); x++) {
        
        for (int y = 1; y <= obtenerNumeroDeFila(); y++) {
            
            for (int z = 1; z <= obtenerNumeroDeProfundidad(); z++) {

                std::cout << this->fila->obtener(x)->obtener(y)->obtener(z)->obtenerValorDeCelda() << std::endl;
            };
            
        };
        
    };

};

void Tablero::mostrarTableroXY() {

    char valorDeLaCelda;

    for (int x = 1; x <= obtenerNumeroDeColumna(); x++) {
        
        for (int y = 1; y <= obtenerNumeroDeFila(); y++) {

            bool filaLlena = false;
            obtenerFila()->obtener(x)->obtener(y)->iniciarCursor();
            
            while (filaLlena == false || obtenerFila()->obtener(x)->obtener(y)->avanzarCursor()) {

                valorDeLaCelda = obtenerFila()->obtener(x)->obtener(y)->obtenerCursor()->obtenerValorDeCelda();
                if(valorDeLaCelda != (char)" ") {

                    filaLlena = true;

                };

            };

            std::cout << valorDeLaCelda << std::endl;
            
        };
        
    };

};

void Tablero::mostrarTableroYZ() {

    char valorDeLaCelda;

    for (int z = 1; z <= obtenerNumeroDeProfundidad(); z++) {

        for (int y = 1; y <= obtenerNumeroDeFila(); y++) {

            bool filaLlena = false;
            obtenerFila()->iniciarCursor();

            while (filaLlena == false || obtenerFila()->avanzarCursor()) {

                valorDeLaCelda = obtenerFila()->obtenerCursor()->obtener(y)->obtener(z)->obtenerValorDeCelda();
                if(valorDeLaCelda != (char)" ") {

                    filaLlena = true;

                };

            };

            std::cout << valorDeLaCelda << std::endl;

        };
        
    };
    
};

Lista< Lista< Lista<Celda*>* >* >* Tablero::obtenerFila() {

    return this->fila;

};

unsigned int Tablero::obtenerNumeroDeFila() {

    return this->numeroDeFila;

};

unsigned int Tablero::obtenerNumeroDeColumna() {

    return this->numeroDeColumna;

};

unsigned int Tablero::obtenerNumeroDeProfundidad() {

    return this->numeroDeProfundidad;

};

void Tablero::marcarTablero(unsigned int fila, unsigned int columna, unsigned int profundidad, Jugador jugadorEnTurno) {

    if(obtenerFila()->obtener(fila)->obtener(columna)->obtener(profundidad)->obtenerEstaVacia()) {

    	//comentado para que compile hasta que se agrege obtenerFicha() a clase Jugador
        //obtenerFila()->obtener(fila)->obtener(columna)->obtener(profundidad)->cambiarValorDeCelda(jugadorEnTurno.obtenerFicha());
    	obtenerFila()->obtener(fila)->obtener(columna)->obtener(profundidad)->cambiarValorDeCelda('X');//solo para probar
    	obtenerFila()->obtener(fila)->obtener(columna)->obtener(profundidad)->cambiarEstadoDeCelda();

    }

};

bool Tablero:: agregarFicha(unsigned int fila, unsigned int columna, char ficha){

	Jugador jugadorEnTurno(2);
	int cantidadElementosEnUso =this->obtenerFila()->obtener(fila)->obtener(columna)->contarElementos();

	if (cantidadElementosEnUso < this->obtenerNumeroDeProfundidad()) {
		this->marcarTablero(fila, columna, cantidadElementosEnUso + 1 , jugadorEnTurno);
	}

	return false;
}

Tablero::~Tablero() {

    for (int x = 1; x <= this->numeroDeColumna; x++) {

        for (int y = 1; y <= this->numeroDeFila; y++) {

            for (int z = 1; z <= this->numeroDeProfundidad; z++) {
                
                Celda* celda = obtenerFila()->obtener(x)->obtener(y)->obtener(z);
                delete celda;

            };
            
            delete[] obtenerFila()->obtener(x)->obtener(y);
                
        };

        delete[] obtenerFila()->obtener(x);

    };

    delete[] obtenerFila();

};
