// TOMAS: Muy bien la práctica.
// TOMAS: Los warinigs "C4626" y "C5027" se producen como consecuencia de las declarciones de constantes no estáticas dentro de las clases.
//        El copilador interpreta que, al ser no estáticas, tienen que tratarse somo variables miembro que no pueden ser modififcadas.
//        Al no poder modificarse no se pueden aplicar los operadores de asignación por defecto (estos al realizar la copia estarian escribiendo
//        en las variables declaradas como ctes al hacer la copia binaria). Una cte.no se puede volver a escribir aunque sea con el mismo valor.
//        Conceptualmente las constantes que tu necesitas son estáticas...
//        Si quieres alguna aclaración más dimeló.
// ALVARO: Lo he entendido gracias no me acordaba y se me pasaba por alto cadavez que repasaba los miembros de la clase base que habia dos variables constantes.
//		   Las he puesto estaticas. y ya no salta el warning.

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
	std::list<SpaceShip *> * spaceShips= new std::list<SpaceShip *>(); // pointer to all spaceships
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
				spaceShips->push_back(new DarthVader(serialNumber));
				break;
			case 1:
				spaceShips->push_back(new TIEFighter(serialNumber));
				break;
			case 2:
				spaceShips->push_back(new XWing(serialNumber));
				break;
			case 3:
				spaceShips->push_back(new CorelianCorvete(serialNumber));
				break;
			}
			spaceShips->back()->launch(distribution(generator), distribution(generator));
		}
		//---------------------------//
		int life;
		std::list<SpaceShip *>::iterator it = spaceShips->begin();
		while (it != spaceShips->end())//cicle through SpaceShips
		{
			(*it)->paint();
			(*it)->move(spaceShips);
			(*it)->updateLife();
			life = (*it)->getLife();
			if ((*it)->getLife() == 0) {
				it=spaceShips->erase(it);
			}
			else {
				++it;
			}
		}
		Sleep(50);
		clear(); 

#pragma warning(disable: 4127)//Constant in infinite loop
	} while (1);
#pragma warning(default: 4127)
}

