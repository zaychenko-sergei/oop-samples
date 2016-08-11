// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _LIST_HPP_
#define _LIST_HPP_

/*****************************************************************************/

#include <initializer_list>
#include <utility>
#include <stdexcept>

/*****************************************************************************/


template< typename T >
class List
{

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	class Node
	{

	/*-------------------------------------------------------------*/

	public:

	/*-------------------------------------------------------------*/

		Node ( const T & _value )
			: m_value( _value )
			, m_pNext( nullptr )
		{}

		const T & GetValue () const { return m_value; }

		T & GetValue () { return m_value; }

		Node const * GetNext () const { return m_pNext; }

		Node * GetNext () { return m_pNext; }

		void SetNext ( Node * _pNext ) { m_pNext = _pNext; }

		void ClearNext () { m_pNext = nullptr; }

	/*-------------------------------------------------------------*/

	private:

	/*-------------------------------------------------------------*/

		T m_value;

		Node * m_pNext;

	/*-------------------------------------------------------------*/

	};

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	class Iterator
	{

	/*-------------------------------------------------------------*/

	public:

	/*-------------------------------------------------------------*/

		explicit Iterator ( Node * _pNode = nullptr );

		const T & operator * () const;
		T & operator * ();

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

	template< typename U >
	List ( std::initializer_list< U > _l );

	template< typename U >
	List ( const List< U > & _l );

	List ( List< T > && _l );

	~List ();

	template< typename U >
	List< T > & operator = ( const List< U > & _l );

	List< T > & operator = ( List< T > && _l );

/*-----------------------------------------------------------------*/

	Iterator begin () const;

	Iterator end () const;

/*-----------------------------------------------------------------*/

	bool IsEmpty () const;

	int Size () const;

	void Clear ();

	void PushBack ( const T & _value );

	void PushFront ( const T & _value );

	void PopBack ();

	void PopFront ();

	void InsertAfter ( Iterator _prevPos, const T & _value );

	void InsertBefore ( Iterator _nextPos, const T & _value );

	void Delete ( Iterator _pos );

	void DeleteBefore ( Iterator _nextPos );

	void DeleteAfter ( Iterator _prevPos );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	template< typename U >
	void CopyDataFrom ( const List< U > & _l );

	bool Owns ( Iterator _pos ) const;

/*-----------------------------------------------------------------*/

	Node * m_pFirst;

	Node * m_pLast;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


template< typename T >
List< T >::List ()
	:	m_pFirst( nullptr )
	,	m_pLast( nullptr )
{
}


/*****************************************************************************/


template< typename T >
    template< typename U >
List< T >::List ( std::initializer_list< U > _l )
	:	List()
{
	for ( const U & x : _l )
		PushBack( ( T ) x );
}


/*****************************************************************************/


template< typename T >
	template< typename U >
List< T >::List ( const List< U > & _l )
	:	List()
{
	CopyDataFrom( _l );
}


/*****************************************************************************/


template< typename T >
List< T >::List ( List< T > && _l )
	:	m_pFirst( _l.m_pFirst )
	,	m_pLast( _l.m_pLast )
{
	_l.m_pFirst = nullptr;
	_l.m_pLast  = nullptr;
}


/*****************************************************************************/


template< typename T >
	template< typename U >
List< T > & List< T >::operator = ( const List< U > & _l )
{
	if ( ( const void * ) this == ( const void * ) ( & _l ) )
		return * this;

	Clear();
	CopyDataFrom( _l );
	return * this;
}


/*****************************************************************************/


template< typename T >
List< T > & List< T >::operator = ( List< T > && _l )
{
	if ( this == &_l )
		return * this;

	std::swap( m_pFirst, _l.m_pFirst );
	std::swap( m_pLast,  _l.m_pLast  );

	return *this;
}


/*****************************************************************************/


template< typename T >
List< T >::~List ()
{
	Clear();
}


/*****************************************************************************/


template< typename T >
inline bool List< T >::IsEmpty () const
{
	return m_pFirst == nullptr;
}


/*****************************************************************************/


template< typename T >
inline typename List< T >::Iterator List< T >::begin () const
{
	return Iterator( m_pFirst );
}


/*****************************************************************************/


template< typename T >
inline typename List< T >::Iterator List< T >::end () const
{
	return Iterator();
}


/*****************************************************************************/


template< typename T >
void List< T >::Clear ()
{
	Node * pCurrent = m_pFirst;
	while ( pCurrent )
	{
		Node * pTemp = pCurrent;
		pCurrent = pCurrent->GetNext();
		delete pTemp;
	}

	m_pFirst = m_pLast = nullptr;
}


/*****************************************************************************/


template< typename T >
	template< typename U >
void List< T >::CopyDataFrom ( const List< U > & _l )
{
	for ( const T & x : _l )
		PushBack( ( T ) x );
}


/*****************************************************************************/


template< typename T >
int List< T >::Size () const
{
	int numElements = 0;
	const Node * pCurrent = m_pFirst;
	while ( pCurrent )
	{
		++numElements;
		pCurrent = pCurrent->GetNext();
	}

	return numElements;
}


/*****************************************************************************/


template< typename T >
void List< T >::PushBack ( const T & _value )
{
	Node * pNewNode = new Node( _value );

	if ( ! m_pFirst )
		m_pFirst = pNewNode;

	else
		m_pLast->SetNext( pNewNode );

	m_pLast = pNewNode;
}


/*****************************************************************************/


template< typename T >
void List< T >::PushFront ( const T & _value )
{
	Node * pNewNode = new Node( _value );
	pNewNode->SetNext( m_pFirst );

	m_pFirst = pNewNode;
	if ( ! m_pLast )
		m_pLast = pNewNode;
}


/*****************************************************************************/


template< typename T >
void List< T >::PopBack ()
{
	if ( IsEmpty() )
		throw std::logic_error( "List is empty" );

    Node * pLast = m_pLast;

    if ( m_pFirst == m_pLast )
        m_pFirst = m_pLast = nullptr;

    else
    {
        Node * pCurrent = m_pFirst;
        while ( pCurrent->GetNext() != m_pLast )
            pCurrent = pCurrent->GetNext();

        m_pLast = pCurrent;
		pCurrent->ClearNext();
    }

    delete pLast;
}


/*****************************************************************************/


template< typename T >
void List< T >::PopFront ()
{
	if ( IsEmpty() )
		throw std::logic_error( "List is empty" );

	Node * pFirst = m_pFirst;

	if ( m_pFirst == m_pLast )
		m_pFirst = m_pLast = nullptr;

	else
		m_pFirst = pFirst->GetNext();

	delete pFirst;
}


/*****************************************************************************/


template< typename T >
void List< T >::InsertAfter ( Iterator _prevPos, const T & _value )
{
	if ( IsEmpty() )
		throw std::logic_error( "List is empty" );
	else if ( ! Owns( _prevPos ) )
		throw std::logic_error( "Node does not belong to list" );

	if ( _prevPos.m_pCurrent == m_pLast )
		PushBack( _value );

	else
	{
		Node * pNewNode = new Node( _value );

		Node * pPrevNode = _prevPos.m_pCurrent;
		pNewNode->SetNext( pPrevNode->GetNext() );
		pPrevNode->SetNext( pNewNode );
	}
}


/*****************************************************************************/


template< typename T >
void List< T >::InsertBefore ( Iterator _nextPos, const T & _value )
{
	if ( IsEmpty() )
		throw std::logic_error( "List is empty" );
	else if ( ! Owns( _nextPos ) )
		throw std::logic_error( "Node does not belong to list" );

	if ( _nextPos.m_pCurrent == m_pFirst )
		PushFront( _value );

	else
	{
		Node * pCurrent = m_pFirst;
		while ( pCurrent->GetNext() != _nextPos.m_pCurrent )
			pCurrent = pCurrent->GetNext();

		Node * pNewNode = new Node( _value );

		Node * pNextNode = _nextPos.m_pCurrent;
		pNewNode->SetNext( pNextNode );
		pCurrent->SetNext( pNewNode );
	}
}


/*****************************************************************************/


template< typename T >
void List< T >::DeleteAfter ( Iterator _prevPos )
{
	if ( IsEmpty() )
		throw std::logic_error( "List is empty" );
	else if ( !Owns( _prevPos ) )
		throw std::logic_error( "Node does not belong to list" );
	else if ( m_pLast == _prevPos.m_pCurrent )
		throw std::logic_error( "No nodes after last node" );

	Node * pPrevNode = _prevPos.m_pCurrent;
	Node * pDyingNode = pPrevNode->GetNext();
	pPrevNode->SetNext( pDyingNode->GetNext() );

	if ( m_pLast == pDyingNode )
		m_pLast = pPrevNode;

	delete pDyingNode;
}


/*****************************************************************************/


template< typename T >
void List< T >::DeleteBefore ( Iterator _nextPos )
{
	if ( IsEmpty() )
		throw std::logic_error( "List is empty" );
	else if ( ! Owns( _nextPos ) )
		throw std::logic_error( "Node does not belong to list" );
	else if ( m_pFirst == _nextPos.m_pCurrent )
		throw std::logic_error( "No nodes before first node" );

	Node * pNextNode = _nextPos.m_pCurrent;

	Node * pPrevNode = m_pFirst, * pCurrentNode = m_pFirst->GetNext();
	if ( pCurrentNode == pNextNode )
	{
		delete m_pFirst;
		m_pFirst = pNextNode;
	}

	else
	{
		while ( pCurrentNode->GetNext() != pNextNode )
		{
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->GetNext();
		}

		pPrevNode->SetNext( pNextNode );
		delete pCurrentNode;
	}
}


/*****************************************************************************/


template< typename T >
void List< T >::Delete ( Iterator _pos )
{
	if ( m_pFirst == _pos.m_pCurrent )
		PopFront();

	else if ( m_pLast == _pos.m_pCurrent )
		PopBack();

	else
		DeleteBefore( ++ _pos );
}


/*****************************************************************************/


template< typename T >
bool List< T >::Owns ( Iterator _pos ) const
{
	const Node * pCurrent = m_pFirst;
	while ( pCurrent )
	{
		if ( pCurrent == _pos.m_pCurrent )
			return true;

		pCurrent = pCurrent->GetNext();
	}

	return false;
}


/*****************************************************************************/


template< typename T >
List< T >::Iterator::Iterator ( Node * _pNode )
	:	m_pCurrent( _pNode )
{
}


/*****************************************************************************/


template< typename T >
const T & List< T >::Iterator::operator * () const
{
	validate();
	return m_pCurrent->GetValue();
}


/*****************************************************************************/


template< typename T >
T & List< T >::Iterator::operator * ()
{
	validate();
	return m_pCurrent->GetValue();
}


/*****************************************************************************/


template< typename T >
bool List< T >::Iterator::operator == ( Iterator i ) const
{
	return m_pCurrent == i.m_pCurrent;
}


/*****************************************************************************/


template< typename T >
bool List< T >::Iterator::operator != ( Iterator i ) const
{
	return !( * this == i );
}


/*****************************************************************************/


template< typename T >
typename List< T >::Iterator & List< T >::Iterator::operator ++ ()
{
	validate();
	m_pCurrent = m_pCurrent->GetNext();
	return * this;
}


/*****************************************************************************/


template< typename T >
typename List< T >::Iterator List< T >::Iterator::operator ++ ( int )
{
	validate();
	Iterator copy = * this;
	m_pCurrent = m_pCurrent->GetNext();
	return copy;
}


/*****************************************************************************/


template< typename T >
void List< T >::Iterator::validate () const
{
	if ( !m_pCurrent )
		throw std::logic_error( "Invalid list iterator state" );
}


/*****************************************************************************/

#endif // _LIST_HPP