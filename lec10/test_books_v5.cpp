#include <iostream>

#include "book_v5.hpp"
#include "chapter.hpp"

/*****************************************************************************/


std::unique_ptr< Book > createTestBook ()
{
	std::unique_ptr< Book > pBook( new Book( "Some Title" ) );

	pBook->addChapter( std::make_unique< Chapter >( "AAA", 12 ) );
	pBook->addChapter( std::make_unique< Chapter >( "BBB", 15 ) );
	pBook->addChapter( std::make_unique< Chapter >( "CCC", 10 ) );

	return pBook;
}


/*****************************************************************************/


int main ()
{
	std::unique_ptr< Book > pBook = createTestBook();

	pBook->forEachChapter(
		[] ( Chapter const & _chapter )
		{
			std::cout << _chapter.getTitle() << std::endl;
		}
	);
}


/*****************************************************************************/
