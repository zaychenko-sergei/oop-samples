
#ifndef _BOOK_BAD_HPP_
#define _BOOK_BAD_HPP_

/*****************************************************************************/

#include "chapter.hpp"
#include <vector>

/*****************************************************************************/

class Book
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

    Book ( std::string _title, std::vector< Chapter * > _chapters )
        :    m_title( _title ), m_chapters( _chapters )
    {}

    Book ( const Book & ) = delete;
    Book & operator = ( const Book & ) = delete;

    ~ Book ()
    {
        for ( Chapter * pChapter : m_chapters )
            delete pChapter;
    }

    std::string getTitle () const { return m_title; }

    std::vector< Chapter * > getChapters () const { return m_chapters; }

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

    std::vector< Chapter * > m_chapters;

    std::string m_title;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/

#endif // _BOOK_BAD_HPP_