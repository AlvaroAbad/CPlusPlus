// TOMAS: Muy bien la práctica.
// TOMAS: Los includes de librerías que haces en los ficheros de cabecera es mejor situarlos
//        en los .cpp pues realmente el fichero cabecera no depende de ellos sólo el fichero implementación los necesita.
//        De esta manera disminuyes el acople con los módulos que usarán la lista.
// ALVARO: movidos los includes a los CPPs.
// TOMAS: PIENSA EN: Al sacar la lógica de los nodos a la clase de los elementos obligas a que cada clase de elemento que se 
//        quiera almacenar tenga que implementar su sistema, una alternativa hubiera sido que "ListableInterface"
//        no hubiera sido un interfaz sino una clase con la implementación por defecto, pero esto se sale de las especificaciones
//        de la práctica.
// ALVARO: Mi idea era esa( basandome en la interfaz Comparable de java) que si quieres guardar en mi lista tus objetos 
//		   debes implementar la interfaz "ListableInterface" e implementar la devolucion del puntero, dandole libertad 
//		   si quiere hacer algo mas como una eliminacion fisica o logica, si el elemento al que apunto lo tengo marcado 
//		   como borrado devuelvo el siguiente que no este marcado como borrado.

#pragma warning(disable:4514)
#pragma warning(disable:4710)
#include "LinkList.h"
#include "ListableStrings.h"
#include <stdlib.h>
#include <string>
int main(int, char[]) {
	TList * stringList = new TList();
	ListableStrings * first = new ListableStrings();
	first->setString("First");
	stringList->push(first);
	printf("%u\n", stringList->size());
	ListableStrings * second = new ListableStrings();
	second->setString("Second");
	stringList->push(second);
	printf("%u\n", stringList->size());
	ListableStrings * third = new ListableStrings();
	third->setString("Third");
	stringList->push(third);
	printf("%u\n", stringList->size());
	ListableStrings * firstPoP= static_cast<ListableStrings *>(stringList->pop());
	printf("POP: %s\n", firstPoP->getString());
	for (size_t i = 0; i < stringList->size(); i++)
	{
		printf("Next: %s\n", static_cast<ListableStrings *>(stringList->next())->getString());
	}
	getchar();
}