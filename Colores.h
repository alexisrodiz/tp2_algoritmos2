
#ifndef SRC_COLORES_H_
#define SRC_COLORES_H_

#include "EasyBMP.h"

/*Colores es un TDA que permite crear y representar un color del tipo RGB, cada color se crea con
 *valores de rojo, verde y azul, cada uno de estos posee valores enteros entre 0 y 255 los cuales
 *representan la intensidad de cada uno*/


class Colores{

private:

	RGBApixel* estructuraDeColor;

public:

	/*pre: "rojo", "verde", "azul" es un entero en el rango [0..255]
	 *post: crea un color del tipo rgb
	 */
	Colores(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul);

	/*pre:
	 *post: libera los recursos del sistema..
	 */
	~Colores();

	/*pre: "nuevaTonalidadDeRojo" es un entero en el rango [0..255]
	 *post: guarda la nueva tonalidad de Rojo en el color
	 */
	void guardarTonalidadRojo(ebmpBYTE nuevaTonalidadDeRojo);

	/*pre: "nuevaTonalidadDeVerde" es un entero en el rango [0..255]
	 *post: guarda la nueva tonalidad de Verde en el color
	 */
	void guardarTonalidadVerde(ebmpBYTE nuevaTonalidadDeVerde);
	/*pre: "nuevaTonalidadDeAzul" es un entero en el rango [0..255]
	 *post: guarda la nueva tonalidad de Azul en el color
	 */
	void guardarTonalidadAzul(ebmpBYTE nuevaTonalidadDeAzul);

	/*pre:
	 *post: devuelve la tonalidad de rojo almacenada en la estructura
	 */
	ebmpBYTE devolverTonalidadRojo();
	/*pre:
	 *post: devuelve la tonalidad de verde almacenada en la estructura
	 */
	ebmpBYTE devolverTonalidadVerde();
	/*pre:
	 *post: devuelve la tonalidad de azul almacenada en la estructura
	 */
	ebmpBYTE devolverTonalidadAzul();

};


#endif
