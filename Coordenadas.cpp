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

void Coordenadas::guardarX(int x){
    this->x = x;
};

void Coordenadas::guardarY(int y){
    this->y = y;
};

void Coordenadas::guardarZ(int z){
    this->z = z;
};