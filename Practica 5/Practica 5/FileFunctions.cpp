#pragma warning(disable: 4996)// error forcing to use fopen_s
#pragma warning(disable: 4514)// stdio.h warnings
#include <stdio.h>
#include "FileFunctions.h"
Archivo * openFile(const char * fileName, const char * mode) {
	if (fileName && mode) {
		FILE * file = fopen(fileName, mode);
		Archivo * archivo = new Archivo;
		archivo->file = file;
		return archivo;
	}
	else {
		return NULL;
	}
}

int closeFile(Archivo * file) {
	if (file) {
		int error= fclose(file->file);
		if (!error) {
			delete (file);
		}
		return error;
	}
	return 0;
}

int readFile(void * buffer,int length, Archivo * file) {
	if (file) {
		size_t readChars;
		readChars = fread(buffer, static_cast<size_t>(sizeof(char)), static_cast<size_t>(length), file->file);
		static_cast<char *>(buffer)[readChars] = '\0';
		return (readChars);
	}
	return 0;
}

int writeFile(void *buffer, unsigned int length, Archivo * file) {
	if (file) {
		return fwrite(buffer, static_cast<size_t>(sizeof(char)), static_cast<size_t>(length), file->file);
	}
	return 0;
	
}
