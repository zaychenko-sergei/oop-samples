#include <iostream>

#include "book_v2.hpp"
#include "chapter.hpp"

/*****************************************************************************/


Book * createTestBook ()
{
	Book * pBook = new Book( "Some Title" );

	pBook->addChapter( new Chapter( "AAA", 12 ) );
	pBook->addChapter( new Chapter( "BBB", 15 ) );
	pBook->addChapter( new Chapter( "CCC", 10 ) );

	return pBook;
}


/*****************************************************************************/


int main ()
{
	Book * pBook = createTestBook();

	for ( Chapter * pChapter : pBook->chapters() )
		std::cout << pChapter->getTitle() << std::endl;

	delete pBook;
}


/*****************************************************************************/
