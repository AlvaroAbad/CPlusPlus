#include "DarthVader.h"

DarthVader::DarthVader(int serialNumber) {
	this->serialchar = 'D';
	this->serialnumber = serialNumber;
}

void DarthVader::launch(unsigned short int posX, unsigned short int posY)
{
	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<short int> distribution(1, 100);
	this->posX = posX;
	this->posY = posY;
	this->life = distribution(generator);
	this->shipsWidth = 5;
	this->Structure[0] = '<';
	this->Structure[1] = '-';
	this->Structure[2] = 'o';
	this->Structure[3] = '-';
	this->Structure[4] = '>';
	this->Structure[5] = '\0';
	this->direction = false;
	this->alignment = Empire;
}

void DarthVader::paint()
{
	gotoxy(this->posX, this->posY);
	printf("%s", this->Structure);
}

void DarthVader::move(std::list<SpaceShip> * spaceShips)
{
	SpaceShip * closestShip = NULL;
	int closestDistX, closestDistY;
	int distX, distY;
	unsigned int dist, closestDist;
	closestDistX = 0;
	closestDistY = 0;
	closestDist = 0;
	std::list<SpaceShip>::iterator it = spaceShips->begin();
	for (std::list<SpaceShip>::iterator it = spaceShips->begin(); it !=  spaceShips->end();++it) {// cicle through ships

		if (*it != this && it->getAlignment() == Rebels) { // check distance to rebel ships
			distX = it->getPosX() - this->posX;
			distY = it->getPosY() - this->posY;
			dist = static_cast<unsigned int>(sqrt(abs(distX) ^ 2 + abs(distY) ^ 2));
			if (!closestShip || dist < closestDist) { //if is the closest ship change target
				closestShip = &*it;
				closestDistX = distX;
				closestDistY = distY;
				closestDist = dist;
			}
		}
	}
	//move to closest ship
	if (closestDistX > 0) {
		this->posX++;
	}
	else if (closestDistX < 0) {
		this->posX--;
	}
	if (closestDistY > 0) {
		this->posY++;
	}
	else if (closestDistY < 0) {
		this->posY--;
	}
}
