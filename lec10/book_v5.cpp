// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "book_v5.hpp"
#include "chapter.hpp"

#include <algorithm>

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


void Book::forEachChapter ( std::function< void ( Chapter const & ) > _action ) const
{
	for ( auto const & chapterPtr : m_chapters )
		_action( * chapterPtr );
}


/*****************************************************************************/


const Chapter *
Book::findChapter ( std::function< bool ( Chapter const & ) > _filter ) const
{
	auto it = std::find_if(
					m_chapters.begin(),
					m_chapters.end(),
					[ & ] ( auto const & chapterPtr )
					{
						return _filter( * chapterPtr );
					}
			  );

	return ( it == m_chapters.end() ) ? nullptr : it->get();
}


/*****************************************************************************/


int Book::countChaptersWith ( std::function< bool ( Chapter const & ) > _filter ) const
{
	return std::count_if(
				m_chapters.begin(),
				m_chapters.end(),
				[ & ] ( auto const & chapterPtr )
				{
					return _filter( *chapterPtr );
				}
		   );
}


/*****************************************************************************/


bool Book::allOf ( std::function< bool ( Chapter const & ) > _filter ) const
{
	return std::all_of(
		m_chapters.begin(),
		m_chapters.end(),
		[ & ] ( auto const & chapterPtr )
		{
			return _filter( *chapterPtr );
		}
	);
}


/*****************************************************************************/
