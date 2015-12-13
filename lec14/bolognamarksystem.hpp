// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _BOLOGNAMARKSYSTEM_HPP_
#define _BOLOGNAMARKSYSTEM_HPP_

/*****************************************************************************/

#include "marksystem.hpp"

/*****************************************************************************/


class BolognaMarkSystem
    :    public MarkSystem
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

    bool isValidMark ( int _mark ) const override
    {
        return _mark >= 1 && _mark <= 100;
    }


    MarkConclusion analyzeMark ( int _mark ) const override
    {
        if ( ! isValidMark( _mark ) )
            return MarkConclusion::InvalidMark;

        if ( _mark < 60 )
            return MarkConclusion::Fail;

        else if ( _mark >= 60 && _mark <= 74 )
            return MarkConclusion::Pass_WithoutScolarship;

        else
            return MarkConclusion::Pass_WithScolarship;
    }

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif //  _BOLOGNAMARKSYSTEM_HPP_
