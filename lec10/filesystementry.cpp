// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "filesystementry.hpp"

/*****************************************************************************/


FilesystemEntry::FilesystemEntry ( const std::string & _name )
	: m_name( _name )
{
	ensureValidName( m_name );
}


/*****************************************************************************/


void FilesystemEntry::rename ( const std::string & _newName )
{
	ensureValidName( _newName );
	m_name = _newName;
}


/*****************************************************************************/


void FilesystemEntry::ensureValidName ( const std::string & _name )
{
	if ( _name.empty() )
		throw std::logic_error( "Name cannot be empty" );

	if ( _name.length() > 255 )
		throw std::logic_error( "Name is too long" );

	if ( _name.find_first_of( "*:<>?\\/|" ) != std::string::npos )
		throw std::logic_error( "Name contains forbidden characters" );
}


/*****************************************************************************/


void FilesystemEntry::show ( std::ostream & _o, int _level ) const
{
	for ( int i = 0; i < _level; i++ )
		_o << '\t';

	_o << '\"' << getName() << "\" (" << getSize() << " bytes)" << std::endl;
}


/*****************************************************************************/

