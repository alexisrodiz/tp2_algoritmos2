#include <iostream>
#include "Coordenadas.h"

Coordenadas::Coordenadas(int x, int y){
    this->x = x;
    this->y = y;
}

Coordenadas::Coordenadas(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

int Coordenadas::obtenerX(){
    return this->x;
}

int Coordenadas::obtenerY(){
    return this->y;
}

int Coordenadas::obtenerZ(){
    return this->z;
}