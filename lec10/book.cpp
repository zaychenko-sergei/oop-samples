// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "book.hpp"
#include "chapter.hpp"

/*****************************************************************************/


Book::Book ( std::string const & _title )
	: m_title( _title )
{}


/*****************************************************************************/


Book::Book (
		std::string const & _title
	,	std::initializer_list< Chapter * > _chapters 
)	:	m_title( _title )
{
	for ( Chapter * pChapter : _chapters )
		addChapter( std::unique_ptr< Chapter >( pChapter ) );
}


/*****************************************************************************/


bool Book::hasChapter ( Chapter const & _chapter ) const
{
	int nChapters = getChaptersCount();
	for ( int i = 0; i < nChapters; i++ )
		if ( m_chapters[ i ].get() == &_chapter )
			return true;

	return false;
}


/*****************************************************************************/


void Book::addChapter ( std::unique_ptr< Chapter > _chapter )
{
	m_chapters.push_back( std::move( _chapter ) );
}


/*****************************************************************************/


void Book::removeChapter ( Chapter const & _chapter )
{
	int nChapters = getChaptersCount();
	for ( int i = 0; i < nChapters; i++ )
		if ( m_chapters[ i ].get() == &_chapter )
		{
			m_chapters.erase( m_chapters.begin() + i );
			return;
		}

	throw std::logic_error( "Chapter does not exists in book" );
}


/*****************************************************************************/


void Book::clearChapters ()
{
	m_chapters.clear();
}


/*****************************************************************************/

