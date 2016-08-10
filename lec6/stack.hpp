// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <stdexcept>
#include <initializer_list>

/*****************************************************************************/


template< typename T >
class Stack
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Stack ( int _size = 10 );

	Stack ( std::initializer_list< T > _l );
	
	Stack ( const Stack< T > & _s );

	Stack ( Stack< T > && _s );

	~ Stack ();

	Stack< T > & operator = ( const Stack< T > & _s );

	Stack< T > & operator = ( Stack< T > && _s );

	void push ( const T & _value );

	void pop ();

	T & top () const;

	bool isEmpty () const;

	bool isFull () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	int m_size;

	T * m_pData;

	T * m_pTop;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


template< typename T >
Stack< T >::Stack ( int _size )
	:	m_size( _size )
{
	if ( m_size <= 0 )
		throw std::logic_error( "Non-positive size" );

	m_pData = new T[ m_size ];
	m_pTop = m_pData;
}


/*****************************************************************************/


template< typename T >
Stack< T >::Stack ( std::initializer_list< T > _l )
	:	Stack( _l.size() )
{
	for ( const T & x : _l )
		push( x );
}


/*****************************************************************************/


template< typename T >
Stack< T >::Stack ( const Stack< T >& _s )
	:	m_size( _s.m_size )
{
	m_pData = new T[ m_size ];
	m_pTop = m_pData;

	int nActual = _s.m_pTop - _s.m_pData;
	for ( int i = 0; i < nActual; i++ )
		push( _s.m_pData[ i ] );
}


/*****************************************************************************/


template< typename T >
Stack< T >::Stack ( Stack< T > && _s )
	:	m_size( _s.m_size ),
		m_pData( _s.m_pData ),
		m_pTop( _s.m_pTop )
{
	_s.m_pData = _s.m_pTop = nullptr;
}


/*****************************************************************************/


template< typename T >
Stack< T >::~Stack ()
{
	delete[] m_pData;
}


/*****************************************************************************/


template< typename T >
Stack< T > & 
Stack< T >::operator = ( const Stack< T > & _s )
{
	if ( this == &_s )
		return *this;

	delete[] m_pData;
	m_size = _s.m_size;
	m_pData = new T[ m_size ];

	int nActual = _s.m_pTop - _s.m_pData;
	for ( int i = 0; i < nActual; i++ )
		m_pData[ i ] = _s.m_pData[ i ];

	m_pTop = m_pData + nActual;

	return * this;
}


/*****************************************************************************/


template< typename T >
Stack< T > & 
Stack< T >::operator = ( Stack< T > && _s )
{
	if ( this == &_s )
		return *this;

	delete[] m_pData;

	m_size  = _s.m_size;
	m_pData = _s.m_pData;
	m_pTop  = _s.m_pTop;

	_s.m_pData = _s.m_pTop = nullptr;

	return * this;
}


/*****************************************************************************/


template< typename T>
void Stack< T >::push ( const T& _value )
{
	if ( isFull() )
		throw std::logic_error( "Stack overflow error" );

	* m_pTop++ = _value;
}

/*****************************************************************************/


template< typename T >
void Stack< T >::pop ()
{
	if ( isEmpty() )
		throw std::logic_error( "Stack underflow error" );

	m_pTop--;
}


/*****************************************************************************/


template< typename T >
T& Stack< T >::top () const
{
	if ( isEmpty() )
		throw std::logic_error( "Stack is empty" );

	return *( m_pTop - 1 );
}


/*****************************************************************************/


template< typename T >
bool Stack< T >::isEmpty () const
{
	return m_pTop == m_pData;
}


/*****************************************************************************/


template< typename T >
bool Stack< T >::isFull () const
{
	return ( m_pTop - m_pData ) == m_size;
}


/*****************************************************************************/

#endif // _STACK_HPP_

