#pragma once
#pragma warning(disable: 4242) // random lib unsigned int to short
#pragma warning(disable: 4458) // declaration hides clas member,
//entioendo lo que quiere decir y como solucionarlo pero es costumre mia declarar el parametro de los constructores igual que los miembros
#pragma warning(disable: 4548) //warning in malloc.h
#pragma warning(disable: 4820) //4 Byte padding in time.h
#pragma warning(disable: 4710) // printf not inlined
#include <stdio.h>
#include <math.h> // for SquerRoot
#include <chrono> // to get time for seed
#include <random> // for the random int generator
#include "consola.h" // to paint in the console
#include <list> // for the List
class SpaceShip
{
public:
	enum alignment { Empire, Rebels };
protected:
	static const short int MAX_WIDTH = 60;
	static const short int MAX_HEIGHT = 60;
	int serialnumber;
	unsigned char serialchar;
	short int posX; // Hrozontal position in screen
	short int posY; // Vertical position in screen
	char Structure[15]; // String defining the ships style
	enum alignment alignment; // 1.Empire 2.Rebels
	unsigned int shipsWidth; // number of characters of the style
	unsigned short int life;
	bool direction; // if basic direction changes
public:
	void updateLife() { this->life--; }
	virtual void paint() = 0;
	virtual void move(std::list<SpaceShip *> *) = 0;
	virtual void launch(short int, short int) = 0;
	//GETTERS
	enum alignment getAlignment() { return this->alignment; }
	int getSerialNumber() { return this->serialnumber; }
	unsigned char getSerialChar() { return this->serialchar; }
	short int getPosX() { return this->posX; }
	short int getPosY() { return this->posY; }
	unsigned short int getLife() { return this->life; }
	//OPERATORS
	const bool &operator !=(const SpaceShip * const  obj) const {
		if (this->serialchar == obj->serialchar && this->serialnumber == obj->serialnumber) {
			return true;
		}
		else {
			return false;
		}
	}
};