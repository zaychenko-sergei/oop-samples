// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "stack.hpp"

#include <stdexcept>

/*****************************************************************************/


Stack::Stack ( int _size )
{
	if ( _size <= 0 )
		throw std::logic_error( "Stack size must be positive" );

	m_size = _size;
	m_pDataStart = new int[ m_size ];
	m_pDataTop = m_pDataStart;
}


/*****************************************************************************/


Stack::Stack ( std::initializer_list< int > _l )
	:	Stack( _l.size() )
{
	for ( int x : _l )
		*( m_pDataTop++ ) = x;
}


/*****************************************************************************/


Stack::Stack ( const Stack & _s )
{
	CopyDataFrom( _s );
}


/*****************************************************************************/


Stack::Stack ( Stack && _s )
	:	m_size( _s.m_size ),
		m_pDataStart( _s.m_pDataStart ),
		m_pDataTop( _s.m_pDataTop )
{
	_s.m_pDataStart = _s.m_pDataTop = nullptr;
}


/*****************************************************************************/


Stack & Stack::operator= ( const Stack & _s )
{
	if ( this == &_s )
		return *this;

	delete[] m_pDataStart;
	CopyDataFrom( _s );
	return *this;
}


/*****************************************************************************/


Stack & Stack::operator = ( Stack && _s )
{
	if ( &_s == this )
		return *this;

	std::swap( m_size, _s.m_size );
	std::swap( m_pDataStart, _s.m_pDataStart );
	std::swap( m_pDataTop, _s.m_pDataTop );

	return *this;
}


/*****************************************************************************/


void Stack::CopyDataFrom ( const Stack & _s )
{
	m_size = _s.m_size;
	m_pDataStart = new int[ m_size ];

	int nActuallyStored = _s.m_pDataTop - _s.m_pDataStart;
	m_pDataTop = m_pDataStart + nActuallyStored;
	memcpy( m_pDataStart, _s.m_pDataStart, nActuallyStored * sizeof( int ) );
}


/*****************************************************************************/


Stack::~Stack ()
{
	delete[] m_pDataStart;
}


/*****************************************************************************/


void Stack::Push ( int _value )
{
	if ( IsFull() )
		throw std::logic_error( "Stack overflow" );

	* ( m_pDataTop++ ) = _value;
}


/*****************************************************************************/


void Stack::Pop ()
{
	if ( IsEmpty() )
		throw std::logic_error( "Stack is empty" );

	-- m_pDataTop;
}


/*****************************************************************************/


int Stack::Top () const
{
	if ( IsEmpty() )
		throw std::logic_error( "Stack is empty" );

	return *( m_pDataTop - 1);
}


/*****************************************************************************/


bool Stack::operator == ( const Stack & s ) const
{
	int nActual1 = m_pDataTop - m_pDataStart;
	int nActual2 = s.m_pDataTop - s.m_pDataStart;
	if ( nActual1 != nActual2 )
		return false;

	return ! memcmp( m_pDataStart, s.m_pDataStart, nActual1 * sizeof ( int ) );
}


/*****************************************************************************/


bool Stack::operator != ( const Stack & s ) const
{
	return !( *this == s );
}


/*****************************************************************************/


std::ostream & operator << ( std::ostream & _o, const Stack & _s )
{
	int nActual = _s.m_pDataTop - _s.m_pDataStart;
	for ( int i = 0; i < nActual; i++ )
		_o << _s.m_pDataStart[ i ] << ' ';
	return _o;
}


/*****************************************************************************/
