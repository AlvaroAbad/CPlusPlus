#pragma warning(disable:4514)
#pragma warning(disable:4710)
#include "LinkList.h"
#include "ListableStrings.h"
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