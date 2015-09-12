// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _STACK_HPP_
#define _STACK_HPP_

/*****************************************************************************/

#include <initializer_list>
#include <iostream>

/*****************************************************************************/

class Stack
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Stack ( int _size = 10 );
	Stack ( std::initializer_list< int > _l );
	Stack ( const Stack & _s );
	Stack ( Stack && _s );
	~ Stack ();

	Stack & operator = ( const Stack & _s );
	Stack & operator = ( Stack && _s );

	bool IsEmpty () const;
	bool IsFull () const;
	void Push ( int _value );
	void Pop ();
	int Top () const;

	bool operator == ( const Stack & s ) const;
	bool operator != ( const Stack & d ) const;

/*-----------------------------------------------------------------*/

	friend std::ostream & operator << ( std::ostream & _o, const Stack & _s );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	void CopyDataFrom ( const Stack & _s );

/*-----------------------------------------------------------------*/

	int * m_pDataStart;
	int * m_pDataTop;
	int m_size;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline bool Stack::IsEmpty () const
{
	return m_pDataStart == m_pDataTop;
}


/*****************************************************************************/


inline bool Stack::IsFull () const
{
	return ( m_pDataTop - m_pDataStart ) == m_size;
}


/*****************************************************************************/

#endif // _STACK_HPP_
