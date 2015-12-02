// TOMAS: Bastente bien la práctica. 
// TOMAS: En la línea 63 del fichero "FileUtils.cpp" usas "strncpy(match, "\0", 1);" aparentemente para
//        para "*match='\0'" lo que es más ineficiente.
// ALVARO: no entiendo lo que quieres decirme pero basicamente sustituyo las comas que me encuentro por '\0' 
//		   para aprovechar el mismo buffer ya que mis nodos hacen una copia de todo lo que hay desde el puntero hasta un terminador de cadena.
// TOMAS: El agoritmo que empleas para obtener la cadena del número dendro del buffer busca hacia atrás
//        el final de la cadena anterior esto es menos eficiente que guardar en un puntero la posición
//        inicial de la cadena.
// ALVARO: Ya he cambiado el Algoritmo para guardarme el ultimo punto encontrado y asi no tener que recorrerlo hacia atras.
// TOMAS: Cargas el fichero en memoria entero. Esta solución no es válida en todos los casos.
// ALVARO: he modificado el algoritmo para que lea segmentos de 128Bytes o si el archivo es menor que lea el tamaño del archivo.

#pragma warning(disable: 4710)
#include "FileUtilities.h"

int main(int, char *) {
	fileOperators::Archivo * file;
	TList * list = new TList();;
	file= fileOperators::openFile("Prueba.txt","r");
	fileOperators::fileUtilities::getnumbers(file, list);
	list->toString();
	fileOperators::closeFile(file);
	getchar();
}

