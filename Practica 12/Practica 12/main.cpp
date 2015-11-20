#pragma warning(disable: 4710)//printf function not inline
#include<stdio.h>
#include "LinkList.h"

TList * getReversedList(TList * lstSrc) {
	TList * lstRes = new TList(*lstSrc);
	lstRes->reverese();
	return lstRes;

}
TList  getReversedListOriginal(TList lstSrc) {
	TList lstRes = lstSrc;
	lstRes.reverese();
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
	printf("Using original reversList Method\n");
	TList list3 = getReversedListOriginal(*list);
	for (unsigned int i = 0; i < list3.size(); i++)
	{
		printf("%s\n", list3.next());
	}
	printf("Using optimized reversList Method\n");
	TList * list4=getReversedList(list);
	for (unsigned int i = 0; i < list4->size(); i++)
	{
		printf("%s\n", list4->next());
	}
	getchar();
}