// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _INITIALIZER_LIST_HPP_
#define _INITIALIZER_LIST_HPP_

/*****************************************************************************/


template< typename T >
class InitializerList
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	InitializerList ();

	InitializerList ( const T * _pBegin, const T * _pEnd );

/*-----------------------------------------------------------------*/

	const T * begin () const;

	const T * end () const;
	
	size_t size () const;

/*-----------------------------------------------------------------*/

	typedef T value_type;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const T * m_pBegin;

	const T * m_pEnd;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


template< typename T >
InitializerList< T >::InitializerList ()
	:	m_pBegin( nullptr )
	,	m_pEnd( nullptr )
{}


/*****************************************************************************/


template< typename T >
InitializerList< T >::InitializerList ( const T * _pBegin, const T * _pEnd )
	:	m_pBegin( _pBegin )
	,	m_pEnd( _pEnd )
{}


/*****************************************************************************/


template< typename T >
const T * InitializerList< T >::begin () const
{
	return m_pBegin;
}


/*****************************************************************************/


template< typename T >
const T * InitializerList< T >::end () const
{
	return m_pEnd;
}


/*****************************************************************************/


template< typename T >
size_t InitializerList< T >::size () const
{
	return m_pEnd - m_pBegin;
}


/*****************************************************************************/

#endif // _INITIALIZER_LIST_HPP_

