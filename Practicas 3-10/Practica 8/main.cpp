// Muy bien la práctica. Nada que añadir.
// ALVARO: arreglado el memory leak que arrastraba de las anteriores practicas.
#pragma warning(disable: 4710)// print f not inline
#include "FileFunctions.h"
#include "FileUtilities.h"

int main(int, char *) {
	fileOperators::Archivo * file;
	file= fileOperators::openFile("Prueba.txt","r");
	printf("%u\n", fileOperators::fileUtilities::countCoincidence(file, ","));
	printf("%u\n", fileOperators::fileUtilities::addNumbers(file));
	fileOperators::closeFile(file);
	getchar();
}

