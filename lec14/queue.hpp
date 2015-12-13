// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

/*****************************************************************************/

#include <stdexcept>
#include <list>
#include <deque>

/*****************************************************************************/


template< typename T >
using List = std::list< T >;


template< typename T >
using Deque = std::deque< T >;


/*****************************************************************************/


template <
		typename T
	,	template < typename > class CONT = List
>
class Queue
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	void push ( T const &  _v );

	void pop ();

	T const & top () const;

	bool empty () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	CONT< T > m_elements;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


template <
		typename T
	,	template < typename > class CONT
>
void
Queue< T, CONT >::push ( T const &  _v )
{
	m_elements.push_back( _v );
}


/*****************************************************************************/


template <
		typename T
	,	template < typename > class CONT
>
void
Queue< T, CONT >::pop ()
{
	if ( empty() )
		throw std::logic_error( "Queue is empty" );

	m_elements.pop_front();
}


/*****************************************************************************/


template <
		typename T
	,	template < typename > class CONT
>
T const &
Queue< T, CONT >::top () const
{
	if ( empty() )
		throw std::logic_error( "Queue is empty" );

	return m_elements.front();
}


/*****************************************************************************/


template <
		typename T
	,	template < typename > class CONT
>
bool 
Queue< T, CONT >::empty () const
{
	return m_elements.empty();
}


/*****************************************************************************/

#endif // _QUEUE_HPP_

