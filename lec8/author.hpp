// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _AUTHOR_HPP_
#define _AUTHOR_HPP_

/*****************************************************************************/

#include <unordered_set>
#include <memory>
#include <functional>
#include <string>

/*****************************************************************************/

class Book;

/*****************************************************************************/


class Author
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Author ( std::string const & _name, int _birthYear );

	std::string const & getName () const;

	int getBirthYear () const;

/*-----------------------------------------------------------------*/

	int getBooksCount () const;

	bool hasBook ( Book const & _book ) const;

	void addBook ( Book const & _book );

	void removeBook ( Book const & _book );

	void clearBooks ();

	void forEachBook ( std::function< void ( Book const & ) > _action ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const std::string m_name;

	const int m_birthYear;

	std::unordered_set< Book const * > m_books;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

inline std::string const &
Author::getName () const
{
	return m_name;
}

/*****************************************************************************/

inline int
Author::getBirthYear () const
{
	return m_birthYear;
}

/*****************************************************************************/

inline int
Author::getBooksCount () const
{
	return m_books.size();
}

/*****************************************************************************/

#endif // _AUTHOR_HPP_


