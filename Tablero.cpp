#include "Tablero.h"
#include "Ficha.h"
#include <iostream>

Tablero::Tablero(unsigned int fila, unsigned int columna, unsigned int profundidad,
		unsigned int longitudLineaGanadora) {

    this->numeroDeFila = fila;
    this->numeroDeColumna = columna;
    this->numeroDeProfundidad = profundidad;
    this->coordenadasDeUltimaCelda = new Coordenadas(0,0,0);
    this->longitudDeLineaGanadora = longitudLineaGanadora;

    this->cantidadDeCeldasVacias = (this->numeroDeFila)*(this->numeroDeColumna)*(this->numeroDeProfundidad);

    this->fila = new Lista< Lista< Lista<Celda*>* >* >();

    for (unsigned int x = 1; x <= this->numeroDeFila; x++) {
        
        Lista< Lista<Celda*>* >* columna = new Lista< Lista<Celda*>* >();
        

        for (unsigned int y = 1; y <= this->numeroDeColumna; y++) {

            Lista<Celda*>* profundidad = new Lista<Celda*>();

            for (unsigned int z = 1; z <= this->numeroDeProfundidad; z++) {
                
                Celda* celda = new Celda();
                celda->obtenerCoordenadas()->guardarX(x);
                celda->obtenerCoordenadas()->guardarY(y);
                celda->obtenerCoordenadas()->guardarZ(z);
                profundidad->agregar(celda);

            };
            
            columna->agregar(profundidad);
                
        };

        this->fila->agregar(columna);
    };
    
};

bool Tablero:: hayCeldasVacias(){
	return this->cantidadDeCeldasVacias > 0;
}


void Tablero::mostrarTablero() {

    mostrarTableroXY();
    mostrarTableroYZ();

};

void Tablero::mostrarTableroXY() {

    std::cout << std::endl;

    Lista< Lista< Lista<Celda*>* >* >* fila = obtenerFila();
    fila->iniciarCursor();
    while (fila->avanzarCursor()) {
        
        Lista< Lista<Celda*>* >* columna = fila->obtenerCursor();
        columna->iniciarCursor();
        while (columna->avanzarCursor()) {
            
            Lista<Celda*>* profundidad = columna->obtenerCursor();
            profundidad->iniciarCursor();
            profundidad->avanzarCursor();

            std::cout << " | ";
            std::cout << profundidad->obtenerCursor()->obtenerValorDeCelda() << " | ";

        };
        
        std::cout << std::endl;

    };
    
    std::cout << std::endl;
    std::cout << "Plano XY del tablero" << std::endl;

};

void Tablero::mostrarTableroYZ() {

    std::cout << std::endl;

    Lista< Lista< Lista<Celda*>* >* >* fila = obtenerFila();
    fila->iniciarCursor();
     while (fila->avanzarCursor()) {
        
        Lista< Lista<Celda*>* >* columna = fila->obtenerCursor();
        columna->iniciarCursor();
        columna->avanzarCursor();
        Lista<Celda*>* profundidad = columna->obtenerCursor();
        profundidad->iniciarCursor();
        while (profundidad->avanzarCursor()) {
            
            std::cout << " | ";
            std::cout << profundidad->obtenerCursor()->obtenerValorDeCelda() << " | ";

        }
        
        std::cout << std::endl;

    };
    
    std::cout << std::endl;
    std::cout << "Plano YZ del tablero" << std::endl;

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


bool Tablero::marcarJugada(Coordenadas* coordenadaJugada, Jugador* jugadorEnTurno){

	Lista<Celda*>* listaProfundidad =  this->obtenerFila()->obtener(coordenadaJugada->obtenerX())
			->obtener(coordenadaJugada->obtenerY());

	bool posicionVaciaNoEncontrada = true;

	bool huboEspacioParaAgregarFicha = false;

	unsigned int posicionCelda = 1;

	listaProfundidad->iniciarCursor();

	while (listaProfundidad->avanzarCursor() && posicionVaciaNoEncontrada){


		if (listaProfundidad->obtenerCursor()->obtenerEstaVacia()){
			posicionVaciaNoEncontrada = false;

            //Ver como obtener Colores
            Ficha* ficha = new Ficha(jugadorEnTurno.obtenerColor());

            //Nuevo metodo para colocar una Ficha
			//listaProfundidad->obtener(posicionCelda)->cambiarValorDeCelda(jugadorEnTurno->obtenerFicha());
            listaProfundidad->obtener(posicionCelda)->colocarFicha(ficha);
			listaProfundidad->obtener(posicionCelda)->cambiarEstadoDeCelda();

			huboEspacioParaAgregarFicha = true;
			this->coordenadasDeUltimaCelda->guardarX(coordenadaJugada->obtenerX());
			this->coordenadasDeUltimaCelda->guardarY(coordenadaJugada->obtenerY());
			this->coordenadasDeUltimaCelda->guardarZ(coordenadaJugada->obtenerZ());

			this->cantidadDeCeldasVacias--;
		}
		posicionCelda++;

	}

    return huboEspacioParaAgregarFicha;
}

Coordenadas* Tablero::obtenerUltimaJugada(){
	Coordenadas* coordenadasUltimaJugada =
			new Coordenadas(this->coordenadasDeUltimaCelda->obtenerX(),
							this->coordenadasDeUltimaCelda->obtenerY(),
							this->coordenadasDeUltimaCelda->obtenerZ());
	return coordenadasUltimaJugada;
}

void Tablero:: borrarUltimaJugada(){
	int posicionX = this->coordenadasDeUltimaCelda->obtenerX();
	int posicionY = this->coordenadasDeUltimaCelda->obtenerY();
	int posicionZ = this->coordenadasDeUltimaCelda->obtenerZ();

    //nuevo metodo para borrar la jugada o vaciar la celda en caso de crear otra carta parecida
	//this->obtenerFila()->obtener(posicionX)->obtener(posicionY)->obtener(posicionZ)->cambiarValorDeCelda(' ');

    this->obtenerFila()->obtener(posicionX)->obtener(posicionY)->obtener(posicionZ)->vaciarCelda();
	this->obtenerFila()->obtener(posicionX)->obtener(posicionY)->obtener(posicionZ)->cambiarEstadoDeCelda();

	this->cantidadDeCeldasVacias++;
}


bool Tablero::jugadorGano(Jugador* jugadorEnTurno){

	return true;
}

bool Tablero:: agregarFicha(unsigned int fila, unsigned int columna, char ficha){

	//Jugador jugadorEnTurno(2).;
	unsigned int cantidadElementosEnUso =this->obtenerFila()->obtener(fila)->obtener(columna)->contarElementos();

	if (cantidadElementosEnUso < this->obtenerNumeroDeProfundidad()) {
		//this->marcarTablero(fila, columna, cantidadElementosEnUso + 1 , jugadorEnTurno);
	}

	return false;
}

Celda* Tablero::buscarCelda(Coordenadas* coordenadas){
	return this->obtenerFila()->obtener(coordenadas->obtenerX())->
			obtener(coordenadas->obtenerY())->obtener(coordenadas->obtenerZ());
}

Tablero::~Tablero() {

    for (unsigned int x = 1; x <= this->numeroDeColumna; x++) {

        for (unsigned int y = 1; y <= this->numeroDeFila; y++) {

            for (unsigned int z = 1; z <= this->numeroDeProfundidad; z++) {
                
                Celda* celda = obtenerFila()->obtener(x)->obtener(y)->obtener(z);
                delete celda;

            };
            
            delete[] obtenerFila()->obtener(x)->obtener(y);
                
        };

        delete[] obtenerFila()->obtener(x);

    };

    delete[] obtenerFila();

};
