#pragma once
#pragma once
#include "SpaceShip.h"

class TIEFighter : public SpaceShip {
public:
	TIEFighter(int serialNumber);
	void launch( short int posX, short int posY);
	virtual void paint();
	virtual void move(std::list<SpaceShip *> *);
};