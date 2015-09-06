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
