#include <stdio.h>
#pragma warning(disable: 4514)
#pragma warning(disable: 4710)
void getIntBytes(const int  * const pInt) { //same as previows method but using reinterprete_cast.
	printf_s("number=%X\n", *pInt);
	for (unsigned int i = 0; i < sizeof(*pInt); i++) {
		printf_s("byte-%u(dire-%p)=%c(%u)\n", i, (reinterpret_cast<const unsigned char * const>(pInt) + i), reinterpret_cast<const unsigned char * const>(pInt)[i], reinterpret_cast<const unsigned char * const>(pInt)[i]);
	}
}

int getGreatestInt(const int * const pInt, int size) {
	const int * pGreatstInt = pInt;//pointer to the greatest integer in the table.
	for (unsigned int i = 0; i < size/ sizeof(int); i++) {//cicle through the table.
		if (pInt[i] > *pGreatstInt) {//compare current greatest with integer in table.
			pGreatstInt = pInt+i;// if checked integer is greater than the current greatest we change pointer address.
		}
	}
	return *pGreatstInt;// return the greatest integer.
}
int getGreatestChar(const char * const pChar,unsigned int size) {// same as before but with chars
	const char * pGreatstChar = pChar;
	for (unsigned int i = 0; i < size; i++) {
		if (pChar[i] > *pGreatstChar) {
			pGreatstChar = pChar + i;
		}
	}
	return *pGreatstChar;
}

const unsigned char * getGreatestByte(const int * const pInt, unsigned int size) { //same as previous but with reinterprete_cast
	const unsigned char * pGreatstInt = reinterpret_cast<const unsigned char * const>(pInt);
	for (unsigned int i = 0; i < size; i++) {
		if (reinterpret_cast<const unsigned char * const>(pInt)[i] > *pGreatstInt) {
			pGreatstInt = (reinterpret_cast<const unsigned char * const>(pInt) + i);
		}
	}
	return pGreatstInt;
}

void reverseString(char tChar[]) {
	char aux;// auxiliar variable to store char.
	unsigned int tamaño = 0;// variable to store string length.
	while (tChar[tamaño] != '\0') { //cicle throught table until scape character found.
		tamaño++;//increment size
	}
	for (unsigned int i = 0; i < tamaño/2; i++) {//cicle for half the size of the word
		aux = tChar[i];//store the letter
		tChar[i] = tChar[(tamaño-1) - i];//move the las leter to the first position
		tChar[(tamaño - 1) - i] = aux;//place the stored letter to the las position.

	}
}
int main(int, char*) {
	// PRÁCTICAS.
	// 1.- Dado un entero obtener por separado cada uno de sus bytes usando operaciones de punteros. -OK
	// 2.- Dada la tabla de enteros int tabla[] = {1, 3, 2, 5, 3, 0xFFFFFFFF, 2}
	//		 Realizar código que obtenga el entero mayor usando aritmética de punteros. -OK
	// 3.- Dada la tabla de caracteres char tabla[] = {'a', 'z', 'f', 'g', '2'}
	//		 Realizar código que obtenga el caracter mayor usando aritmética de punteros.-OK
	// 4.- Igual que el 2 pero que obtenga la posición del byte mayor.
	// 5.- Generar código que dada una cadena le de la vuelta: ejmp "hola" -> "aloh"
	
	int number = 3569854213;
	int tablaInt[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2 };
	char tablaChar[] = { 'a', 'z', 'f', 'g', '2' };
	const unsigned char * pGreatestByte;
	getIntBytes(&number);
	printf("greatest number in the table is: %d\n", getGreatestInt(tablaInt, sizeof(tablaInt)));
	printf("greatest Char in the table is: %c\n", getGreatestChar(tablaChar, sizeof(tablaChar)));
	pGreatestByte = getGreatestByte(tablaInt, sizeof(tablaInt));
	printf("greatest byte in the table is: %p(%X)\n", pGreatestByte,*pGreatestByte);
	char tablaString[] = "fistrenchungen";
	printf_s("%s\n", tablaString);
	reverseString(tablaString);
	printf_s("%s\n", tablaString);
	getchar();
}