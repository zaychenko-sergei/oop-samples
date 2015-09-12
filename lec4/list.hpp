// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _LIST_HPP_
#define _LIST_HPP_

/*****************************************************************************/

#include <initializer_list>

/*****************************************************************************/


class List
{

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	class Node;

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	class Iterator
	{

	/*-------------------------------------------------------------*/

	public:

	/*-------------------------------------------------------------*/

		explicit Iterator ( Node * _pNode = nullptr );

		int operator * () const;
		int & operator * ();

		bool operator == ( Iterator i ) const;
		bool operator != ( Iterator i ) const;

		Iterator & operator ++ ();
		Iterator operator ++ ( int );

	/*-------------------------------------------------------------*/

	private:

	/*-------------------------------------------------------------*/

		friend class List;

		void validate () const;

	/*-------------------------------------------------------------*/

		Node * m_pCurrent;

	/*-------------------------------------------------------------*/

	};


/*-----------------------------------------------------------------*/

	List ();

	List ( std::initializer_list< int > _l );

	List ( const List & _l );

	List ( List && _l );

	~List ();

	List & operator = ( const List & _l );

	List & operator = ( List && _l );

/*-----------------------------------------------------------------*/

	Iterator begin () const;

	Iterator end () const;

/*-----------------------------------------------------------------*/

	bool IsEmpty () const;

	int Size () const;

	void Clear ();

	void PushBack ( int _value );

	void PushFront ( int _value );

	void PopBack ();

	void PopFront ();

	void InsertAfter ( Iterator _prevPos, int _value );

	void InsertBefore ( Iterator _nextPos, int _value );

	void Delete ( Iterator _pos );

	void DeleteBefore ( Iterator _nextPos );

	void DeleteAfter ( Iterator _prevPos );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	void CopyDataFrom ( const List & _l );

	bool Owns ( Iterator _pos ) const;

/*-----------------------------------------------------------------*/

	Node * m_pFirst;

	Node * m_pLast;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline bool List::IsEmpty () const
{
	return m_pFirst == nullptr;
}


/*****************************************************************************/


inline List::Iterator List::begin () const
{
	return Iterator( m_pFirst );
}


/*****************************************************************************/


inline List::Iterator List::end () const
{
	return Iterator();
}


/*****************************************************************************/

#endif // _LIST_HPP