// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "list.hpp"

#include <utility>
#include <stdexcept>

/*****************************************************************************/


class List::Node
{

/*-------------------------------------------------------------*/

public:

/*-------------------------------------------------------------*/

	Node ( int _value )
		: m_value( _value )
		, m_pNext( nullptr )
	{}

	int GetValue () const { return m_value; }

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


/*****************************************************************************/


List::List ()
	:	m_pFirst( nullptr )
	,	m_pLast( nullptr )
{
}


/*****************************************************************************/


List::List ( std::initializer_list< int > _l )
	:	List()
{
	for ( int x : _l )
		PushBack( x );
}


/*****************************************************************************/


List::List ( const List & _l )
	:	List()
{
	CopyDataFrom( _l );
}


/*****************************************************************************/


List::List ( List && _l )
	:	m_pFirst( _l.m_pFirst )
	,	m_pLast( _l.m_pLast )
{
	_l.m_pFirst = nullptr;
	_l.m_pLast  = nullptr;
}


/*****************************************************************************/


List & List::operator = ( const List & _l )
{
	if ( this == & _l )
		return * this;

	Clear();
	CopyDataFrom( _l );
	return * this;
}


/*****************************************************************************/


List & List::operator = ( List && _l )
{
	if ( this == &_l )
		return * this;

	std::swap( m_pFirst, _l.m_pFirst );
	std::swap( m_pLast,  _l.m_pLast  );

	return *this;
}


/*****************************************************************************/


List::~List ()
{
	Clear();
}


/*****************************************************************************/


void List::Clear ()
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


void List::CopyDataFrom ( const List & _l )
{
	for ( int x : _l )
		PushBack( x );
}


/*****************************************************************************/


int List::Size () const
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


void List::PushBack ( int _value )
{
	Node * pNewNode = new Node( _value );

	if ( ! m_pFirst )
		m_pFirst = pNewNode;

	else
		m_pLast->SetNext( pNewNode );

	m_pLast = pNewNode;
}


/*****************************************************************************/


void List::PushFront ( int _value )
{
	Node * pNewNode = new Node( _value );
	pNewNode->SetNext( m_pFirst );

	m_pFirst = pNewNode;
	if ( ! m_pLast )
		m_pLast = pNewNode;
}


/*****************************************************************************/


void List::PopBack ()
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


void List::PopFront ()
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


void List::InsertAfter ( Iterator _prevPos, int _value )
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


void List::InsertBefore ( Iterator _nextPos, int _value )
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


void List::DeleteAfter ( Iterator _prevPos )
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


void List::DeleteBefore ( Iterator _nextPos )
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


void List::Delete ( Iterator _pos )
{
	if ( m_pFirst == _pos.m_pCurrent )
		PopFront();

	else if ( m_pLast == _pos.m_pCurrent )
		PopBack();

	else
		DeleteBefore( ++ _pos );
}


/*****************************************************************************/


bool List::Owns ( Iterator _pos ) const
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


List::Iterator::Iterator ( Node * _pNode )
	:	m_pCurrent( _pNode )
{
}


/*****************************************************************************/


int List::Iterator::operator * () const
{
	validate();
	return m_pCurrent->GetValue();
}


/*****************************************************************************/


int & List::Iterator::operator * ()
{
	validate();
	return m_pCurrent->GetValue();
}


/*****************************************************************************/


bool List::Iterator::operator == ( Iterator i ) const
{
	return m_pCurrent == i.m_pCurrent;
}


/*****************************************************************************/


bool List::Iterator::operator != ( Iterator i ) const
{
	return !( * this == i );
}


/*****************************************************************************/


List::Iterator & List::Iterator::operator ++ ()
{
	validate();
	m_pCurrent = m_pCurrent->GetNext();
	return * this;
}


/*****************************************************************************/


List::Iterator List::Iterator::operator ++ ( int )
{
	validate();
	Iterator copy = * this;
	m_pCurrent = m_pCurrent->GetNext();
	return copy;
}


/*****************************************************************************/


void List::Iterator::validate () const
{
	if ( !m_pCurrent )
		throw std::logic_error( "Invalid list iterator state" );
}


/*****************************************************************************/
