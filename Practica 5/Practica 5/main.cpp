// TOMAS: Bien la práctica aunque en le mainveo un "malloc" sin su correspondiente "free"
//        y en el "openFile" un new sin su correspondiente close en ningún sitio.
// ALVARO: arreglado el delete haciendolo en el fileClose;
// ALVARO:apartir de ahora hare los delete y los free del main, pero creo que en un main hacer frees y deletes de las cosas que has creado en el propio main y usado alolargo de toda la ejcucion 
//es un poco redundante, ya que se va a liberar si o si cuando acabe la ejecucion del main, si tuviesemos un objeto que su destructor durase 10 minutos tendiramos al usuario 
//esperando a que se cerrase el programa 10 minutos cuando si le dejamos al SO que se ocupe seria instantaneo.

#pragma warning(disable: 4710)
#include <stdlib.h>
#include <string.h>
#include "FileFunctions.h"

int main(int, char *) {
	
	Archivo * file;
	file =openFile("Prueba.txt","r+");
	if (file) {
		void * buffer = malloc(sizeof(char) * 20);
		int readChars = readFile(buffer, 19, file);
		printf("%s\n", static_cast<char *>(buffer));
		readChars = readFile(buffer, 19, file);
		printf("%s\n", static_cast<char *>(buffer));
		fseek(file->file, 0, SEEK_END);
		writeFile(buffer, static_cast<unsigned int>(strlen(static_cast<char *>(buffer))), file);
		if (ferror(file->file)) {
			perror("The following error occurred");
		}
		closeFile(file);
		free(buffer);
	}
	else {
		perror("The following error occurred");
	}
	getchar();
}