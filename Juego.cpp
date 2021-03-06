#include <iostream>
#include <algorithm>    // std::find
#include <iomanip>      // std::setw
#include <cmath>
#include <string>
#include "Juego.h"

using namespace std;

Juego::Juego(){

    this->jugadores = new Lista<Jugador*>;

    this->mazo = new Mazo;

    this->tablero = NULL;

    this->exportarTablero = NULL;

    this->porcentajeQuitarFichas = 5;

    this->cantidadFichasADevolverJugador = this->calcularCantidadFichasADevolverJugador();

    this->fichasUtilizadas = new Lista<Ficha*>;
}

bool Juego::verificarFichaValorFueUtilizada(char fichaValor){
    this->fichasUtilizadas->iniciarCursor();
    while(this->fichasUtilizadas->avanzarCursor()){
        if(this->fichasUtilizadas->obtenerCursor()->obtenerValorDeLaFicha() == fichaValor){
            return true;
        }
    }
    return false;
}

void Juego::agregarJugadores(){
    int i = 1;
    char agregarOtroJugador;
    string nombre;
    char cinFicha;
    bool fichaFueUtilizada;
    do {
        cout << "Por favor ingrese el nombre del jugador " << i <<  endl;

        cin >> nombre;
        
        do { // Pide una ficha mientras exista en la lista de ficha ya utilizadas
            cout << "Por favor, elija una ficha (letra)" << endl;
            
            cin >>  cinFicha;

            fichaFueUtilizada = this->verificarFichaValorFueUtilizada(cinFicha);
            if (fichaFueUtilizada){
                cout << "La ficha elegida ya fue utilizada, por favor elija otra" << endl;
            }
            

        } while ( fichaFueUtilizada );

       // ver de generar colores aleatorios para cada jugador
        Colores* color = new Colores(50,50,50);

        Ficha* ficha = new Ficha(color, cinFicha); 

        this->fichasUtilizadas->agregar(ficha);
        
        Jugador * jugador = new Jugador(nombre, ficha, i);
            
        jugadores->agregar(jugador);

        // Si ya se agregaron 2 jugadores, pregunto si se quieren agregar mas
        if (i >= 2) {
            cout << "Desea agregar otro jugador? S: SI, N: NO" << endl;
            cin >> agregarOtroJugador;
        }
        
        ++i;
    }
    while(i <= 2 || tolower(agregarOtroJugador) == 's');

    this->calcularCantidadFichasPorJugador();
    
}

int Juego::calcularCantidadFichasADevolverJugador(){
    return this->cantidadFichasPorJugador * (this->porcentajeQuitarFichas / 100);
}

void Juego::calcularCantidadFichasPorJugador(){
    float total;
    unsigned int x, y, z;
    x = this->tablero->obtenerNumeroDeFila();
    y = this->tablero->obtenerNumeroDeColumna();
    z = this->tablero->obtenerNumeroDeProfundidad();
    int cantidadJugadores = this->jugadores->contarElementos();
    total = (x * y * z) / cantidadJugadores;
    this->cantidadFichasPorJugador = floor(total);
}


void Juego::imprimirJugadores(){
    jugadores->iniciarCursor();
    while (jugadores->avanzarCursor())
    {
        Jugador* jugador = jugadores->obtenerCursor();
        cout << "ID: " << jugador->obtenerId() << endl;
        cout << "Nombre: " << jugador->obtenerNombre() << endl;
        cout << "Ficha elegida: " << jugador->obtenerFicha() << "\n" << endl;
    }
}

Jugador* Juego::obtenerJugadorPorId(int id){
    Jugador* jugador = NULL;
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		if (this->jugadores->obtenerCursor()->obtenerId() == id){
			jugador = this->jugadores->obtenerCursor();
		}
	}
	return jugador;
};

void Juego::agregarTablero(){
    int x, y, z, minimo;
    vector<int> dimensionesTablero;

    do {
        cout << "Por favor indique las dimensiones del tablero" << endl;
        cout << "\nLargo (Minimo: 3, Maximo: 100): ";
        cin >> x;
    }
    while (x < 3 || x > 100);

    do {
        cout << "\nAncho (Minimo: 3, Maximo: 100): ";
        cin >> y;
    }
    while( y < 3 || y > 100);

    do {
        cout << "\nProfundidad (Minimo: 3, Maximo: 100): ";
        cin >> z;
    }
    while(z < 3 || z > 100);

    dimensionesTablero.push_back(x);
    dimensionesTablero.push_back(y);
    dimensionesTablero.push_back(z);
    
    // Obtengo el minimo de las 3 dimensiones del tablero para asignarlo como
    // el nEnLinea para ganar el juego
    minimo = *min_element(dimensionesTablero.begin(), dimensionesTablero.end());

    Tablero* tablero = new Tablero(x, y, z, minimo);

    this->tablero = tablero;

    this->exportarTablero = new ExportarTableroBMP(640, 480, 8, 5, 5, this->tablero);
    
};

void Juego::recorrerListaDeJugadores(){
    if(this->jugadores->avanzarCursor() == false){
        this->jugadores->iniciarCursor();
        this->jugadores->avanzarCursor();
    }
}

void Juego::iniciar(){
    int i = 0;
    cout << "Iniciando juego..." << endl;

    this->agregarTablero();

    bool jugadorGano = false;

    this->agregarJugadores();

    this->jugadores->iniciarCursor();

    Jugador* jugadorActual = NULL;

    while(jugadorGano == false){
        int valorCartaJugada;
        char usarCartas;
        bool tieneCartaSeleccionada;

        this->recorrerListaDeJugadores();

        Carta* cartaJugada = NULL;

        jugadorActual = this->jugadores->obtenerCursor();

        cout << "TURNO: " << jugadorActual->obtenerNombre() << "(" << jugadorActual->obtenerId() << ")" << endl;
        
        cout << "\nRetirando una carta del mazo..." << endl;
        jugadorActual->sacarCartaMazo(this->mazo);

        cout << "\nTus cartas en mano son: " << endl;
	    jugadorActual->imprimirCartasEnMano();

        cout << "\nUsar alguna carta? S: SI - N: NO" << endl;
        cin >> usarCartas;

        if (tolower(usarCartas) == 's'){

            do {
                cout << "Indique el valor de la carta a utilizar: " << endl;
                cin >> setw(1) >> valorCartaJugada;

                tieneCartaSeleccionada = jugadorActual->verificarSiTieneCartaPorId(valorCartaJugada);
                if (tieneCartaSeleccionada == false){
                    cout << "No tiene esa carta en mano, elija otra por favor" << endl;
                }

            } while (tieneCartaSeleccionada == false);
            
             

            cartaJugada = jugadorActual->obtenerCartaPorValor(valorCartaJugada);

            this->procesarCarta(cartaJugada, jugadorActual);

        }

        this->inicarJugada(jugadorActual);

        this->exportarTablero->exportarTableroXY(i);
        
        jugadorGano = this->tablero->jugadorGano(jugadorActual);
        ++i;
    }

    if (jugadorGano){
        cout << "Ha ganado el jugador: " << jugadorActual->obtenerNombre() << endl;
    }
    
}

void Juego::inicarJugada(Jugador* jugadorActual){
    int x, y;
    bool jugadaMarcada;
    Coordenadas* coordenadaJugada = NULL;
    do {

        cout << "Indique una ubicacion para colocar la ficha: " << endl;
            
        cout << "Coordenada x : " << endl;
        cin >> x;

        if(x <= this->tablero->obtenerNumeroDeFila() && x > 0){
            cout << "Coordenada y : " << endl;
            cin >> y;
            if(y <= this->tablero->obtenerNumeroDeColumna() && y > 0){
                coordenadaJugada = jugadorActual->realizarJugada(x,y);

                jugadaMarcada = tablero->marcarJugada(coordenadaJugada, jugadorActual);
                if (jugadaMarcada == false){
                    cout << "No hay espacio en las coordenadas seleccionadas, elija otras" << endl;
                }

            } else {
                cout << "Por favor, elija una coordenada en 'y' v??lida" << endl;
            }

        } else {
            cout << "Por favor, elija una coordenada en 'x' v??lida" << endl;
        }
            
    }
    while(jugadaMarcada == false);

}

void Juego::procesarCarta(Carta* cartaJugada, Jugador* jugadorActual){
    int idJugador;
    switch (cartaJugada->obtenerValor()){
        case 1:
            // Bloquear turno del siguiente jugador (saltea el siguiente) 
            cout << "Bloqueando turno del siguiente jugador!" << endl;
            this->jugadores->avanzarCursor();
            break;
        case 2:
            // Jugar doble 
            cout << "Jugando Doble!" << endl;
            for (int i = 2; i > 0; i--){
                this->inicarJugada(jugadorActual);
                if(i > 1){
                    cout << "Otra vez!" << endl;
                }
            }
            break;
        case 3:
            // Deshacer ultima jugada 
            cout << "Deshaciendo ultima jugada!" << endl;
            this->tablero->borrarUltimaJugada();
            break;
        case 4:
            // Restar n cantidad de fichas a un jugador 
            cout << "Seleccione el ID del jugador al que desea quitarle fichas: " << endl;
            this->imprimirJugadores();
            cin >> idJugador;
            Jugador* jugadorSeleccionado = this->obtenerJugadorPorId(idJugador);

            jugadorSeleccionado->devolverFichas(this->cantidadFichasADevolverJugador);

            break;
    }
}
