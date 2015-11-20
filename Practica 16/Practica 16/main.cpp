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
	fileStream->write(static_cast<void*>(writeBuffer), 18);
	printf("\n");
	fileStream->close();
	printf("\n");

	comStream->open();
	printf("\n");
	comStream->read(readBuffer, 20);
	printf("\n");
	comStream->write(static_cast<void*>(writeBuffer), 18);
	printf("\n");
	comStream->close();
	printf("\n");

	TCPStream->open();
	printf("\n");
	TCPStream->read(readBuffer, 20);
	printf("\n");
	TCPStream->write(static_cast<void*>(writeBuffer), 18);
	printf("\n");
	TCPStream->close();
	printf("\n");

	getchar();

}