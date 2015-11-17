#pragma once
#include "SpaceShip.h"

class DarthVader : public SpaceShip {
public:
	DarthVader(int serialNumber);
	void launch(unsigned short int posX, unsigned short int posY);
	virtual void paint();
	virtual void move(std::list<SpaceShip> *);
};