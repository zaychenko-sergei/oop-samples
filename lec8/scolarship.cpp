// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "scolarship.hpp"

/*****************************************************************************/


Scolarship::Scolarship ( double _amount, bool _personal )
	:	m_amount( _amount ), m_personal( _personal )
{
	if ( m_amount <= 0.0 )
		throw std::logic_error( "Non-positive amount" );
}


/*****************************************************************************/
