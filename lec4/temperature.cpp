// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "temperature.hpp"

#include <stdexcept>

/*****************************************************************************/

namespace temperature
{

/*****************************************************************************/


Temperature::Temperature ( long double _celcius )
	:    m_celcius( _celcius )
{
	if ( m_celcius < ABSOLUTE_ZERO_CELCIUS )
		throw std::logic_error( "Temperature below absolute zero" );
}


/*****************************************************************************/


Temperature Temperature::operator + ( Temperature t ) const
{
	return Temperature( m_celcius + t.m_celcius );
}


/*****************************************************************************/


Temperature & Temperature::operator += ( Temperature t )
{
	* this = * this + t;
	return * this;
}


/*****************************************************************************/


Temperature Temperature::operator - ( Temperature t ) const
{
	return Temperature( m_celcius - t.m_celcius );
}


/*****************************************************************************/


Temperature & Temperature::operator -= ( Temperature t )
{
	*this = *this - t;
	return *this;
}


/*****************************************************************************/


Temperature operator "" _C ( long double _celcius )
{
	return Temperature( _celcius );
}


/*****************************************************************************/


Temperature operator "" _K ( long double _kelvin )
{
	return Temperature( _kelvin + ABSOLUTE_ZERO_CELCIUS );
}


/*****************************************************************************/


Temperature operator "" _F ( long double _fahr )
{
	return Temperature( ( _fahr - 32.0 ) * 5.0 / 9.0 );
}


/*****************************************************************************/

} // namespace temperature

/*****************************************************************************/
