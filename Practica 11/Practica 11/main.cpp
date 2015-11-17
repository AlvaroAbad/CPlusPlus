#pragma warning(disable: 4710)
#include "FileUtilities.h"

int main(int, char *) {
	fileOperators::Archivo * file;
	TList * list;
	file= fileOperators::openFile("Prueba.txt","r");
	list=fileOperators::fileUtilities::getnumbers(file);
	list->toString();
	fileOperators::closeFile(file);
	getchar();
}

