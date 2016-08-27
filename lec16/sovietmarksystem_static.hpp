// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _SOVIETMARKSYSTEM_STATIC_HPP_
#define _SOVIETMARKSYSTEM_STATIC_HPP_

/*****************************************************************************/

#include "markconclusion.hpp"

/*****************************************************************************/


class SovietMarkSystem
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/


    static bool isValidMark ( int _mark )
    {
        return _mark >= 1 && _mark <= 5;
    }


    static MarkConclusion analyzeMark ( int _mark )
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

#endif //  _SOVIETMARKSYSTEM_STATIC_HPP_
