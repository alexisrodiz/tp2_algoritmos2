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

Coordenadas* Jugador::realizarJugada(int x, int y){

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