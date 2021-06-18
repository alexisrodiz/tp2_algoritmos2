#ifndef COORDENADAS_H_
#define COORDENADAS_H_


class Coordenadas {

    private:

        int x;

        int y;

        int z;

    public:

        /*
        * Constructor de la clase
        * pre: Recibe las Coordenadas x e y por parametro
        * post: Instancia un objeto con las Coordenadas indicadas
        */
        Coordenadas(int x, int y);

         /*
        * Constructor de la clase
        * pre: Recibe las Coordenadas x, y, z por parametro
        * post: Instancia un objeto con las Coordenadas indicadas
        */
        Coordenadas(int x, int y, int z);


        /*
        * post: Devuelve la Coordenada en X
        */
        int obtenerX();

        /*
        * post: Devuelve la Coordenada en Y
        */
        int obtenerY();

        /*
        * post: Devuelve la Coordenada en Y
        */
        int obtenerZ();

        /*
        * post: Destructor de la clase
        */
        ~Coordenadas();
};


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


#endif /* COORDENADAS_H_ */