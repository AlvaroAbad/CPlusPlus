#include <stdio.h>
// ***********************************************************
class CBase
{
public:
	CBase()
	{
		printf("CBase()\n");
		m_iValueBase = 0;
		Metodo1();
	}

	~CBase()
	{
		printf("~CBase()\n");
	}

	int Metodo1()
	{
		printf("CBase::Metodo1()\n");
		return 0;
	}

	int Metodo2() {
		printf("CBase::Metodo2()\n");
		return 0;
	}

	int Metodo3()
	{
		Metodo1();
		return 0;
	}

private:
	int m_iValueBase;
};
class CBaseV
{
public:
	CBaseV()
	{
		printf("CBase()\n");
		m_iValueBase = 0;
		MetodoV1();
	}

	virtual ~CBaseV()
	{
		printf("~CBase()\n");
	}

	virtual int MetodoV1()
	{
		printf("CBase::MetodoV1()\n");
		return 0;
	}

	virtual int MetodoV2() {
		printf("CBase::MetodoV2()\n");
		return 0;
	}

	int Metodo2()
	{
		printf("CBase::metodo2()\n");
		MetodoV1();
		return 0;
	}

private:
	int m_iValueBase;
};

// ***********************************************************
class CDerived : public CBase
{
public:
	CDerived()
	{
		printf("CDerived()\n");
		m_iValueDerived = 0;
	}

	~CDerived()
	{
		printf("~CDerived()\n");
	}

	int Metodo1()
	{
		printf("CDerived::Metodo1()\n");
		return 0;
	}


private:
	int m_iValueDerived;
};
class CDerivedV : public CBaseV
{
public:
	CDerivedV()
	{
		printf("CDerivedV()\n");
		m_iValueDerived = 0;
	}

	~CDerivedV()
	{
		printf("~CDerived()\n");
	}

	virtual int MetodoV1()
	{
		printf("CDerived::MetodoV1()\n");
		return 0;
	}


private:
	int m_iValueDerived;
};

// ***********************************************************
class CDerived2 : public CBaseV
{
public:
	CDerived2()
	{
		printf("CDerived2()\n");
		m_iValueDerived = 0;
	}

	~CDerived2()
	{
		printf("~CDerived2()\n");
	}

	virtual int MetodoV1()
	{
		printf("CDerived::MetodoV1_2()\n");
		return 0;
	}

	virtual int MetodoV2()
	{
		printf("CDerived::MetodoV2_2()\n");
		return 0;
	}

private:
	int m_iValueDerived;
};

int main(int, char *) {
	CBaseV * cbaseV = new CBaseV();
	CDerivedV * cbaseVD = new CDerivedV();
	CBaseV * cbaseVD2 = new CDerived2();
	CBase * cbase = new CBase();
	CDerived * cbaseD = new CDerived();
	cbaseVD->Metodo2();
	
	printf("Size of CBaseV: %u\n", sizeof(*cbaseV));//8Bytes(x86)|16Bytes(x64)
	printf("Size of CBaseVD: %u\n", sizeof(*cbaseVD));//12Bytes(x86)|24Bytes(x64)
	printf("Size of CBase: %u\n", sizeof(*cbase));//4Bytes(x86)|4Bytes(x64)
	printf("Size of CBaseD: %u\n", sizeof(*cbaseD));//8Bytes(x86)|8Bytes(x64)
	
	//1. el tamaño de la tabla apuntada por el __vfptr es del tamaño de todas las funciones virtuales declaradas, esto incluye el destructor virtual(tamaño Vtable.PNG).
	//2. dentro de la clase el puntero se situa como primer elemento de la clase por lo que el puntero a una clase con funciones virtuales tambien es un puntero al __vfptr
	//sin embargo el espacio dememoria con las funciones virtuales se encuentra fuera de la memoria reservada para la clase(posicion de vTable en la clase.PNG).
	//3. __vfptr(Vtable) aumenta en 4 Bytes el tamaño de la clase(x89) o 8(x64).
	//por lo que podemos deducir que se le añade un puntero a la clase.
	//4. al llamar a un metodo virtual en el constructor de la clase base el metodo que se llama es al propio metodo de la clase base independientemente si se esta instanciando una clase derivada o la clase base
	//5. Para acceder a una funcion virtual el compilador debe  1)ir al __vfptr, 2)averiguar la direccion de memoria de la VTable, 3)acceder a la posicion de la funcion y 4)por ultimo ejecutarla,
	//por el contrario una funcion no virtual solo necesita 2 pasos para ejecutarse 1)ir a la posicion donde se encuentra la funcion y 2)ejecutarse


	getchar();
}