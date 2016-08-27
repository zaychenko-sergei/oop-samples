// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "directory.hpp"
#include "filesystemvisitor.hpp"

/*****************************************************************************/


Directory::Directory ( const std::string & _name )
	:	FilesystemEntry( _name )
{
}


/*****************************************************************************/

Directory::~Directory () = default;

/*****************************************************************************/


void Directory::accept ( FilesystemVisitor & _visitor ) const
{
	_visitor.visit( * this );
}


/*****************************************************************************/


Directory *
Directory::clone () const
{
	Directory * pClone = new Directory( getName() );
	
	for ( auto const & pChildEntry : m_childEntries )
		pClone->addChildEntry( std::unique_ptr< FilesystemEntry >( pChildEntry->clone() ) );

	return pClone;
}


/*****************************************************************************/


void Directory::addChildEntry ( std::unique_ptr< FilesystemEntry > _entry )
{
	const char * pEntryName = _entry->getName().c_str();
	if ( m_childEntriesByName.count( pEntryName ) )
		throw std::logic_error( "Child entry name is not unique" );

	m_childEntriesByName[ pEntryName ] = getChildEntriesCount();

	m_childEntries.push_back( std::move( _entry ) );
}


/*****************************************************************************/


void Directory::removeChildEntry ( FilesystemEntry * _pEntry )
{
	auto itByName = m_childEntriesByName.find( _pEntry->getName().c_str() );
	if ( itByName == m_childEntriesByName.end() )
		throw std::logic_error( "Entry does not exist in the directory" );

	int position = itByName->second;
	m_childEntries.erase( m_childEntries.begin() + position );

	m_childEntriesByName.erase( itByName );
}


/*****************************************************************************/


int Directory::getSize () const
{
	int nTotalSize = 0;
	for ( auto const & pChildEntry : m_childEntries )
		nTotalSize += pChildEntry->getSize();
	return nTotalSize;
}


/*****************************************************************************/
