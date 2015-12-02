// TOMAS: Muy bien la pr�ctica.
// TOMAS: los "static_cast<void*>" en los "write" no son necesarios ya que cuando un par�metro se 
//        declra de tipo "void *" se est� indicando que se le puede pasar cualquier puntero.
// ALVARO: eliminados los "static_cast<void*>".

#pragma warning(disable:4514)
#pragma warning(disable:4710)
#include "FileStream.h"
#include "TcpStream.h"
#include "ComStream.h"
#include <stdlib.h>
int main(int, char*) {

	CStream *fileStream = new CFileStream("Prueba.txt");
	CStream *comStream = new CComStream("COM2");
	CStream *TCPStream = new CTcpStream("195.25.211.25",1234);
	void * readBuffer = malloc(20);
	char writeBuffer[] = "String for writing";

	fileStream->open();
	printf("\n");
	fileStream->read(readBuffer, 20);
	printf("\n");
	fileStream->write(writeBuffer, 18);
	printf("\n");
	fileStream->close();
	printf("\n");

	comStream->open();
	printf("\n");
	comStream->read(readBuffer, 20);
	printf("\n");
	comStream->write(writeBuffer, 18);
	printf("\n");
	comStream->close();
	printf("\n");

	TCPStream->open();
	printf("\n");
	TCPStream->read(readBuffer, 20);
	printf("\n");
	TCPStream->write(writeBuffer, 18);
	printf("\n");
	TCPStream->close();
	printf("\n");

	getchar();

}