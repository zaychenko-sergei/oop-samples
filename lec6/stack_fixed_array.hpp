// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _STACK_FIXED_ARRAY_HPP_
#define _STACK_FIXED_ARRAY_HPP_

#include <stdexcept>
#include <initializer_list>

/*****************************************************************************/


template< typename T, int SIZE = 10 >
class Stack
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	template< typename, int > friend class Stack;

/*-----------------------------------------------------------------*/

	Stack ();

	template< typename U >
	Stack ( std::initializer_list< U > _l );
	
	template< typename U, int OTHER_SIZE >
	Stack ( const Stack< U, OTHER_SIZE > & _s );

	template< typename U, int OTHER_SIZE >
	Stack< T, SIZE > & operator = ( const Stack< U, OTHER_SIZE > & _s );

	void push ( const T & _value );

	void pop ();

	T & top () const;

	bool isEmpty () const;

	bool isFull () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	T m_Data[ SIZE ];

	T * m_pTop;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


template< typename T, int SIZE >
Stack< T, SIZE >::Stack ()
{
	m_pTop = m_Data;
}


/*****************************************************************************/


template< typename T, int SIZE >
	template< typename U >
Stack< T, SIZE >::Stack ( std::initializer_list< U > _l )
{
	m_pTop = m_Data;

	for ( const U & x : _l )
		push( static_cast< const T & >( x ) );
}


/*****************************************************************************/


template< typename T, int SIZE >
	template< typename U, int OTHER_SIZE >
Stack< T, SIZE >::Stack ( const Stack< U, OTHER_SIZE > & _s )
{
	m_pTop = m_Data;

	int nActual = _s.m_pTop - _s.m_Data;
	for ( int i = 0; i < nActual; i++ )
		push( static_cast< T >( _s.m_Data[ i ] ) );
}


/*****************************************************************************/


template< typename T, int SIZE >
	template< typename U, int OTHER_SIZE >
Stack< T, SIZE > & 
Stack< T, SIZE >::operator = ( const Stack< U, OTHER_SIZE > & _s )
{
	if ( static_cast< const void * >( this ) == static_cast< const void * >( &_s ) )
		return *this;

	m_pTop = m_Data;

	int nActual = _s.m_pTop - _s.m_Data;
	for ( int i = 0; i < nActual; i++ )
		push( _s.m_Data[ i ] );

	return * this;
}


/*****************************************************************************/


template< typename T, int SIZE >
void Stack< T, SIZE >::push ( const T & _value )
{
	if ( isFull() )
		throw std::logic_error( "Stack overflow error" );

	* m_pTop++ = _value;
}


/*****************************************************************************/


template< typename T, int SIZE >
void Stack< T, SIZE >::pop ()
{
	if ( isEmpty() )
		throw std::logic_error( "Stack underflow error" );

	m_pTop--;
}


/*****************************************************************************/


template< typename T, int SIZE >
T & Stack< T, SIZE >::top () const
{
	if ( isEmpty() )
		throw std::logic_error( "Stack is empty" );

	return *( m_pTop - 1 );
}


/*****************************************************************************/


template< typename T, int SIZE >
bool Stack< T, SIZE >::isEmpty () const
{
	return m_pTop == m_Data;
}


/*****************************************************************************/


template< typename T, int SIZE >
bool Stack< T, SIZE >::isFull () const
{
	return ( m_pTop - m_Data ) == SIZE;
}


/*****************************************************************************/

#endif // _STACK_FIXED_ARRAY_HPP_

