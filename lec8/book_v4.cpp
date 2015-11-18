// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "book_v4.hpp"
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


Chapter const * 
Book::findChapterByTitle ( std::string const & _title ) const
{
	auto it = m_chaptersByTitle.find( _title );
	return ( it != m_chaptersByTitle.end() ) ? it->second : nullptr;
}


/*****************************************************************************/


void Book::addChapter ( std::unique_ptr< Chapter > _chapter )
{
	if ( findChapterByTitle( _chapter->getTitle() ) )
		throw std::logic_error( "Chapter with duplicate title" );

	m_chaptersByTitle[ _chapter->getTitle() ] = _chapter.get();

	m_chapters.push_back( std::move( _chapter ) );
}


/*****************************************************************************/


void Book::removeChapter ( Chapter const & _chapter )
{
	auto itByTitle = m_chaptersByTitle.find( _chapter.getTitle() );
	if ( itByTitle == m_chaptersByTitle.end() )
		throw std::logic_error( "Chapter does not exists in book" );

	m_chaptersByTitle.erase( itByTitle );

	int nChapters = getChaptersCount();
	for ( int i = 0; i < nChapters; i++ )
		if ( m_chapters[ i ].get() == &_chapter )
		{
			m_chaptersByTitle.erase( _chapter.getTitle() );
			return;
		}
}


/*****************************************************************************/


void Book::clearChapters ()
{
	m_chaptersByTitle.clear();
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


bool Book::hasAuthor ( Author const & _author ) const
{
	return m_authors.find( & _author ) != m_authors.end();
}


/*****************************************************************************/


void Book::addAuthor ( Author const & _author )
{
	if ( hasAuthor( _author ) )
		throw std::logic_error( "Duplicate author" );

	m_authors.insert( & _author );
}


/*****************************************************************************/


void Book::removeAuthor ( Author const & _author )
{
	auto it = m_authors.find( & _author );
	if ( it == m_authors.end() )
		throw std::logic_error( "No such author" );

	m_authors.erase( it );
}


/*****************************************************************************/


void Book::clearAuthors ()
{
	m_authors.clear();
}


/*****************************************************************************/


void Book::forEachAuthor ( std::function< void ( Author const & ) > _action ) const
{
	for ( Author const * pAuthor : m_authors )
		_action( * pAuthor );
}


/*****************************************************************************/
