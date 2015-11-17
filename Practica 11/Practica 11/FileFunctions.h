#pragma once
#pragma warning(disable: 4514)
#pragma warning(disable: 4996)
#pragma warning(disable: 4710)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
namespace fileOperators{
	struct Archivo {
		FILE * file;
	};
	Archivo * openFile(const char *,const char *);
int closeFile(Archivo *);
size_t readFile(void *, unsigned int, Archivo *);
size_t writeFile(void *, unsigned int, Archivo *);
}