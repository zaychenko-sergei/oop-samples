// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _LIBRARY_HPP_
#define _LIBRARY_HPP_

/*****************************************************************************/

#include <vector>
#include <memory>
#include <functional>

/*****************************************************************************/

class Book;
class Author;

/*****************************************************************************/


class Library
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	~ Library ();

/*-----------------------------------------------------------------*/

	void addBook ( std::unique_ptr< Book > _book );

	void forEachBook ( std::function< void ( Book & ) > _action ) const;

/*-----------------------------------------------------------------*/

	void addAuthor ( std::unique_ptr< Author > _author );

	void forEachAuthor ( std::function< void ( Author & ) > _action ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::vector< std::unique_ptr< Book > > m_books;

	std::vector< std::unique_ptr< Author > > m_authors;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif // _LIBRARY_HPP_


