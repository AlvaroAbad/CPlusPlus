// TOMAS: Muy bien la práctica auque arrastras el memory leak del "new" del "openFile"
// ALVARO: Arreglado haciendo delete en el closeFile;
#pragma warning(disable: 4710)//printf not inlined
#include "FileUtilities.h"

int main(int, char *) {
	Archivo * file;
	file=openFile("Prueba.txt","r");
	printf("%u\n", countCoincidence(file, ","));
	printf("%u\n", addNumbers(file));
	closeFile(file);
	getchar();
}

