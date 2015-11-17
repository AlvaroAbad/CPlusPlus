#pragma warning(disable: 4514)
#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileFunctions.h"

void TFile::openFile(const char * fileName, const char * mode) {
	if(fileName && mode){
	this->file=fopen(fileName, mode);
	}
}

int TFile::closeFile() {
	if (this->file) {
		return fclose(this->file);
	}
	return 0;
}

size_t TFile::readFile(void * buffer,unsigned int length) {
	if (this->file){
		size_t readChars;
	readChars = fread(buffer, static_cast<size_t>(sizeof(char)), static_cast<size_t>(length), this->file);
	static_cast<char *>(buffer)[readChars] = '\0';
	return (readChars);
	}
	return 0;
}

size_t TFile::writeFile(void *buffer, unsigned int length) {
	if (this->file) {
		return fwrite(buffer, static_cast<size_t>(sizeof(char)), static_cast<size_t>(length), this->file);
	}
	return 0;
}

