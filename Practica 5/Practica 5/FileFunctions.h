#pragma once
#pragma warning(disable:4514)
#include <stdio.h>
struct Archivo {
	FILE * file;
};
Archivo * openFile(const char *,const char *);
int closeFile(Archivo *const);
int readFile(void *, int, Archivo *const);
int writeFile(void *, unsigned int, Archivo *const);