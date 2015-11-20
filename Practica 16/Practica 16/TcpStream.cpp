#pragma warning(disable:4514)
#pragma warning(disable:4710)
#include "TcpStream.h"

CTcpStream::CTcpStream(char* ip,unsigned int port)
{
	this->ip = ip;
	this->port = port;
}

CTcpStream::~CTcpStream()
{
}

int CTcpStream::open()
{
	printf("opening conection to: %s:%u", this->ip,this->port);
	return 0;
}

int CTcpStream::close()
{
	printf("closing connection to: %s:%u", this->ip, this->port);
	return 0;
}

int CTcpStream::read(void * buffer, unsigned int size)
{
	printf("reading %u chars from %s:%u and saiving them to %p", size, this->ip, this->port, buffer);
	return 0;
}

int CTcpStream::write(void * buffer, unsigned int size)
{
	printf("writing first %u chars from '%s' into %s:%u", size, static_cast<char *>(buffer), this->ip,this->port);
	return 0;
}
