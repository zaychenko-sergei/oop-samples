// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _BOOK_V2_HPP_
#define _BOOK_V2_HPP_

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

	bool hasChapter ( Chapter const & _chapter ) const;

	void addChapter ( Chapter * _pChapter );

	void removeChapter ( Chapter const & _chapter );

	void clearChapters ();

/*-----------------------------------------------------------------*/

	typedef std::vector< Chapter * >::const_iterator ChapterIterator;
	ChapterIterator chaptersBegin () const;
	ChapterIterator chaptersEnd () const;

/*-----------------------------------------------------------------*/

	class IterableChapters
	{

	/*-----------------------------------------------------------------*/

	public:

	/*-----------------------------------------------------------------*/

		IterableChapters ( ChapterIterator _chaptersBegin, ChapterIterator _chaptersEnd )
			: m_begin( _chaptersBegin ), m_end( _chaptersEnd )
		{}

		ChapterIterator begin () const { return m_begin; }
		ChapterIterator end () const { return m_end; }

	/*-----------------------------------------------------------------*/

	private:

	/*-----------------------------------------------------------------*/

		ChapterIterator m_begin, m_end;

	/*-----------------------------------------------------------------*/

	};


	IterableChapters chapters () const;

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


inline Book::ChapterIterator 
Book::chaptersBegin () const
{
	return m_chapters.begin();
}


/*****************************************************************************/

inline Book::ChapterIterator 
Book::chaptersEnd () const
{
	return m_chapters.end();
}


/*****************************************************************************/


inline Book::IterableChapters 
Book::chapters () const
{
	return IterableChapters( chaptersBegin(), chaptersEnd() );
}


/*****************************************************************************/

#endif // _BOOK_V2_HPP_