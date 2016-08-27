// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "managed_array.hpp"

#include <memory.h>

/*****************************************************************************/


ManagedArray::ManagedArray ( int _size )
	:	m_size( _size )
{
	if ( m_size <= 0 )
		throw NonPositiveArraySize( m_size );

	m_pData = new int[ m_size ];
	memset( m_pData, 0, sizeof( int ) * m_size );
}


/*****************************************************************************/


ManagedArray::~ManagedArray ()
{
	delete[] m_pData;
}


/*****************************************************************************/


int & ManagedArray::operator[] ( int _index )
{
	if ( _index < 0 || _index >= m_size )
		throw IndexOutOfRange( _index, 0, m_size - 1 );

	return m_pData[ _index ];
}


/*****************************************************************************/


int ManagedArray::operator[] ( int _index ) const
{
	if ( _index < 0 || _index >= m_size )
		throw IndexOutOfRange( _index, 0, m_size - 1 );

	return m_pData[ _index ];
}


/*****************************************************************************/
