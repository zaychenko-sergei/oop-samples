// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _BOOK_V3_HPP_
#define _BOOK_V3_HPP_

/*****************************************************************************/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <functional>

/*****************************************************************************/

class Chapter;
class Author;

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

	/////

	int getAuthorsCount () const;

	bool hasAuthor ( Author const & _author ) const;

	void addAuthor ( Author const & _author );

	void removeAuthor ( Author const & _author );

	void clearAuthors ();

	void forEachAuthor ( std::function< void ( Author const & ) > _action ) const;

	/////

	int getChaptersCount () const;

	bool hasChapter ( Chapter const & _chapter ) const;

	Chapter const * findChapterByTitle ( std::string const & _title ) const;

	void addChapter ( std::unique_ptr< Chapter > _chapter );

	void removeChapter ( Chapter const & _chapter );

	void clearChapters ();

	void forEachChapter ( std::function< void ( Chapter const & ) > _action ) const;

	const Chapter * findChapter ( std::function< bool ( Chapter const & ) > _filter ) const;

	int countChaptersWith ( std::function< bool ( Chapter const & ) > _filter ) const;

	bool allOf ( std::function< bool ( Chapter const & ) > _filter ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::vector< std::unique_ptr< Chapter > > m_chapters;

	std::unordered_map< std::string, Chapter const * > m_chaptersByTitle;

	std::unordered_set< Author const * > m_authors;

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

inline int 
Book::getAuthorsCount () const
{
	return m_authors.size();
}

/*****************************************************************************/


#endif // _BOOK_V3_HPP_