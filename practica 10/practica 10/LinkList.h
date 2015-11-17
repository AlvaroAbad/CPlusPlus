#pragma warning(disable: 4514)//unreferenced inline function
#pragma warning(disable: 4710)//printf function not inline
#include <stdlib.h>
#include <string>
#pragma once
class TListNode {
private:

	TListNode * NextTList;
	char * string;

public:
	TListNode();
	char * getString();
	void setString(const char * string);
	TListNode * getNext();
	void setNext(TListNode * node);
	~TListNode();
};

class TList {
private:
	TListNode * lastNode;
	TListNode * selectedNode;
	TListNode * firstNode;
	unsigned int listSize;
public:
	TList();
	~TList();
	unsigned int size();
	int push(const char *);
	const char * first();
	const char * next();
	unsigned int pop(char *, unsigned int);// devuelve la longitud necesaria para almacenar la cadena si el valor pasado no es suficiente
	void reset();
};

