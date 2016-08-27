#include "book_bad.hpp"

#include <iostream>


/*****************************************************************************/


Book * createTestBook ()
{
	std::vector< Chapter * > chapters;
	chapters.push_back( new Chapter( "AAA", 12 ) );
	chapters.push_back( new Chapter( "BBB", 15 ) );
	chapters.push_back( new Chapter( "CCC", 10 ) );

	return new Book( "Some Title", chapters );
}


/*****************************************************************************/


int main ()
{
	Book * pBook = createTestBook();

	std::vector< Chapter * > chapters = pBook->getChapters();
	for ( Chapter const * pChapter : chapters )
		std::cout << pChapter->getTitle() << std::endl;

	delete pBook;
}


/*****************************************************************************/
