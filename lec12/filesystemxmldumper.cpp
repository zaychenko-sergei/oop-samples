// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "filesystemxmldumper.hpp"

#include "file.hpp"
#include "directory.hpp"

/*****************************************************************************/


FilesystemXMLDumper::FilesystemXMLDumper ( std::ostream & _o, int _level )
    :    m_o( _o ), m_level( _level )
{
}


/*****************************************************************************/


void FilesystemXMLDumper::visit ( File const & _file )
{
    indent();
    m_o << "<file name=\"" << _file.getName() 
        << "\" size=\""    << _file.getSize() << "\" />" << std::endl;
}


/*****************************************************************************/


void FilesystemXMLDumper::visit ( Directory const & _directory )
{
    indent();
    m_o << "<directory name=\"" << _directory .getName() << "\">" << std::endl;
 
    ++ m_level;
    int nChildEntries = _directory.getChildEntriesCount();
    for ( int i = 0; i < nChildEntries; i++ )
        _directory.getChildEntry( i ).accept( * this );
    -- m_level;

    indent();
    m_o << "</directory>" << std::endl;
}


/*****************************************************************************/


void FilesystemXMLDumper::indent ()
{
    for ( int i = 0; i < m_level; i++ )
        m_o << "    ";
}


/*****************************************************************************/

