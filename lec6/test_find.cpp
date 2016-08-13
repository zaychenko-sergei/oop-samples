
#include "list.hpp"
#include <cassert>
#include <iostream>

template< typename T >
const T * MyFind ( const T * _pArray, int _nElements, const T & _value )
{
	for ( int i = 0; i < _nElements; i++ )
		if ( _pArray[ i ] == _value )
			return _pArray + i;

	return nullptr;
}

template< typename T >
typename List< T >::Iterator
MyFind ( const List< T > & _list, const T & _value )
{
	List< T >::Iterator it = _list.begin();
	while ( it != _list.end() )
	{
		if ( * it == _value )
			return it;
		++it;
	}

	return _list.end();
}


template< typename It, typename T >
It MyFind ( It _first, It _last, const T & _value )
{
	It current = _first;
	while ( current != _last )
	{
		if ( *current == _value )
			return current;
		++current;
	}

	return _last;
}



template< typename T >
class istream_iterator
{

public:

	istream_iterator ( std::istream & _stream )
		: m_pStream( &_stream ), m_currentValue( T() )
	{
		update();
	}

	istream_iterator ()
		: m_pStream( nullptr )
	{
	}

	bool operator == ( const istream_iterator & _it ) const
	{
		return m_pStream == _it.m_pStream;
	}

	bool operator != ( const istream_iterator & _it ) const
	{
		return !( *this == _it );
	}

	istream_iterator& operator ++ ()
	{
		update();
		return *this;
	}

	const T & operator * () const
	{
		return m_currentValue;
	}

private:

	void update ()
	{
		( *m_pStream ) >> m_currentValue;
	}

	std::istream * m_pStream;
	T m_currentValue;
};



int main ()
{
	int data[ 5 ] = { 1, 2, 3, 4, 5 };
	const int * pResult = MyFind( data, data + 5, 3 );
	assert( pResult && ( * pResult == 3 ) );

	List < int > myList{ 1, 2, 3, 4, 5 };
	const List< int >::Iterator it = MyFind( myList.begin(), myList.end(), 3 );
	assert( ( it != myList.end() ) && ( *it == 3 ) );

	istream_iterator< int > result =
		MyFind(
			istream_iterator< int >( std::cin ),
			istream_iterator< int >(),
			3
		);
	assert( *result == 3 );
}
