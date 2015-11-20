#pragma warning(disable:4514)
#pragma warning(disable:4710)
#include "FileStream.h"

CFileStream::CFileStream(const char * fileName)
{
	this->filename = fileName;
}

CFileStream::~CFileStream()
{
}

int CFileStream::open()
{
	printf("opening file: %s", this->filename);
	return 0;
}

int CFileStream::close()
{
	printf("Closing file: %s", this->filename);
	return 0;
}

int CFileStream::read(void * buffer, unsigned int size)
{
	printf("reading %u chars from %s amd saiving them to %p", size, this->filename, buffer);
	return 0;
}

int CFileStream::write(void * buffer, unsigned int size)
{
	printf("writing first %u chars from '%s' into %s", size, static_cast<char *>(buffer), this->filename);
	return 0;
}
