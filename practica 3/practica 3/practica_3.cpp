// TOMAS: Tienes que corregir los dos puntos siguientes.
// TOMAS: Veo mallocs pero no veo frees.
// ALVARO: he extraido el malloc al main y cambiado los metodos para que tengan como parametros un buffer donde almacenar la palabra y la longitud del buffer y devuelven la longitud de la palabra, 
//asi que si el metodo ha devuelto un 0 es porq algo ha ido mal.
// TOMAS: Este fichero me genera muchos warnings cuando pongo el nivel de warnings a máximo nivel.
// ALVARO: he movido los pragma warning encima de los includes pero en mi ordenador no me saltan los warnings y los tengo a tope.

// TOMAS: No veo la utilizadad de los "const" en los tipos "char * const" que usas.
// ALVARO: A mi parecer si un puntero, y mas si es un puntero tras hacer un malloc, no va a cambiar radicalemnte de direcin a la que apunta lo mejor es q sea constante, 
//ya que si vas a acceder a espacios de memoria seguidos puedes acceder sin necesidad de cambiar a donde apunta, asi t aseguras q si haces un free de ese puntero siempre vas a estar en la posicion de memoria correcta.
#pragma warning(disable: 4514)// warnings in corecrt_wstdio.h
#pragma warning(disable: 4710)//swprintf_s not in line
#include <stdio.h>
#include <string>

const char * words[] = { "hola", "adios", "mundo", "arriba", "abajo" };
const int tableWordsSize = sizeof(words) / sizeof(char *);

const char * getString(unsigned int position) {
	if (position < tableWordsSize) {// check if position is within table
		return words[position];// return string
	}
	else {
		return NULL;
	}
}

 unsigned int reverseString(void * const buffer, unsigned int size, const char * pString) {
	unsigned int len = 0;
	// calc length of string
	while (pString[len] != '\0') {
		len++;
	}
	if (size < len) {
		return 0;
	}
	//reserve memory for reversed string
	char * const pReversedString = static_cast<char * const>(buffer);
	//reverese string
	for (unsigned int i = 0; i < len; i++)
	{
		pReversedString[i] = pString[(len - 1) - i];
	}
	pReversedString[len] = '\0';
	return len;
}

 unsigned int reverseString(void * const buffer, unsigned int size, unsigned int position) {// use previous functions to reverse a string from a table
	const char * pString = getString(position);
	if (pString) {
		return reverseString(buffer, size,pString);
	}
	else {
		return 0;
	}
}

int main(int, char *) {
	void * const buffer = malloc(7);
	unsigned int len= reverseString(buffer, 7,3);
	if (len) {
		printf("%s", static_cast<char *>(buffer));
	}
	free(buffer);
	getchar();
}