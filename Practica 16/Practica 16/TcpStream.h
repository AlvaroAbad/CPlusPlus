#pragma once
#include "Stream.h"
class CTcpStream :
	public CStream
{
public:
	CTcpStream(char *,unsigned int);
	virtual ~CTcpStream();
	virtual int open();
	virtual int close();
	virtual int read(void * buffer, unsigned int size);
	virtual int write(void * buffer, unsigned int size);
private:
	char * ip;
	unsigned int port;
};

