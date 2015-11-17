#pragma once
#include "TIEFighter.h"
class XWing : public SpaceShip {
public:
	XWing(int serialNumber);
	void launch(unsigned short int posX, unsigned short int posY);
	virtual void paint();
	virtual void move(std::list<SpaceShip> *);
};
