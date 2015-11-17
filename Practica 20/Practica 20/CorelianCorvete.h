#pragma once
#include "TIEFighter.h"
class CorelianCorvete : public SpaceShip {
public:
	CorelianCorvete(int serialNumber);
	void launch(unsigned short int posX, unsigned short int posY);
	virtual void paint();
	virtual void move(std::list<SpaceShip> *);
private:
	char * const reverseString(const char *);
};