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

