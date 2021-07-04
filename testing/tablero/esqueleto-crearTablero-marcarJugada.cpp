#include <iostream>
#include "Lista.h"

Lista< Lista< Lista<char*>* >* >* crearTablero(unsigned int filaNew, unsigned int columnaNew, unsigned int alturaNew){
	unsigned int numeroDeFila = filaNew;
	unsigned int numeroDeColumna = columnaNew;
	unsigned int numeroDeProfundidad = alturaNew;

	Lista< Lista< Lista<char*>* >* >* fila;
	fila = new Lista< Lista< Lista<char*>* >* >();

	    for (unsigned int x = 1; x <= numeroDeFila; x++) {

	        Lista< Lista<char*>* >* columna = new Lista< Lista<char*>* >();


	        for (unsigned int y = 1; y <= numeroDeColumna; y++) {

	            Lista<char*>* profundidad = new Lista<char*>();

	            for (unsigned int z = 1; z <= numeroDeProfundidad; z++) {

	                char* celda = new char;
	                *celda = '0'; //caracter espacio vacio

	                profundidad->agregar(celda);

	            };

	            columna->agregar(profundidad);

	        };

	        fila->agregar(columna);
	    };
	    return fila;
}

bool marcarJugada(Lista< Lista< Lista<char*>* >* >* fila,int x, int y, char ficha){

    Lista<char*>* listaProfundidad =  fila->obtener(x)
    			->obtener(y);

    	bool posicionVaciaNoEncontrada = true;

    	bool huboEspacioParaAgregarFicha = false;

    	unsigned int posicionCelda = 1;

    	listaProfundidad->iniciarCursor();

    	while (listaProfundidad->avanzarCursor() && posicionVaciaNoEncontrada){


    		if (*(listaProfundidad->obtenerCursor() ) == '0'){
    			posicionVaciaNoEncontrada = false;

                * (listaProfundidad->obtener(posicionCelda) ) = ficha;

    			huboEspacioParaAgregarFicha = true;

    		}
    		posicionCelda++;

    	}
    	return huboEspacioParaAgregarFicha;
}


int main() {

	unsigned int numeroDeFila = 8;
	unsigned int numeroDeColumna = 8;
	unsigned int numeroDeProfundidad = 8;

	Lista< Lista< Lista<char*>* >* >* fila;
	fila = crearTablero(numeroDeFila, numeroDeColumna, numeroDeProfundidad);

	//Muestra contenido de (3,3,1) que es '0' es decir vacio.
    std::cout << "Posicion (3,3,1) contenido: "<<*(fila->obtener(3)->obtener(3)->obtener(1)) << std::endl;

    //Coloca primera Ficha 'X' en (3,3,1)
	if (marcarJugada(fila,3,3,'X')){
		std::cout <<"agregada Ficha 'X' en (3,3,1) " << std::endl;
	}
	else{
		std::cout <<"columna llena" << std::endl;
	}
	/**************************************************/
	//muestra contenido Posicion (3,3,1)
    std::cout << "Posicion (3,3,1) contenido: "<<*(fila->obtener(3)->obtener(3)->obtener(1)) << std::endl;
    /**************************************************/
    //llena la profundidad
    for(int i = 0; i < 7; ++i){
    	bool sePudoAgregarFicha = marcarJugada(fila,3,3,'X');
    	if (sePudoAgregarFicha){
    		std::cout <<"agregada Ficha 'X' en (3,3) " << std::endl;
    	}
    	else{
    		std::cout <<"Error: columna llena, no se pudo agregar" << std::endl;
    	}
    }
    /********************************************************/
    //intenta agregar una ficha a columna llena
    if (marcarJugada(fila,3,3,'X')){
        		std::cout <<"agregada Ficha 'X' en (3,3,1) " << std::endl;
        	}
        	else{
        		std::cout <<"Error: columna llena, no se pudo agregar" << std::endl;
        	}
    /********************************************************/
    //imprime la profundidad en su totalidad
    std::cout << "Impresion Profundidad :" << std::endl;
    std::cout << std::endl;
    for (int i = 8; i >= 1; --i) {
    	std::cout << *(fila->obtener(3)->obtener(3)->obtener(i)) << std::endl;
	}
    /*****************************************/












    /*Juego* juego = new Juego;

    juego->iniciar();

    
    
    std::cout << "Fin" << std::endl;

	Tablero* tablero = new Tablero(8,8,8,3);

	tablero->agregarFicha(1,5,'x');

	std::cout << tablero->buscarCelda(1,5,1)->obtenerValorDeCelda() << std::endl;
	std::cout <<"hola"<<std::endl;
	//tablero->mostrarTableroXY();
    
    */
    return 0;
}
