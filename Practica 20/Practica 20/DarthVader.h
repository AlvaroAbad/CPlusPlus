#pragma once
#include "SpaceShip.h"

class DarthVader : public SpaceShip {
public:
	DarthVader(int serialNumber);
	void launch( short int posX,  short int posY);
	virtual void paint();
	virtual void move(std::list<SpaceShip *> *);
};