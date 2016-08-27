// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _CHAPTER_HPP_
#define _CHAPTER_HPP_

/*****************************************************************************/

#include <string>

/*****************************************************************************/


class Chapter
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Chapter ( std::string const & _title, int _nPages );
	
	std::string const & getTitle () const;

	int getPagesCount () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const std::string m_title;

	const int m_nPages;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

inline Chapter::Chapter ( std::string const & _title, int _nPages )
	: m_title( _title ), m_nPages( _nPages )
{
}


/*****************************************************************************/

inline std::string const & 
Chapter::getTitle () const
{ 
	return m_title; 
}

/*****************************************************************************/

inline int 
Chapter::getPagesCount () const 
{
	return m_nPages; 
}

/*****************************************************************************/

#endif // _CHAPTER_HPP_


