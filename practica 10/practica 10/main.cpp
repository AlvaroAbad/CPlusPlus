// TOMAS: Bastante bien. Mira los comentarios a continuaci�n.
// TOMAS: Los cpp me generan muchos warnings cuando pongo el nivel de warnings a m�ximo nivel.
// ALVARO: Ya esta arreglado,Sigo sin entender porq a veces solo me dice los warnings de la pesta�a activa cuando hago el build.
// TOMAS: El casting de la l�nea 115 no deber�a ser necesario.
// ALVARO: cierto pense que como el free te pedia un void * me saltaria un warning por hacer un Casting automaticamente.
// TOMAS: Si al pop no le paso el tama�o adecuado retorna un 0 por lo que no me da pista
//        de cuanto le necesito pasar...
// ALVARO: he cambiado el enfoque para que sea mas intuitivo, y a�adido un comentario en el .h
// ahora pop si le pasas el tama�o incorrecto te devolvera el tama�o necesario, y si le pasas un tama�o corrcto te devuelve 0
#pragma warning(disable: 4710)//printf function not inline
#include<stdio.h>
#include "LinkList.h"

int main(int, char*) {
	char * buffer =static_cast<char *>(malloc(100));
	TList * list = new TList();
	list->push("First");
	printf("Size: %u\n", list->size());
	list->push("Second");
	printf("Size: %u\n", list->size());
	printf("First String: %s\n", list->first());
	printf("Next String: %s\n", list->next());
	printf("Next String: %s\n", list->next());
	list->pop(buffer, 100);
	printf("POP: %s\n", buffer);
	printf("First String: %s\n", list->first());
	list->push("third");
	printf("Size: %u\n", list->size());
	list->reset();
	printf("Size: %u\n", list->size());
	getchar();
}