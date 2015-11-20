#pragma once
#pragma warning(disable: 4996)//strcpy error(unsecured)
#include "FileFunctions.h"
#include "LinkList.h"
namespace fileOperators {
namespace fileUtilities {
	unsigned int countCoincidence(Archivo *, const char *);
	int addNumbers(Archivo *);
	void getnumbers(Archivo *,TList *);
}
}