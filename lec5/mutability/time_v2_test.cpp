// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "time_v2.hpp"
#include <iostream>

/*****************************************************************************/


int main ()
{
	Time t1( 17, 15 );
	Time t2( 23, 10 );
	const char * str1 = t1.ToString();
	const char * str2 = t2.ToString();
	std::cout << str1 << ' ' << str2 << std::endl;
}


/*****************************************************************************/
