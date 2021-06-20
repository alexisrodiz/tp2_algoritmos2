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
        * pre: Tener coordenada en Z
        * post: Devuelve la Coordenada en Z
        */
        int obtenerZ();

        /*
        * post: Actualiza el valor de la coordenada X
        */
        void guardarX(int x);

        /*
        * post: Actualiza el valor de la coordenada Y
        */
        void guardarY(int y);

        /*
        * post: Actualiza el valor de la coordenada Z
        */
        void guardarZ(int z);


        /*
        * post: Destructor de la clase
        */
        ~Coordenadas();
};

#endif /* COORDENADAS_H_ */