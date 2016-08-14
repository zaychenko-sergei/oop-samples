// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "book_v2.hpp"
#include "chapter.hpp"

/*****************************************************************************/


Book::Book ( std::string const & _title )
	: m_title( _title )
{}


/*****************************************************************************/


Book::Book ( std::string const & _title, std::initializer_list< Chapter * > _chapters )
	: m_title( _title ), m_chapters( _chapters )
{}


/*****************************************************************************/


Book::~Book ()
{
	clearChapters();
}


/*****************************************************************************/


bool Book::hasChapter ( Chapter const & _chapter ) const
{
	int nChapters = getChaptersCount();
	for ( int i = 0; i < nChapters; i++ )
		if ( m_chapters[ i ] == &_chapter )
			return true;

	return false;
}


/*****************************************************************************/


void Book::addChapter ( Chapter * _pChapter )
{
	m_chapters.push_back( _pChapter );
}


/*****************************************************************************/


void Book::removeChapter ( Chapter const & _chapter )
{
    int chapterIndex = -1;
	
	int nChapters = getChaptersCount();
	for ( int i = 0; i < nChapters; i++ )
		if ( m_chapters[ i ] == & _chapter )
		{
		    chapterIndex = i;
			break;
		}

	if ( chapterIndex == -1 )
		throw std::logic_error( "Chapter does not exists in book" );

	delete m_chapters.at( chapterIndex );
	m_chapters.erase( m_chapters.begin() + chapterIndex );
}


/*****************************************************************************/


void Book::clearChapters ()
{
	for ( Chapter * pChapter : m_chapters )
		delete pChapter;

	m_chapters.clear();
}


/*****************************************************************************/

