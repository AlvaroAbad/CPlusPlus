#include "ListableStrings.h"

ListableStrings::ListableStrings()
{
	this->next = nullptr;
	this->string = nullptr;
}

ListableStrings::~ListableStrings()
{
	free(this->string);
}

void ListableStrings::setString(const char * string)
{
	unsigned int len=strlen(string);
	this->string = static_cast<char*>(malloc(len + 1));
	strcpy(this->string, string);
}

const char * ListableStrings::getString()
{
	return this->string;
}

