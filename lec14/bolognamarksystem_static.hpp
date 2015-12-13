// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _BOLOGNAMARKSYSTEM_STATIC_HPP_
#define _BOLOGNAMARKSYSTEM_STATIC_HPP_

/*****************************************************************************/

#include "markconclusion.hpp"

/*****************************************************************************/


class BolognaMarkSystem
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/


	static bool isValidMark ( int _mark )
	{
		return _mark >= 1 && _mark <= 100;
	}


	static MarkConclusion analyzeMark ( int _mark )
	{
		if ( !isValidMark( _mark ) )
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

#endif //  _BOLOGNAMARKSYSTEM_STATIC_HPP_

