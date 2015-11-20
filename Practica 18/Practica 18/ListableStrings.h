#pragma once
#pragma warning(disable: 4996)
#include "Node.h"
#include <stdlib.h>
#include <string>
class ListableStrings:public ListableInterface {
public:
	ListableStrings();
	~ListableStrings();
	virtual ListableInterface * getNext() { return this->next; }
	virtual void setNext(ListableInterface * node) { this->next = node; }
	void setString(const char *);
	const char * getString();
private:
	ListableInterface * next;
	char * string;
};