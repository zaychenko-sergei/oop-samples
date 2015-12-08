// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "file.hpp"
#include "filesystemvisitor.hpp"

/*****************************************************************************/


File::File ( const std::string & _name, int _size )
	:	FilesystemEntry( _name )
	,	m_size( _size )
{
	validateSize( m_size );
}


/*****************************************************************************/


void File::accept ( FilesystemVisitor & _visitor ) const
{
	_visitor.visit( * this );
}


/*****************************************************************************/


File * File::clone () const
{
	return new File( getName(), getSize() );
}


/*****************************************************************************/


int File::getSize () const
{
	return m_size;
}


/*****************************************************************************/


void File::updateSize ( int _newSize )
{
	validateSize( m_size );
	m_size = _newSize;
}


/*****************************************************************************/


void File::validateSize ( int _size )
{
	if ( _size < 0 )
		throw std::logic_error( "File size cannot be negative" );
}


/*****************************************************************************/

