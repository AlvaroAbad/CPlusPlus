#pragma once
#pragma warning(disable: 4514)// stdio warnings
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Archivo {
	FILE * file;
};
Archivo * openFile(const char *,const char *);
int closeFile(Archivo * const);
size_t readFile(void *, unsigned int, Archivo * const);
size_t writeFile(void *, unsigned int, Archivo * const);