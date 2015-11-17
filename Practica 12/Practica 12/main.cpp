#pragma warning(disable: 4710)//printf function not inline
#include<stdio.h>
#include "LinkList.h"

TList * getReversedList(TList * lstSrc) {
	TList * lstRes = new TList(*lstSrc);
	lstRes->reverese();
	return lstRes;

}

int main(int, char*) {
	TList * list = new TList();
	list->push("First");
	list->push("Second");
	list->push("third");
	printf("Size: %u\n", list->size());
	TList list2 = *list;
	for (unsigned int i = 0; i < list2.size(); i++)
	{
		printf("%s\n", list2.next());
	}
	TList * list3=getReversedList(&list2);
	for (unsigned int i = 0; i < list3->size(); i++)
	{
		printf("%s\n", list3->next());
	}
	getchar();
}