#pragma once
#pragma warning(disable: 4514)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class TFile {
private:
	FILE * file;
public:
	TFile() {
		this->file = NULL;
	}
	void openFile(const char *,const char *);
	int closeFile();
	size_t readFile(void *, unsigned int);
	size_t writeFile(void *, unsigned int);
	FILE * getFile() { return this->file; }
};

