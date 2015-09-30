// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include <string>
#include <iostream>

/*****************************************************************************/

int main ()
{
	std::string s1, s2;

	std::cout << "Please enter two strings separated by spaces: ";
	std::cin >> s1 >> s2;

	std::cout << "Lengths of strings are: "
		<< s1.length() << " and " << s2.length() << std::endl;

	if ( s1 == s2 )
		std::cout << "Strings are equal" << std::endl;
	else if ( s1 < s2 )
		std::cout << "First string is lexicographically smaller" << std::endl;
	else
		std::cout << "Second string is lexicographically smaller" << std::endl;

	std::cout << ( s1 + s2 ) << std::endl;

	for ( char c : s1 )
		std::cout << c << ' ';
	std::cout << std::endl;
}

/*****************************************************************************/
