#include "Tablero.h"
#include "Ficha.h"
#include <iostream>
#include "Plano.h"

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
    
    /************Esta porcion agrega el cubo de celdas vecinas a cada celda*/
    /*1.- No se puede hacer esta accion al crear celdas, ya que no todas estan definidas
     *en el tablero en el momento en que se agrega cada una y se necesitan de todas sus vecinas
     *
     *2.- Las celdas que no estan en la frontera poseen sus 26 vecinas completas y que apuntan a otras
     *celdas existentes, las celdas que estan en la frontera tienen algunas vecinas que no apuntan a nada
     *(celdas en el exterior del tablero) dichas vecinas en el exterior del tablero apuntan a NULL.
     *
     *3.- La estructura de celdas vecinas en para cada celda queda fija a lo largo del juego.
     */
    this->obtenerFila()->iniciarCursor();
    while(this->obtenerFila()->avanzarCursor()){
    	Lista<Lista<Celda*>*>* columnaAuxiliar = this->obtenerFila()->obtenerCursor();
    	columnaAuxiliar->iniciarCursor();

    	while(columnaAuxiliar->avanzarCursor()){
    		Lista<Celda*>* profundidadAuxiliar = columnaAuxiliar->obtenerCursor();
    		profundidadAuxiliar->iniciarCursor();

    			while(profundidadAuxiliar->avanzarCursor()){
    				Celda* celdaAuxiliar = profundidadAuxiliar->obtenerCursor();
    				Coordenadas* coordenadasCelda = celdaAuxiliar->obtenerCoordenadas();
    				for (int i = -1; i <= 1; ++i) {
						for (int j = -1; j <= 1; ++j) {
							for (int k = -1; k <= 1; ++k) {
								Celda* celdaVecina = this->buscarCelda(coordenadasCelda->obtenerX()+i,
										coordenadasCelda->obtenerY()+j,coordenadasCelda->obtenerZ()+k);

								celdaAuxiliar->guardarVecina(celdaVecina,i,j,k);
							}
						}
					}
    			}
    	}
    }


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
            while (profundidad->avanzarCursor() || profundidad->obtenerCursor()->obtenerValorDeCelda()!= ' '){

            	std::cout << " | ";
            	std::cout << profundidad->obtenerCursor()->obtenerValorDeCelda() << " | ";
            };
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

unsigned int Tablero::obtenerLongitudLineaGanadora(){

	return this->longitudDeLineaGanadora;
}


bool Tablero::marcarJugada(Coordenadas* coordenadaJugada, Jugador* jugadorEnTurno){

	Colores* color = new Colores(50,50,50); //solo para probar, borrar despues
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
			//Ficha* ficha = new Ficha(color,jugadorEnTurno->obtenerFicha());//solo es de prueba,
            //Ficha* ficha = new Ficha(jugadorEnTurno.obtenerColor()); //comentado para que compile

            //Nuevo metodo para colocar una Ficha
			//listaProfundidad->obtener(posicionCelda)->cambiarValorDeCelda(jugadorEnTurno->obtenerFicha());
            listaProfundidad->obtener(posicionCelda)->colocarFicha(jugadorEnTurno->obtenerFicha());
			listaProfundidad->obtener(posicionCelda)->cambiarEstadoDeCelda();

			huboEspacioParaAgregarFicha = true;
			this->coordenadasDeUltimaCelda->guardarX(coordenadaJugada->obtenerX());
			this->coordenadasDeUltimaCelda->guardarY(coordenadaJugada->obtenerY());
			this->coordenadasDeUltimaCelda->guardarZ(posicionCelda);

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

	int x = this->coordenadasDeUltimaCelda->obtenerX();
	int y = this->coordenadasDeUltimaCelda->obtenerY();
	int z = this->coordenadasDeUltimaCelda->obtenerZ();
	Celda* celdaUltima = buscarCelda(x,y,z);

	unsigned int contadorDeLineaGanadora[3][3][3];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				contadorDeLineaGanadora[i][j][k] = 1;
			}
		}
	}

	for (int i = -1; i <=1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			for (int k = -1; k <= 1; ++k) {
				Celda* celdaVecina = celdaUltima->obtenerVecina(i,j,k);

				/*Recordar que las celdas* celdas vecinas que esta fuera del tablero estan seteadas con NULL
				 *desde el constructor.
				 *Ademas aquellas celdas dentro del tablero que aun no fueron marcadas con una ficha
				 *contienen un Ficha* seteado en NULL.
				 */
				while (celdaVecina!= NULL && celdaVecina->obtenerFicha()!= NULL && celdaUltima->obtenerFicha()->
						valoresFichaIguales(celdaVecina->obtenerFicha()->obtenerValorDeLaFicha())){

					contadorDeLineaGanadora[i+1][j+1][k+1]++;
					celdaVecina = celdaVecina->obtenerVecina(i,j,k);
				}
			}
		}
	}

	for (int i = 0; i <= 2; ++i) {
		for (int j = 0; j <=2; ++j) {
			for (int k = 0; k <=2; ++k) {

				if ((contadorDeLineaGanadora[i][j][k] + contadorDeLineaGanadora[2-i][2-j][2-k] - 1)
						>= this->obtenerLongitudLineaGanadora()) {
					std::cout << "longitud linea ganadora: "
							<<contadorDeLineaGanadora[i][j][k] + contadorDeLineaGanadora[2-i][2-j][2-k] - 1<<std::endl;
					std::cout <<contadorDeLineaGanadora[i][j][k] <<std::endl;
					std::cout <<contadorDeLineaGanadora[2-i][2-j][2-k] <<std::endl;

					std::cout <<std::endl;
						std::cout <<std::endl;

						std::cout <<"cara x = 0"<< std::endl;
						for (int j = 0; j < 3; ++j) {
							for (int k = 0; k < 3; ++k) {
								std::cout <<contadorDeLineaGanadora[0][j][k] <<" ";
							}
							std::cout << std::endl;
						}

						std::cout <<"cara x = 1"<< std::endl;
						for (int j = 0; j < 3; ++j) {
							for (int k = 0; k < 3; ++k) {
								std::cout <<contadorDeLineaGanadora[1][j][k] <<" ";
							}
							std::cout << std::endl;
						}

						std::cout <<"cara x = 0"<< std::endl;
						for (int j = 0; j < 3; ++j) {
							for (int k = 0; k < 3; ++k) {
								std::cout <<contadorDeLineaGanadora[2][j][k] <<" ";
							}
							std::cout << std::endl;
						}


					return true;
				}
			}
		}
	}


	return false;
}

bool Tablero:: agregarFicha(unsigned int fila, unsigned int columna, char ficha){

	//Jugador jugadorEnTurno(2);
	unsigned int cantidadElementosEnUso =this->obtenerFila()->obtener(fila)->obtener(columna)->contarElementos();

	if (cantidadElementosEnUso < this->obtenerNumeroDeProfundidad()) {
		//this->marcarTablero(fila, columna, cantidadElementosEnUso + 1 , jugadorEnTurno);
	}

	return false;
}

Celda* Tablero::buscarCelda(unsigned int x, unsigned int y, unsigned int z){
	Celda* celda = NULL;
	if (( 1 <= x && x <= this->obtenerNumeroDeFila() ) &&
			(1 <= y && y <= this->obtenerNumeroDeColumna()) && 1 <= z &&
							z <= this->obtenerNumeroDeProfundidad()) {//muy largo, despues arreglar

		celda = this->obtenerFila()->obtener(x)->obtener(y)->obtener(z);
	}
	return celda;
}

Plano* Tablero::generarPlanoXY(int z){

	Plano* plano = new Plano(this->obtenerNumeroDeFila(), this->obtenerNumeroDeColumna());

	for (unsigned int i = this->obtenerNumeroDeFila(); i >=1 ; --i) {
		for (unsigned int j = 1; j <= this->obtenerNumeroDeColumna(); ++j) {

			Celda* celda = this->buscarCelda(i,j,z);
			if(celda->obtenerFicha() != NULL){
				plano->guardarValor(i,j,celda->obtenerFicha()->obtenerValorDeLaFicha());
			}
				else{
					plano->guardarValor(i,j,' ');
				}
		}
	}
	return plano;
}

Plano* Tablero::generarPlanoYZ(int x){

	Plano* plano = new Plano(this->obtenerNumeroDeColumna(), this->obtenerNumeroDeProfundidad());

	for (unsigned int j = this->obtenerNumeroDeColumna(); j >=1 ; --j) {
		for (unsigned int k = 1; k <= this->obtenerNumeroDeProfundidad(); ++k) {

			Celda* celda = this->buscarCelda(x,j,k);
			if(celda->obtenerFicha() != NULL){
				plano->guardarValor(x,j,celda->obtenerFicha()->obtenerValorDeLaFicha());
			}
				else{
					plano->guardarValor(x,j,' ');
				}
		}
	}
	return plano;
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











