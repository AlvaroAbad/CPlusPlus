#include "TIEFighter.h"

TIEFighter::TIEFighter(int serialNumber)
{
	this->serialchar = 'T';
	this->serialnumber = serialNumber;
}

void TIEFighter::launch(unsigned short int posX, unsigned short int posY)
{
	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<short int> distribution(1, 100);
	this->posX = posX;
	this->posY = posY;
	this->life = distribution(generator);
	this->shipsWidth = 5;
	this->Structure[0] = '|';
	this->Structure[1] = '-';
	this->Structure[2] = 'o';
	this->Structure[3] = '-';
	this->Structure[4] = '|';
	this->Structure[5] = '\0';
	this->direction = false;
	this->alignment = Empire;
}

void TIEFighter::paint()
{
	gotoxy(this->posX, this->posY);
	printf("%s", this->Structure);
}

void TIEFighter::move(std::list<SpaceShip>*)
{
	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine generator(seed);

	if (this->posY == MAX_HEIGHT) {
		this->direction = true;
	}
	else if (this->posY == 0) {
		this->direction = false;
	}
	if (this->direction) {
		this->posY--;
	}
	else {
		this->posY++;
	}

	if (this->posX <static_cast<short int>(MAX_WIDTH - this->shipsWidth) && this->posX > 0) {
		std::uniform_int_distribution<short int> distribution(-3, 3);
		this->posX += distribution(generator);
	}
	else if (this->posX >= static_cast<short int>(MAX_WIDTH - this->shipsWidth)) {
		std::uniform_int_distribution<short int> distribution(-3, 0);
		this->posX += distribution(generator);
	}
	else if (this->posX <= 0) {
		std::uniform_int_distribution<short int> distribution(0, 3);
		this->posX += distribution(generator);
	}

}
