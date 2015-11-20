#include "XWing.h"

XWing::XWing(int serialNumber)
{
	this->serialchar = 'X';
	this->serialnumber = serialNumber;
}

void XWing::launch( short int posX,  short int posY)
{
	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<unsigned short int> distribution(1, 100);
	this->posX = posX;
	this->posY = posY;
	this->life = distribution(generator);
	this->shipsWidth = 5;
	this->Structure[0] = ':';
	this->Structure[1] = '>';
	this->Structure[2] = 'o';
	this->Structure[3] = '<';
	this->Structure[4] = ':';
	this->Structure[5] = '\0';
	this->direction = false;
	this->alignment = Rebels;
}

void XWing::paint()
{
	gotoxy(this->posX, this->posY);
	printf("%s", this->Structure);
}

void XWing::move(std::list<SpaceShip *>*)
{
	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine generator(seed);

	if (this->posX >= static_cast<short int>(MAX_WIDTH - this->shipsWidth)) {
		this->direction = true;
	}
	else if (this->posX == 0) {
		this->direction = false;
	}

	if (this->direction) {
		this->posX--;
	}
	else {
		this->posX++;
	}

	if (this->posY < MAX_HEIGHT && this->posY>0) {
		std::uniform_int_distribution<short int> distribution(-3, 3);
		this->posY += distribution(generator);
	}
	else if (this->posY >= MAX_HEIGHT) {
		std::uniform_int_distribution<short int> distribution(-3, 0);
		this->posY += distribution(generator);
	}
	else if (this->posY <= 0) {
		std::uniform_int_distribution<short int> distribution(0, 3);
		this->posY += distribution(generator);
	}

}
