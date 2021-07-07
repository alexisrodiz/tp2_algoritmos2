#include <iostream>
#include <algorithm>    // std::find
#include <cstring>		// string.empty()
#include "Jugador.h"
using namespace std;



Jugador::Jugador(std::string nombre, Ficha* ficha, int numeroJugador) {
	this->cartas = new Lista<Carta*>;
	this->ficha = ficha;
	this->nombre = nombre;
	this->idJugador = numeroJugador;
	this->cantidadMaximaCartas = 3;
	
}

void Jugador::sacarCartaMazo(Mazo* mazo) {
	if (cartas->contarElementos() < cantidadMaximaCartas) {
		Carta* carta = mazo->sacarCarta();
		cartas->agregar(carta);
	}
}

vector<int> Jugador::obtenerIdsCartas(){
	vector<int> ids;
	this->cartas->iniciarCursor();
	while(this->cartas->avanzarCursor()){
		ids.push_back(this->cartas->obtenerCursor()->obtenerValor());
	}
	return ids;
};

bool Jugador::verificarSiTieneCartaPorId(int idCarta){
	vector<int> idsCartas = this->obtenerIdsCartas();
	if ( std::find(idsCartas.begin(), idsCartas.end(), idCarta) != idsCartas.end() ){
		return true;
	}
	return false;
}


Lista<Carta*>* Jugador::obtenerCartas(){
	return this->cartas;
}

string Jugador::obtenerNombre(){
	return this->nombre;
}

Ficha* Jugador::obtenerFicha(){
	return this->ficha;
}

void Jugador::imprimirCartasEnMano(){
	Lista<Carta*>* cartas = this->obtenerCartas();
	cartas->iniciarCursor();

	while(cartas->avanzarCursor()){
		Carta* carta = cartas->obtenerCursor();
		cout << "\tID " << carta->obtenerValor() << ": " << carta->obtenerTipo()  << endl;
	}
}

int Jugador::obtenerCantidadFichas(){
	return this->obtenerCantidadFichas();
}

Coordenadas* Jugador::realizarJugada(){
	int x, y ;

	cout << "Indique una ubicacion para colocar la ficha: " << endl;
	
	cout << "Coordenada x : " << endl;
	cin >> x;
	cout << "Coordenada y : " << endl;
	cin >> y;

	Coordenadas* coordenadas = new Coordenadas(x, y);

	return coordenadas;
}

Carta* Jugador::obtenerCartaPorValor(int valor){
	Carta* carta = NULL;
	this->cartas->iniciarCursor();
	while(this->cartas->avanzarCursor()){
		if (this->cartas->obtenerCursor()->obtenerValor() == valor){
			carta = this->cartas->obtenerCursor();
		}
	}
	return carta;
}

bool Jugador::usarUnaFicha(){
	if (this->cantidadFichas > 0){
		--this->cantidadFichas;
		return true;
	}
	return false;
}

void Jugador::devolverFichas(int cantidadFichasADevolver){
	// Le resto cantidad de fichas al jugador, mientras la cantidad que
	// tiene sea mayor a cero y hasta que cantidadFichasADevolver tambien sea mayor a cero
	while(this->cantidadFichas > 0 && cantidadFichasADevolver > 0){
		--this->cantidadFichas;
		--cantidadFichasADevolver;
	}
};

void Jugador::establecerFichasIniciales(int cantidadFichasIniciales){
	this->cantidadFichas = cantidadFichasIniciales;
}

int Jugador::obtenerId(){
	return this->idJugador;
};

/*
Jugador::Jugador(){
	nroJugador = 0;
	for(int i = 1; i <= 2;i++){
		fichaAsignada[i] = "";
	}
	carta = "";
	cantidadFichas = 0;
}

void Jugador::establecerJugador(unsigned int jugador){
	nroJugador = jugador;
}



void Jugador::ingresarFicha(){
	std::cout << "Ingrese ficha jugador " << nroJugador << " : ";
	if(nroJugador == 1){
		std::cin >> fichaAsignada[0];
	}else{
		std::cin >> fichaAsignada[1];
		while(controlFicha(fichaAsignada)){
			std::cout << "Debe elegir otra ficha jugador " << nroJugador << " : ";
			std::cin >> fichaAsignada[1];
		}
	}

}

bool Jugador::controlFicha(std::string ficha[2]){
	bool validez = false;
	if(ficha[0] == ficha[1]){
		validez = true;
	}
	return validez;
}

unsigned int Jugador::obtenerJugador(){
	return nroJugador;
}

unsigned int Jugador::obtenerFichasTotal(){
	std::cout << "El jugador " << nroJugador << " tiene " << cantidadFichas << std::endl;
	return cantidadFichas;
}

std::string Jugador::obtenerFicha(){
	std::cout << "El jugador " << nroJugador << " tiene la ficha " << fichaAsignada[nroJugador-1] << std::endl;
	return fichaAsignada[nroJugador-1];
}

void Jugador::imprimirJugador(){
	std::cout << "Jugador " << nroJugador << " tu turno"<< std::endl;
}

void Jugador::ingresarFicha(Jugadores* ficha,unsigned int i){
	std::cout << "Ingrese ficha jugador " << i+1 << ": ";
	std::cin >> fichaAsignada;
	while(!ficha->verificarFicha(fichaAsignada)){
		std::cout << "Ficha ya usada, ingrese otra: ";
		std::cin >> fichaAsignada;
	}
	this->jugadores->agregar(ficha,i);

}
*/
/*
void Jugador::mostrarJugadores(){
	for(unsigned int i=0; i<this->cantidadJugadores;i++){
		std::cout << "Jugador: " << i+1 << this->jugadores->obtener(i) << " Ficha: " << this->jugadores->obtener(i) << std::endl;
	}
}
*/
/*
void Jugador::asignarNumeroDeCartas(){
	int maximo = 3;
	Carta* carta = new Carta(maximo,this->carta);
	std::cout << "Carta: " << carta->obtenerTipo() << std::endl;
	std::cout << " Tipo: " << carta->obtenerValor() << std::endl;
	this->cartas->agregar(carta);
	this->cartas->obtener(maximo);
}
*/

