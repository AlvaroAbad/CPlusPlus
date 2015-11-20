#include "CorelianCorvete.h"

CorelianCorvete::CorelianCorvete(int serialNumber)
{
	this->serialchar = 'C';
	this->serialnumber = serialNumber;
}

void CorelianCorvete::launch( short int posX,  short int posY)
{

	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<unsigned short int> distribution(1, 100);
	this->posX = posX;
	this->posY = posY;
	this->life = distribution(generator);
	this->shipsWidth = 7;
	this->Structure[0] = '[';
	this->Structure[1] = ']';
	this->Structure[2] = '=';
	this->Structure[3] = '=';
	this->Structure[4] = '=';
	this->Structure[5] = '<';
	this->Structure[6] = '>';
	this->Structure[7] = '\0';
	this->direction = false;
	this->alignment = Rebels;
}

void CorelianCorvete::paint()
{
	gotoxy(this->posX, this->posY);
	if (this->posX < MAX_HEIGHT / 2) {
		printf("%s", this->Structure);
	}
	else {
		printf("%s", reverseString(this->Structure));
	}
}

void CorelianCorvete::move(std::list<SpaceShip *>*)
{
	unsigned int distanceToClosestHBorder;
	unsigned int distanceToClosestVBorder;
	if (this->posX == 0 && this->posY != MAX_HEIGHT) {
		this->posY++;
	}
	else if (this->posX != static_cast<short int>(MAX_WIDTH - this->shipsWidth) && this->posY == MAX_HEIGHT) {
		this->posX++;
	}
	else if (this->posX == static_cast<short int>(MAX_WIDTH - this->shipsWidth) && this->posY != 0) {
		this->posY--;
	}
	else if (this->posX != 0 && this->posY == 0) {
		this->posX--;
	}
	else {
		if (this->posX > MAX_WIDTH / 2) {
			distanceToClosestHBorder = static_cast<unsigned int>(MAX_WIDTH - this->posX);
		}
		else {
			distanceToClosestHBorder = static_cast<unsigned int>(this->posX);
		}
		if (this->posY > MAX_HEIGHT / 2) {
			distanceToClosestVBorder = static_cast<unsigned int>(MAX_HEIGHT - this->posY);
		}
		else {
			distanceToClosestVBorder = static_cast<unsigned int>(this->posY);
		}

		if (distanceToClosestHBorder > distanceToClosestVBorder) {
			if (this->posY > MAX_HEIGHT / 2) {
				this->posY++;
			}
			else {
				this->posY--;
			}
		}
		else {
			if (this->posX > MAX_WIDTH / 2) {
				this->posX++;
			}
			else {
				this->posX--;
			}
		}
	}
}

char * const CorelianCorvete::reverseString(const char * pString)
{
		unsigned int len = 0;
		while (pString[len] != '\0') {
			len++;
		}
		char * const pReversedString = static_cast<char * const>(malloc(len));
		for (unsigned int i = 0; i < len; i++)
		{
			switch (pString[(len - 1) - i]) {
			case ']': pReversedString[i] = '[';
				break;
			case '[': pReversedString[i] = ']';
				break;
			case '<': pReversedString[i] = '>';
				break;
			case '>': pReversedString[i] = '<';
				break;
			default:
				pReversedString[i] = pString[(len - 1) - i];
				break;
			}

		}
		pReversedString[len] = '\0';
		return pReversedString;
	
}
