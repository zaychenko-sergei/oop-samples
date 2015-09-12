// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ARRAY_PTR_HPP_
#define _ARRAY_PTR_HPP_

/*****************************************************************************/


class ArrayPtr
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	ArrayPtr ( int * _data, int _length );

	int operator * () const;
	int & operator * ();

	int operator [] ( int _index ) const;
	int & operator [] ( int _index );

	bool operator == ( ArrayPtr _ptr ) const;
	bool operator != ( ArrayPtr _ptr ) const;

	ArrayPtr & operator ++ ();
	ArrayPtr operator ++ ( int );
	ArrayPtr & operator -- ();
	ArrayPtr operator -- ( int );

	ArrayPtr & operator += ( int _numPosptrions );
	ArrayPtr operator + ( int _numPosptrions ) const;

	ArrayPtr & operator -= ( int _numPositions );
	ArrayPtr operator - ( int _numPositions ) const;

	int operator - ( ArrayPtr _ptr ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	bool isValid () const;

	bool sameArray ( ArrayPtr _ptr ) const;

/*-----------------------------------------------------------------*/

	int * const m_pData;

	const int m_length;

	int m_currentPosition;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline bool ArrayPtr::isValid () const
{
	return m_currentPosition >= 0 && m_currentPosition < m_length;
}


/*****************************************************************************/


inline bool ArrayPtr::sameArray ( ArrayPtr _ptr ) const
{
	return m_pData == _ptr.m_pData && m_length == _ptr.m_length;
}


/*****************************************************************************/

#endif // _ARRAY_PTR_HPP_