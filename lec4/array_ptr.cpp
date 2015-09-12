// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "array_ptr.hpp"

#include <cassert>
#include <stdexcept>

/*****************************************************************************/


ArrayPtr::ArrayPtr ( int * _data, int _length )
	:    m_pData( _data ),
         m_length( _length ),
         m_currentPosition( 0 )
{
	if ( _length <= 0 )
		throw std::logic_error( "Error: expecting a positive length!" );
}


/*****************************************************************************/


int ArrayPtr::operator * () const
{
	assert( isValid() );
	return m_pData[ m_currentPosition ];
}


/*****************************************************************************/


int & ArrayPtr::operator * ()
{
	assert( isValid() );
	return m_pData[ m_currentPosition ];
}


/*****************************************************************************/


int ArrayPtr::operator [] ( int _index ) const
{
	assert( isValid() );
	assert( ( m_currentPosition + _index ) < m_length );
	return m_pData[ m_currentPosition + _index ];
}


/*****************************************************************************/


int & ArrayPtr::operator [] ( int _index )
{
	assert( isValid() );
	assert( ( m_currentPosition + _index ) < m_length );
	return m_pData[ m_currentPosition + _index ];
}


/*****************************************************************************/


bool ArrayPtr::operator == ( ArrayPtr _ptr ) const
{
	return m_currentPosition == _ptr.m_currentPosition && sameArray( _ptr );
}


/*****************************************************************************/


bool ArrayPtr::operator != ( ArrayPtr _ptr ) const
{
	return !( *this == _ptr );
}


/*****************************************************************************/


ArrayPtr & ArrayPtr::operator ++ ()
{
	assert( isValid() );
	++m_currentPosition;
	return *this;
}


/*****************************************************************************/


ArrayPtr ArrayPtr::operator ++ ( int )
{
	assert( isValid() );
	ArrayPtr copy( *this );
	++m_currentPosition;
	return copy;
}


/*****************************************************************************/


ArrayPtr & ArrayPtr::operator -- ()
{
	assert( isValid() );
	--m_currentPosition;
	return *this;
}


/*****************************************************************************/


ArrayPtr ArrayPtr::operator -- ( int )
{
	assert( isValid() );
	ArrayPtr copy( *this );
	--m_currentPosition;
	return copy;
}


/*****************************************************************************/


ArrayPtr & ArrayPtr::operator += ( int _numPositions )
{
	assert( isValid() );
	assert( ( m_currentPosition + _numPositions ) <= m_length );
	m_currentPosition += _numPositions;
	return *this;
}


/*****************************************************************************/


ArrayPtr ArrayPtr::operator + ( int _numPositions ) const
{
	return ArrayPtr( *this ) += _numPositions;
}


/*****************************************************************************/


ArrayPtr & ArrayPtr::operator -= ( int _numPositions )
{
	assert( isValid() );
	assert( ( m_currentPosition - _numPositions ) >= 0 );
	m_currentPosition -= _numPositions;
	return *this;
}


/*****************************************************************************/


ArrayPtr ArrayPtr::operator - ( int _numPositions ) const
{
	return ArrayPtr( *this ) -= _numPositions;
}


/*****************************************************************************/


int ArrayPtr::operator - ( ArrayPtr _ptr ) const
{
	assert( isValid() );
	assert( _ptr.isValid() );
	assert( sameArray( _ptr ) );
	return m_currentPosition - _ptr.m_currentPosition;
}


/*****************************************************************************/


