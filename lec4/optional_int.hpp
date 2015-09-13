// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _OPTIONAL_INT_HPP_
#define _OPTIONAL_INT_HPP_

/*****************************************************************************/

#include <stdexcept>

/*****************************************************************************/


class OptionalInt
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	OptionalInt ();

	OptionalInt ( int _value );

	explicit operator bool () const;

	bool operator ! () const;

	int operator * () const;

	int & operator * ();

	void reset ();

	void reset ( int _value );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	int m_value;

	bool m_isSet;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline OptionalInt::OptionalInt ()
{
	reset();
}


/*****************************************************************************/


inline OptionalInt::OptionalInt ( int _value )
{
	reset( _value );
}


/*****************************************************************************/


inline OptionalInt::operator bool () const
{
	return m_isSet;
}


/*****************************************************************************/


inline bool OptionalInt::operator ! () const
{
	return ! m_isSet;
}


/*****************************************************************************/


inline int OptionalInt::operator * () const
{
	if ( ! m_isSet )
		throw std::logic_error( "Optional value not set" );

	return m_value;
}


/*****************************************************************************/


inline int & OptionalInt::operator * ()
{
	if ( ! m_isSet )
		throw std::logic_error( "Optional value not set" );

	return m_value;
}


/*****************************************************************************/


inline void OptionalInt::reset ()
{
	m_isSet = false;
}


/*****************************************************************************/


inline void OptionalInt::reset ( int _value )
{
	m_isSet = true;
	m_value = _value;
}


/*****************************************************************************/

#endif // _OPTIONAL_INT_HPP_