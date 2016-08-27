#include <iostream>

#include "book.hpp"
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


Book * createAnotherTestBook ()
{
    return new Book( 
        "Another Title",
        {
            new Chapter( "AAA", 12 ),
            new Chapter( "BBB", 15 ),
            new Chapter( "CCC", 10 )
        }
    );
}


/*****************************************************************************/


int main ()
{
    Book * pBook1 = createTestBook();
    Book * pBook2 = createAnotherTestBook();

    int nChapters = pBook1->getChaptersCount();
    for ( int i = 0; i < nChapters; i++ )
        std::cout << pBook1->getChapter( i ).getTitle() << std::endl;

    nChapters = pBook2->getChaptersCount();
    for ( int i = 0; i < nChapters; i++ )
        std::cout << pBook2->getChapter( i ).getTitle() << std::endl;

    delete pBook1;
    delete pBook2;
}

/*****************************************************************************/
