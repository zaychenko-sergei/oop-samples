// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "list.hpp"

#include <utility>
#include <stdexcept>

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
	const Node * pTemp = _l.GetFirst();
	while ( pTemp )
	{
		PushBack( pTemp->GetValue() );
		pTemp = pTemp->GetNext();
	}
}


/*****************************************************************************/


int List::Size () const
{
	int numElements = 0;
	const Node * pCurrent = GetFirst();
	while ( pCurrent )
	{
		++ numElements;
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


void List::InsertAfter ( const Node * _pPrevNode, int _value )
{
	if ( IsEmpty() )
		throw std::logic_error( "List is empty" );
	else if ( ! Owns( _pPrevNode ) )
		throw std::logic_error( "Node does not belong to list" );

	if ( _pPrevNode == m_pLast )
		PushBack( _value );

	else
	{
		Node * pNewNode = new Node( _value );

		Node * pPrevNode = const_cast< Node * >( _pPrevNode );
		pNewNode->SetNext( pPrevNode->GetNext() );
		pPrevNode->SetNext( pNewNode );
	}
}


/*****************************************************************************/


void List::InsertBefore ( const Node * _pNextNode, int _value )
{
	if ( IsEmpty() )
		throw std::logic_error( "List is empty" );
	else if ( ! Owns( _pNextNode ) )
		throw std::logic_error( "Node does not belong to list" );

	if ( _pNextNode == m_pFirst )
		PushFront( _value );

	else
	{
		Node * pCurrent = m_pFirst;
		while ( pCurrent->GetNext() != _pNextNode )
			pCurrent = pCurrent->GetNext();

		Node * pNewNode = new Node( _value );

		Node * pNextNode = const_cast< Node * >( _pNextNode );
		pNewNode->SetNext( pNextNode );
		pCurrent->SetNext( pNewNode );
	}
}


/*****************************************************************************/


void List::DeleteAfter ( const Node * _pPrevNode )
{
	if ( IsEmpty() )
		throw std::logic_error( "List is empty" );
	else if ( !Owns( _pPrevNode ) )
		throw std::logic_error( "Node does not belong to list" );
	else if ( m_pLast == _pPrevNode )
		throw std::logic_error( "No nodes after last node" );

	Node * pPrevNode = const_cast< Node * >( _pPrevNode );
	Node * pDyingNode = pPrevNode->GetNext();
	pPrevNode->SetNext( pDyingNode->GetNext() );

	if ( m_pLast == pDyingNode )
		m_pLast = pPrevNode;

	delete pDyingNode;
}


/*****************************************************************************/


void List::DeleteBefore ( const Node * _pNextNode )
{
	if ( IsEmpty() )
		throw std::logic_error( "List is empty" );
	else if ( ! Owns( _pNextNode ) )
		throw std::logic_error( "Node does not belong to list" );
	else if ( m_pFirst == _pNextNode )
		throw std::logic_error( "No nodes before first node" );

	Node * pNextNode = const_cast< Node * >( _pNextNode );

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


void List::DeleteNode ( const Node * _pNode )
{
	if ( m_pFirst == _pNode )
		PopFront();

	else if ( m_pLast == _pNode )
		PopBack();

	else
		DeleteBefore( _pNode->GetNext() );
}


/*****************************************************************************/


bool List::Owns ( const Node * _pNode ) const
{
	const Node * pCurrent = GetFirst();
	while ( pCurrent )
	{
		if ( pCurrent == _pNode )
			return true;

		pCurrent = pCurrent->GetNext();
	}

	return false;
}


/*****************************************************************************/
