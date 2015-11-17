// TOMAS: Muy bien la práctcica :-).
// TOMAS: Los cpp me generan muchos warnings cuando pongo el nivel de warnings a máximo nivel.
// ALVARO: se me habia olvidarlo deshabilitarlos en el console tambien, y por alguna razon no me salian si no buildeo teniendo la pestaña de console.h activa
//
#pragma warning(disable: 4820) //warning in various external files
#pragma warning(disable: 4548) //warning in malloc.h
#pragma warning(disable: 4668) // warning in processthreadsapi.h
#pragma warning(disable: 4710) // printf not inlined
#pragma warning(disable: 4242) // random lib unsigned int to short
#include <stdio.h>
#include <math.h> // for SquerRoot
#include <chrono> // to get time for seed
#include <random> // for the random int generator
#include "consola.h" // to paint in the console




struct TEntity;
typedef void(*funcEntity)(TEntity *);
TEntity * spaceShips[10]; // pointer to all spaceships
#define MAX_WIDTH static_cast<int>(60) // max screen width
#define MAX_HEIGHT static_cast<int>(60) //max screen height

char * const reverseString(const char * pString) {
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

// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	short int m_ix; // Hrozontal position in screen
	short int m_iy; // Vertical position in screen
	char m_style[15]; // String defining the ships style
	int m_alignment; // 1.Empire 2.Rebels
	unsigned int m_shipWidth; // number of characters of the style
	bool m_direction; // if basic direction changes
	funcEntity *m_funcs; // functions of the entity
	TEntity(funcEntity *funcs, short int x, short int y, char style[], int alignment)
	{
		unsigned int i = 0;
		while (*(style + i) != '\0') {
			m_style[i] = style[i];
			i++;
		}
		m_style[i] = '\0';
		m_shipWidth = i - 1;
		m_ix = x;
		m_iy = y;
		m_alignment = alignment;
		m_funcs = funcs;
		m_direction = false;
	}
};
// ***************************************************************************************
// FUNCTIONS
// ***************************************************************************************
#pragma region Darth Vader
void paintDarthVader(TEntity *entity) {
	gotoxy(entity->m_ix, entity->m_iy);
	printf("%s", entity->m_style);
}
void moveDarthVader(TEntity *entity) {// Moves toward closest spaceShip
	TEntity * closestShip = NULL;
	int closestDistX, closestDistY;
	int distX, distY;
	unsigned int dist, closestDist;
	closestDistX = 0;
	closestDistY = 0;
	closestDist = 0;
	for (unsigned int i = 1; i < 10; i++) {// cicle through ships

		if (spaceShips[i] != entity && spaceShips[i]->m_alignment == 2) { // check distance to rebel ships
			distX = spaceShips [i]->m_ix - entity->m_ix;
			distY = spaceShips [i]->m_iy - entity->m_iy;
			dist = static_cast<unsigned int>(sqrt(abs(distX) ^ 2 + abs(distY) ^ 2));
			if (!closestShip || dist < closestDist) { //if is the closest ship change target
				closestShip = spaceShips[i];
				closestDistX = distX;
				closestDistY = distY;
				closestDist = dist;
			}
		}
	}
	//move to closest ship
	if (closestDistX > 0) {
		entity->m_ix++;
	}
	else if (closestDistX < 0) {
		entity->m_ix--;
	}
	if (closestDistY > 0) {
		entity->m_iy++;
	}
	else if (closestDistY < 0) {
		entity->m_iy--;
	}
}
#pragma endregion

#pragma region TIE Fighter
void paintTIEFighter(TEntity *entity) {
	gotoxy(entity->m_ix, entity->m_iy);
	printf("%s", entity->m_style);
}

void moveTIEFighter(TEntity *entity) {// moves randomly horizontaly moves up and down by 1
	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine generator(seed);

	if (entity->m_iy == MAX_HEIGHT) {
		entity->m_direction = true;
	}
	else if (entity->m_iy == 0) {
		entity->m_direction = false;
	}
	if (entity->m_direction) {
		entity->m_iy--;
	}
	else {
		entity->m_iy++;
	}

	if (entity->m_ix <static_cast<short int>(MAX_WIDTH - entity->m_shipWidth) && entity->m_ix > 0) {
		std::uniform_int_distribution<short int> distribution(-3, 3);
		entity->m_ix += distribution(generator);
	}
	else if (entity->m_ix >= static_cast<short int>(MAX_WIDTH - entity->m_shipWidth)) {
		std::uniform_int_distribution<short int> distribution(-3, 0);
		entity->m_ix += distribution(generator);
	}
	else if (entity->m_ix <= 0) {
		std::uniform_int_distribution<short int> distribution(0, 3);
		entity->m_ix += distribution(generator);
	}

}
#pragma endregion

#pragma region Xwing
void paintXWing(TEntity *entity) {
	gotoxy(entity->m_ix, entity->m_iy);
	printf("%s", entity->m_style);
}

void moveXWing(TEntity *entity) {// moves randomly vertically moves left and right by 1
	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine generator(seed);

	if (entity->m_ix >= static_cast<short int>(MAX_WIDTH - entity->m_shipWidth)) {
		entity->m_direction = true;
	}
	else if (entity->m_ix == 0) {
		entity->m_direction = false;
	}

	if (entity->m_direction) {
		entity->m_ix--;
	}
	else {
		entity->m_ix++;
	}

	if (entity->m_iy < MAX_HEIGHT && entity->m_iy>0) {
		std::uniform_int_distribution<short int> distribution(-3, 3);
		entity->m_iy += distribution(generator);
	}
	else if (entity->m_iy >= MAX_HEIGHT) {
		std::uniform_int_distribution<short int> distribution(-3, 0);
		entity->m_iy += distribution(generator);
	}
	else if (entity->m_iy <= 0) {
		std::uniform_int_distribution<short int> distribution(0, 3);
		entity->m_iy += distribution(generator);
	}

}
#pragma endregion

#pragma region corelian corvete
void paintCorelianCorvete(TEntity *entity) {
	gotoxy(entity->m_ix, entity->m_iy);
	if (entity->m_ix < MAX_HEIGHT / 2) {
		printf("%s", entity->m_style);
	}
	else {
		printf("%s", reverseString(entity->m_style));
	}
}

void moveCorelianCorvete(TEntity *entity) {// moves to closest border and moves around screen anticlockwise
	unsigned int distanceToClosestHBorder;
	unsigned int distanceToClosestVBorder;
	if (entity->m_ix == 0 && entity->m_iy != MAX_HEIGHT) {
		entity->m_iy++;
	}
	else if (entity->m_ix != static_cast<short int>(MAX_WIDTH - entity->m_shipWidth) && entity->m_iy == MAX_HEIGHT) {
		entity->m_ix++;
	}
	else if (entity->m_ix == static_cast<short int>(MAX_WIDTH - entity->m_shipWidth) && entity->m_iy != 0) {
		entity->m_iy--;
	}
	else if (entity->m_ix != 0 && entity->m_iy == 0) {
		entity->m_ix--;
	}
	else {
		if (entity->m_ix > MAX_WIDTH / 2) {
			distanceToClosestHBorder = static_cast<unsigned int>(MAX_WIDTH - entity->m_ix);
		}
		else {
			distanceToClosestHBorder = static_cast<unsigned int>(entity->m_ix);
		}
		if (entity->m_iy > MAX_HEIGHT / 2) {
			distanceToClosestVBorder = static_cast<unsigned int>(MAX_HEIGHT - entity->m_iy);
		}
		else {
			distanceToClosestVBorder = static_cast<unsigned int>(entity->m_iy);
		}

		if (distanceToClosestHBorder > distanceToClosestVBorder) {
			if (entity->m_iy > MAX_HEIGHT / 2) {
				entity->m_iy++;
			}
			else {
				entity->m_iy--;
			}
		}
		else {
			if (entity->m_ix > MAX_WIDTH / 2) {
				entity->m_ix++;
			}
			else {
				entity->m_ix--;
			}
		}
	}

}
#pragma endregion
// ***************************************************************************************
// MAIN
// ***************************************************************************************

int main(int, char*)
{
	hidecursor();
	//Random Generator//
	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<short int> distribution(0, MAX_HEIGHT);
	//---------------//

	//SpaceShips Behaviour tables//
	funcEntity funcionesDarthVader[2] = { &paintDarthVader ,&moveDarthVader };
	funcEntity funcionesTIEFighter[2] = { &paintTIEFighter ,&moveTIEFighter };
	funcEntity funcionesXWing[2] = { &paintXWing ,&moveXWing };
	funcEntity funcionesCorelianCorvete[2] = { &paintCorelianCorvete ,&moveCorelianCorvete };
	//---------------------------//

	//SpaceShips Creation//
	spaceShips[0] = new TEntity(funcionesDarthVader, distribution(generator), distribution(generator), "<(0)>", 1);
	spaceShips[1] = new TEntity(funcionesTIEFighter, distribution(generator), distribution(generator), "|(0)|", 1);
	spaceShips[2] = new TEntity(funcionesTIEFighter, distribution(generator), distribution(generator), "|(0)|", 1);
	spaceShips[3] = new TEntity(funcionesTIEFighter, distribution(generator), distribution(generator), "|(0)|", 1);
	spaceShips[4] = new TEntity(funcionesTIEFighter, distribution(generator), distribution(generator), "|(0)|", 1);
	spaceShips[5] = new TEntity(funcionesXWing, distribution(generator), distribution(generator), "8===[o]===8", 2);
	spaceShips[6] = new TEntity(funcionesXWing, distribution(generator), distribution(generator), "8===[o]===8", 2);
	spaceShips[7] = new TEntity(funcionesXWing, distribution(generator), distribution(generator), "8===[o]===8", 2);
	spaceShips[8] = new TEntity(funcionesXWing, distribution(generator), distribution(generator), "8===[o]===8", 2);
	spaceShips[9] = new TEntity(funcionesCorelianCorvete, distribution(generator), distribution(generator), "[]===<>", 2);
	
	//---------------------------//

	//START THE BATTLE//
	do {// infinite loop - first we paint all entities then we calculate next position. 

		for (unsigned int z = 0; z < 2; z++)//cicle through functions
		{
			for (unsigned int y = 0; y < 10; y++) {// cicle throught entities
				spaceShips[y]->m_funcs[z](spaceShips [y]);//triguer function of entity
			}
		}
		Sleep(200);
		clear(); 

#pragma warning(disable: 4127)//Constant in infinite loop
	} while (1);
#pragma warning(default: 4127)
}

