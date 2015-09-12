// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _LIST_HPP_
#define _LIST_HPP_

/*****************************************************************************/

#include <initializer_list>

/*****************************************************************************/


class List
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	class Node
	{

	/*-------------------------------------------------------------*/

	public:

	/*-------------------------------------------------------------*/

		Node ( int _value )
			: m_value( _value )
			, m_pNext( nullptr )
		{}

		int GetValue () const { return m_value;  }

		int & GetValue () { return m_value; }

		Node const * GetNext () const { return m_pNext; }

		Node * GetNext () { return m_pNext; }

		void SetNext ( Node * _pNext ) { m_pNext = _pNext; }

		void ClearNext () { m_pNext = nullptr; }

	/*-------------------------------------------------------------*/

	private:

	/*-------------------------------------------------------------*/

		int m_value;

		Node * m_pNext;

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

	bool IsEmpty () const;

	int Size () const;

	const Node * GetFirst () const;

	const Node * GetLast () const;

	void Clear ();

	void PushBack ( int _value );

	void PushFront ( int _value );

	void PopBack ();

	void PopFront ();

	void InsertAfter ( const Node * _pPrevNode, int _value );

	void InsertBefore ( const Node * _pNextNode, int _value );

	void DeleteNode ( const Node * _pNode );

	void DeleteBefore ( const Node * _pNextNode );

	void DeleteAfter ( const Node * _pPrevNode );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	void CopyDataFrom ( const List & _l );

	bool Owns ( const Node * _pNode ) const;

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


inline const List::Node *
List::GetFirst () const
{
	return m_pFirst;
}


/*****************************************************************************/


inline const List::Node * 
List::GetLast () const
{
	return m_pLast;
}


/*****************************************************************************/

#endif // _LIST_HPP