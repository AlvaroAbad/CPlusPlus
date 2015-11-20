#pragma once
#include "TIEFighter.h"
class XWing : public SpaceShip {
public:
	XWing(int serialNumber);
	void launch( short int posX,  short int posY);
	virtual void paint();
	virtual void move(std::list<SpaceShip *> *);
};
