// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include <iostream>

/*****************************************************************************/

class Base1
{
public:
	virtual void f ()
	{
		std::cout << "Base1::f() this = " << this << std::endl;
	}
};

/*****************************************************************************/

class Base2
{
public:
	virtual void f ()
	{
		std::cout << "Base2::f() this = " << this << std::endl;
	}
};

/*****************************************************************************/

class Derived
	: public Base1, public Base2
{
public:
	void f () override
	{
		std::cout << "Derived::f() this = " << this << std::endl;
		Base1::f();
		Base2::f();
	}
};

/*****************************************************************************/

int main ()
{
	Derived * pDerived = new Derived();
	std::cout << "Calling directly : pDerived = " << pDerived << std::endl;
	pDerived->f();

	Base1 * pBase1 = pDerived;
	std::cout << "Calling through 1st base : pBase1 = " << pBase1 << std::endl;
	pBase1->f();

	Base2 * pBase2 = pDerived;
	std::cout << "Calling through 2nd base : pBase2 = " << pBase2 << std::endl;
	pBase2->f();

	delete pDerived;
}

/*****************************************************************************/
