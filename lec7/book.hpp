// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _BOOK_HPP_
#define _BOOK_HPP_

/*****************************************************************************/

#include <string>
#include <vector>
#include <initializer_list>

/*****************************************************************************/

class Chapter;

/*****************************************************************************/


class Book
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Book ( std::string const & _title );

	Book ( std::string const & _title, std::initializer_list< Chapter * > _chapters );

	~Book ();

	Book ( const Book & ) = delete;
	Book & operator = ( const Book & ) = delete;

	std::string const & getTitle () const;

	int getChaptersCount () const;

	Chapter & getChapter ( int _index ) const;

	int findChapterIndex ( Chapter const & _chapter ) const;

	bool hasChapter ( Chapter const & _chapter ) const;

	void addChapter ( Chapter * _pChapter );

	void insertChapter ( int _atIndex, Chapter * _pChapter );

	void removeChapter ( int _atIndex );

	void removeChapter ( Chapter const & _chapter );

	void clearChapters ();

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::vector< Chapter * > m_chapters;

	const std::string m_title;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline std::string const & 
Book::getTitle () const
{
	return m_title;
}


/*****************************************************************************/


inline int
Book::getChaptersCount () const
{
	return m_chapters.size();
}


/*****************************************************************************/


inline Chapter & 
Book::getChapter ( int _index ) const
{
	return * m_chapters.at( _index );
}


/*****************************************************************************/

#endif // _BOOK_HPP_