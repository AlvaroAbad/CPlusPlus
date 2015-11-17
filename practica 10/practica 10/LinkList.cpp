#include "LinkList.h"

TList::TList()
{
		this->lastNode = nullptr;
		this->selectedNode = nullptr;
		this->firstNode = nullptr;
		this->listSize = 0;
}

TList::~TList()
{
	this->reset();
}

unsigned int TList::size()
{
	return this->listSize;
}

int TList::push(const char * string)
{
	TListNode * node= new TListNode();
	node->setString(string);
	if (this->lastNode) {
		this->lastNode->setNext(node);
	}
	else {
		this->firstNode = node;
	}
	
	this->lastNode = node;
	if (!this->selectedNode) {//if selected is not set set it to first node
		this->selectedNode = this->firstNode;
	}
	return static_cast<int>(this->listSize++);
}

const char * TList::first()
{
	this->selectedNode = this->firstNode;
	return this->firstNode->getString();
}

const char * TList::next()
{
	const char * string = this->selectedNode->getString();
	this->selectedNode = this->selectedNode->getNext();
	if (!this->selectedNode) {
		this->selectedNode = this->firstNode;
	}
	return string;
}

unsigned int TList::pop(char * buffer, unsigned int size)//modificar funcion para aceptar un buffer y devolver un entero reflejando un error
{
	unsigned int len = static_cast<unsigned int>(strlen(this->firstNode->getString()));
	if (size > len) {
		strcpy_s(buffer, static_cast<rsize_t>(size), this->firstNode->getString());
		TListNode * node = this->firstNode;
		this->firstNode = node->getNext();
		delete(node);
		this->listSize--;
		return 0;
	}
	else {
		return len;
	}
}

void TList::reset()
{
	TListNode * node = this->firstNode;
	TListNode * nodeToDelete;
	while (node) {
		nodeToDelete = node;
		node = node->getNext();
		delete (nodeToDelete);
	}
	this->listSize = 0;
}
//TLISTNODE FUNCTIONS.
TListNode::TListNode()
{
	this->string = nullptr;
	this->NextTList = nullptr;
}

char * TListNode::getString()
{
	return this->string;
}

void TListNode::setString(const char * usrString)
{	
	unsigned int len = static_cast<unsigned int>(strlen(usrString)) + 1;
	char * tmpString = static_cast<char *>(malloc(len));
	strcpy_s(tmpString,len, usrString);
	this->string = tmpString;
}

TListNode * TListNode::getNext()
{
	return this->NextTList;
}

void TListNode::setNext(TListNode * node)
{
	this->NextTList = node;
}

TListNode::~TListNode()
{
	if (this->string) {
		free(this->string);
	}
}
