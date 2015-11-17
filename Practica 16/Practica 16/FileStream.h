#pragma once
#include "Stream.h"

class CFileStream :
	public CStream
{
public:
	CFileStream(const char * fileName);
	virtual ~CFileStream();
	virtual int open();
	virtual int close();
	virtual int read(void *, unsigned int);
	virtual int write(void *, unsigned int);
private: 
	const char * filename;
	FILE * file;
};

