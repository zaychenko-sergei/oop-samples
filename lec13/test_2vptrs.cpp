// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include <iostream>

/*****************************************************************************/


class Base1
{

public:

	virtual void f1 ()
	{
		std::cout << "Base1::f1 This= " << this << std::endl;
	}

private:

	int x;
};


/*****************************************************************************/


class Base2
{

public:

	virtual void f2 ()
	{
		std::cout << "Base2::f2 This= " << this << std::endl;
	}

private:

	double y;

};


/*****************************************************************************/


class Derived
	: public Base1, public Base2
{

public:

	void f1 () override
	{
		std::cout << "Derived::f1 This= " << this << std::endl;
	}

	void f2 () override
	{
		std::cout << "Derived::f2 This= " << this << std::endl;
	}

private:

	short z;

};


/*****************************************************************************/


int main ()
{
	Derived* pD = new Derived();
	pD->f1();
	pD->f2();
	pD->Base1::f1();
	pD->Base2::f2();

	Base2 * pB = pD;
	pB->f2();

	delete pD;
}


/*****************************************************************************/
