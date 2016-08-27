// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _SOVIETMARKSYSTEM_HPP_
#define _SOVIETMARKSYSTEM_HPP_

/*****************************************************************************/

#include "marksystem.hpp"

/*****************************************************************************/


class SovietMarkSystem
    :    public MarkSystem
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

    bool isValidMark ( int _mark ) const override
    {
        return _mark >= 1 && _mark <= 5;
    }

    MarkConclusion analyzeMark ( int _mark ) const override
    {
        if ( ! isValidMark( _mark ) )
            return MarkConclusion::InvalidMark;

        if ( _mark < 3 )
            return MarkConclusion::Fail;

        else if ( _mark == 3 )
            return MarkConclusion::Pass_WithoutScolarship;

        else
            return MarkConclusion::Pass_WithScolarship;
    }

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif // _SOVIETMARKSYSTEM_HPP_