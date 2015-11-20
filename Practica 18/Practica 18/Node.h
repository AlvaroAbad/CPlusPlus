#pragma once
class ListableInterface {

public:
	virtual ~ListableInterface();
	virtual ListableInterface * getNext() = 0;
	virtual void setNext(ListableInterface * node) = 0;

};