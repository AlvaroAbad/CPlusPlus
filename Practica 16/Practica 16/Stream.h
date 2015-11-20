#pragma once
#include <stdio.h>
class CStream
{
public:
	virtual ~CStream() {}
	// Open Stream
	virtual int open() = 0;
	// Close Stream
	virtual int close() = 0;
	// Read Stream
	virtual int read(void *, unsigned int) = 0;
	// Write Stream
	virtual int write(void *, unsigned int) = 0;
};

