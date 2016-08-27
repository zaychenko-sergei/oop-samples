// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _MARKSYSTEM_HPP_
#define _MARKSYSTEM_HPP_

/*****************************************************************************/

#include "markconclusion.hpp"

/*****************************************************************************/


class MarkSystem
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

    virtual ~MarkSystem () = default;

    virtual bool isValidMark ( int _mark ) const = 0;

    virtual MarkConclusion analyzeMark ( int _mark ) const = 0;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif // _MARKSYSTEM_HPP_