// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _TEMPERATURE_HPP_
#define _TEMPERATURE_HPP_

/*****************************************************************************/

namespace temperature
{

/*****************************************************************************/


const long double ABSOLUTE_ZERO_CELCIUS = -273.15;


/*****************************************************************************/


class Temperature
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	long double asCelcius () const { return m_celcius; }
	long double asKelvin () const { return m_celcius - ABSOLUTE_ZERO_CELCIUS; }
	long double asFahrenheit () const { return m_celcius * 9.0 / 5.0 + 32.0; }

	bool operator == ( Temperature t ) const { return m_celcius == t.m_celcius; }
	bool operator != ( Temperature t ) const { return m_celcius != t.m_celcius; }
	bool operator <  ( Temperature t ) const { return m_celcius  < t.m_celcius; }
	bool operator <= ( Temperature t ) const { return m_celcius <= t.m_celcius; }
	bool operator >  ( Temperature t ) const { return m_celcius  > t.m_celcius; }
	bool operator >= ( Temperature t ) const { return m_celcius >= t.m_celcius; }

	Temperature operator + ( Temperature t ) const;
	Temperature & operator += ( Temperature t );

	Temperature operator - ( Temperature t ) const;
	Temperature & operator -= ( Temperature t );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Temperature ( long double _celcius );

	friend Temperature operator "" _C ( long double );
	friend Temperature operator "" _K ( long double );
	friend Temperature operator "" _F ( long double );

/*-----------------------------------------------------------------*/

	long double m_celcius;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

} // namespace temperature

/*****************************************************************************/

#endif // _TEMPERATURE_HPP_