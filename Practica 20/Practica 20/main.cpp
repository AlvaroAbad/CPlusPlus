// TOMAS: Muy bien la práctcica :-).
// TOMAS: Los cpp me generan muchos warnings cuando pongo el nivel de warnings a máximo nivel.
// ALVARO: se me habia olvidarlo deshabilitarlos en el console tambien, y por alguna razon no me salian si no buildeo teniendo la pestaña de console.h activa
//
#pragma warning(disable: 4820) //warning in various external files
#pragma warning(disable: 4548) //warning in malloc.h
#pragma warning(disable: 4668) // warning in processthreadsapi.h
#pragma warning(disable: 4710) // printf not inlined
#pragma warning(disable: 4242) // random lib unsigned int to short

#include "DarthVader.h"
#include "TIEFighter.h"
#include "XWing.h"
#include "CorelianCorvete.h"


#define MAX_WIDTH static_cast<int>(60) // max screen width
#define MAX_HEIGHT static_cast<int>(60) //max screen height

// ***************************************************************************************
// MAIN
// ***************************************************************************************

int main(int, char*)
{
	std::list<SpaceShip> * spaceShips= new std::list<SpaceShip>(); // pointer to all spaceships
	int serialNumber = 0;
	hidecursor();
	//Random Generator//
	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<short int> distribution(0, MAX_HEIGHT);
	//---------------//

	//START THE BATTLE//
	do {// infinite loop - first we paint all entities then we calculate next position. 
		//SpaceShips Creation//
		while (spaceShips->size() < 5) {
			serialNumber++;
			switch (distribution(generator) % 4) {
			case 0:
				spaceShips->push_back(*(new DarthVader(serialNumber)));
				break;
			case 1:
				spaceShips->push_back(*(new TIEFighter(serialNumber)));
				break;
			case 2:
				spaceShips->push_back(*(new XWing(serialNumber)));
				break;
			case 3:
				spaceShips->push_back(*(new CorelianCorvete(serialNumber)));
				break;
			}
			spaceShips->end()->launch(distribution(generator), distribution(generator));
		}
		//---------------------------//
		std::list<SpaceShip>::iterator it = spaceShips->begin();
		for (std::list<SpaceShip>::iterator it = spaceShips->begin(); it != spaceShips->end(); ++it)//cicle through SpaceShips
		{
			it->paint();
			it->move(spaceShips);
			it->updateLife();
			if (it->getLife() == 0) {
				spaceShips->remove(*it);
			}
		}
		Sleep(50);
		clear(); 

#pragma warning(disable: 4127)//Constant in infinite loop
	} while (1);
#pragma warning(default: 4127)
}

