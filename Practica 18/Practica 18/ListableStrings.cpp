#pragma warning(disable:4514)
#pragma warning(disable:4710)
#include "ListableStrings.h"
#include <stdlib.h>
#include <string>

ListableStrings::ListableStrings()
{
	this->next = nullptr;
	this->string = nullptr;
}

ListableStrings::~ListableStrings()
{
	free(this->string);
}

void ListableStrings::setString(const char * usrString)
{
	unsigned int len=strlen(usrString);
	this->string = static_cast<char*>(malloc(len + 1));
	strcpy(this->string, usrString);
}

const char * ListableStrings::getString()
{
	return this->string;
}

