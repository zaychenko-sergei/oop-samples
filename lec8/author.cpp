// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "author.hpp"

/*****************************************************************************/


Author::Author ( std::string const & _name, int _birthYear )
	:	m_name( _name ), 
		m_birthYear( _birthYear )
{
}


/*****************************************************************************/


bool Author::hasBook ( Book const & _book ) const
{
	return m_books.find( & _book ) != m_books.end();
}


/*****************************************************************************/


void Author::addBook ( Book const & _book )
{
	if ( hasBook( _book ) )
		throw std::logic_error( "Duplicate book" );

	m_books.insert( & _book );
}


/*****************************************************************************/


void Author::removeBook ( Book const & _book )
{
	auto it = m_books.find( & _book );
	if ( it == m_books.end() )
		throw std::logic_error( "No such book" );

	m_books.erase( it );
}


/*****************************************************************************/


void Author::clearBooks ()
{
	m_books.clear();
}


/*****************************************************************************/


void Author::forEachBook ( std::function< void ( Book const & ) > _action ) const
{
	for ( Book const * pBook : m_books )
		_action( * pBook );
}


/*****************************************************************************/
