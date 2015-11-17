#include "ComStream.h"

CComStream::CComStream(const char * COMPort)
{
	this->COMPort = COMPort;
}

CComStream::~CComStream()
{
}

int CComStream::open()
{
	printf("abriendo puerto serie COM %s", this->COMPort);
	return 0;
}

int CComStream::close()
{
	printf("Closing serial COM port: %s", this->COMPort);
	return 0;
}

int CComStream::read(void * buffer, unsigned int size)
{
	printf("reading %u chars from serial COM port %s amd saiving them to %p", size, this->COMPort, buffer);
	return 0;
}

int CComStream::write(void * buffer, unsigned int size)
{
	printf("writing first %u chars from '%s' into serial COM port %s", size, buffer, this->COMPort);
	return 0;
}
