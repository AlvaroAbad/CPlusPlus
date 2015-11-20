#pragma warning(disable:4514)
#pragma warning(disable:4710)
#include "LinkList.h"

TList::TList()
{
		this->lastNode = nullptr;
		this->selectedNode = nullptr;
		this->firstNode = nullptr;
		this->listSize = 0;
}

TList::TList(TList & obj)
{
	this->lastNode = nullptr;
	this->selectedNode = nullptr;
	this->firstNode = nullptr;
	this->listSize = 0;
	if (obj.firstNode) {
		this->push(obj.firstNode);
		ListableInterface * aux = obj.firstNode->getNext();
		while (aux) {
			this->push(aux);
			aux = aux->getNext();
		}
	}

}

unsigned int TList::size()
{
	return this->listSize;
}

int TList::push(ListableInterface * node)
{
	if (this->lastNode) {
		this->lastNode->setNext(node);
	}
	else {
		this->firstNode = node;
	}
	
	this->lastNode = node;
	if (!this->selectedNode) {
		this->selectedNode = this->firstNode;
	}
	return static_cast<int>(this->listSize++);
}

ListableInterface * TList::first()
{
	return this->firstNode;
}

ListableInterface * TList::next()
{
	ListableInterface * node = this->selectedNode;
	this->selectedNode = this->selectedNode->getNext();
	if (!this->selectedNode) {
		this->selectedNode = this->firstNode;
	}
	return node;
}

ListableInterface * TList::pop()//modificar funcion para aceptar un buffer y devolver un entero reflejando un error
{
	ListableInterface * node = this->firstNode;
		this->firstNode = node->getNext();
		node->setNext(nullptr);
		if (this->selectedNode == node) {
			this->selectedNode = this->firstNode;
		}
		this->listSize--;
		return node;
	
}

void TList::reset()
{
	ListableInterface * node = this->firstNode;
	ListableInterface * nodeToDelete;
	while (node) {
		nodeToDelete = node;
		node = node->getNext();
		delete (nodeToDelete);
	}
	this->listSize = 0;
}
void TList::reverese()
{
	ListableInterface * prevNode = this->firstNode;
	ListableInterface * node = this->firstNode->getNext();
	ListableInterface * nextNode;
	while(node){
	nextNode = node->getNext();
	node->setNext(prevNode);
	prevNode = node;
	node = nextNode;
	}
	node = this->firstNode;
	node->setNext(NULL);
	this->firstNode = this->lastNode;
	this->lastNode = node;
	this->selectedNode = this->firstNode;
}