#pragma once
#include "Stream.h"
class CComStream :
	public CStream
{
public:
	CComStream(const char *);
	virtual ~CComStream();
	virtual int open();
	virtual int close();
	virtual int read(void *, unsigned int);
	virtual int write(void *, unsigned int);

private:
	const char * COMPort;
};

