// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "book.hpp"
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


int Book::findChapterIndex ( Chapter const & _chapter ) const
{
	int nChapters = getChaptersCount();
	for ( int i = 0; i < nChapters; i++ )
		if ( m_chapters[ i ] == &_chapter )
			return i;

	return -1;
}


/*****************************************************************************/


bool Book::hasChapter ( Chapter const & _chapter ) const
{
	return findChapterIndex( _chapter ) != -1;
}


/*****************************************************************************/


void Book::addChapter ( Chapter * _pChapter )
{
	m_chapters.push_back( _pChapter );
}


/*****************************************************************************/


void Book::insertChapter ( int _atIndex, Chapter * _pChapter )
{
	m_chapters.insert( m_chapters.begin() + _atIndex, _pChapter );
}


/*****************************************************************************/


void Book::removeChapter ( int _atIndex )
{
	delete m_chapters.at( _atIndex );
	m_chapters.erase( m_chapters.begin() + _atIndex );
}


/*****************************************************************************/


void Book::removeChapter ( Chapter const & _chapter )
{
	int index = findChapterIndex( _chapter );
	if ( index == -1 )
		throw std::logic_error( "Chapter does not exists in book" );

	removeChapter( index );
}


/*****************************************************************************/


void Book::clearChapters ()
{
	for ( Chapter * pChapter : m_chapters )
		delete pChapter;

	m_chapters.clear();
}


/*****************************************************************************/

