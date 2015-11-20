#pragma warning(disable: 4514)//unreferenced inline function
#pragma warning(disable: 4710)//function not inline
#include <stdlib.h>
#include <string>
#include "Node.h"
#pragma once

class TList {
private:
	ListableInterface * lastNode;
	ListableInterface * selectedNode;
	ListableInterface * firstNode;
	unsigned int listSize;
public:
	TList();
	TList(TList & obj);
	unsigned int size();
	int push(ListableInterface *);
	ListableInterface * first();
	ListableInterface * next();
	ListableInterface * pop();
	void reset();
	void reverese();
};