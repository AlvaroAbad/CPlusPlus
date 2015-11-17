#pragma once
#pragma once
#include "SpaceShip.h"

class TIEFighter : public SpaceShip {
public:
	TIEFighter(int serialNumber);
	void launch(unsigned short int posX, unsigned short int posY);
	virtual void paint();
	virtual void move(std::list<SpaceShip> *);
};