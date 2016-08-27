// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "powereddevice.hpp"

#include <stdexcept>

/*****************************************************************************/


PoweredDevice::PoweredDevice ( int _nominalPower )
	:	m_nominalPower( _nominalPower )    
	,	m_turned( false )                   
{
}

/*****************************************************************************/


void PoweredDevice::turnOn ()
{
	if ( m_turned )
		throw std::logic_error( "Device is already turned on" );
	m_turned = true;
}


/*****************************************************************************/


void PoweredDevice::turnOff ()
{
	if ( ! m_turned )
		throw std::logic_error( "Device is not turned on" );
	m_turned = false;
}


/*****************************************************************************/

