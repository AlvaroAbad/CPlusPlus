#include "FileFunctions.h"
unsigned int countCoincidence(TFile * const file, const char * string) {
	if (string) {
		unsigned int matches = 0;
		FILE * pfile = file->getFile();
		fseek(pfile, 0, SEEK_END);
		long fileSize = ftell(pfile);// get file size to create buffer
		rewind(pfile);
		void * buffer = malloc(sizeof(char) * (fileSize + 1));
		file->readFile(buffer, static_cast<unsigned int>(fileSize));
		char * match = static_cast<char *>(buffer);
		while ((match = strstr(match + 1, string))!=0) {
			matches++;
		}
		free(buffer);
		return matches;
	}
	else {
		return 0;
	}
}

int addNumbers(TFile * const file) {
	int total = 0;
	int i = -1;
	FILE * pfile = file->getFile();
	fseek(pfile, 0, SEEK_END);
	long fileSize = ftell(pfile);
	rewind(pfile);
	void * buffer = malloc(sizeof(char) * (fileSize + 1));
	file->readFile(buffer, static_cast<unsigned int>(fileSize));
	char * match = static_cast<char *>(buffer);
	char * lastmatch = match;
	while ((match = strstr((match + 1), ","))!=0) {
		strncpy_s(match, 1, "\0",1);
		while (match[i] != '\0' && (match + i)>static_cast<char *>(buffer)) {
			i--;
		}
		if ((match + i) == static_cast<char *>(buffer)) {
			total += atoi(match + i);
		}
		else {
			total += atoi(match + (i + 1));
		}
		i = -1;
		lastmatch = match;
	}
	total += atoi(lastmatch + 1);
	free(buffer);
	return total;
}