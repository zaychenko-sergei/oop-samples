// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "library.hpp"
#include "author.hpp"
#include "chapter.hpp"
#include "book_v7.hpp"

/*****************************************************************************/


Library::~Library () = default;


/*****************************************************************************/


void 
Library::addBook ( std::unique_ptr< Book > _book )
{
	m_books.push_back( std::move( _book ) );
}


/*****************************************************************************/


void Library::forEachBook ( std::function< void ( Book & ) > _action ) const
{
	for ( auto const & bookPtr : m_books )
		_action( * bookPtr );
}


/*****************************************************************************/


void
Library::addAuthor ( std::unique_ptr< Author > _author )
{
	m_authors.push_back( std::move( _author ) );
}



/*****************************************************************************/


void Library::forEachAuthor ( std::function< void ( Author & ) > _action ) const
{
	for ( auto const & authorPtr : m_authors )
		_action( * authorPtr );
}


/*****************************************************************************/
