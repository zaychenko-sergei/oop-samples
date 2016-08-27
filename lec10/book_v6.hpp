// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _BOOK_V6_HPP_
#define _BOOK_V6_HPP_

/*****************************************************************************/

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <functional>

/*****************************************************************************/

class Chapter;

/*****************************************************************************/


class Book
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Book ( std::string const & _title );

	Book ( 
			std::string const & _title
		,	std::initializer_list< Chapter * > _chapters 
	);

	std::string const & getTitle () const;

	int getChaptersCount () const;

	bool hasChapter ( Chapter const & _chapter ) const;

	Chapter const * findChapterByTitle ( std::string const & _title ) const;

	void addChapter ( std::unique_ptr< Chapter > _chapter );

	void removeChapter ( Chapter const & _chapter );

	void clearChapters ();

	void forEachChapter ( std::function< void ( Chapter const & ) > _action ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::vector< std::unique_ptr< Chapter > > m_chapters;

	std::unordered_map< std::string, Chapter const * > m_chaptersByTitle;

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

#endif // _BOOK_V6_HPP_