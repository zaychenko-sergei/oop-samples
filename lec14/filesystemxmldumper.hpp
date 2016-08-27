// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _FILESYSTEM_XML_DUMPER_HPP_
#define _FILESYSTEM_XML_DUMPER_HPP_

//************************************************************************

#include "filesystemvisitor.hpp"

#include <ostream>

/*****************************************************************************/


class FilesystemXMLDumper
    :    public FilesystemVisitor
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

    FilesystemXMLDumper ( std::ostream & _o, int _level = 0 );

    void visit ( File const & _file ) override;
    void visit ( Directory const & _directory ) override;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

    void indent ();

/*-----------------------------------------------------------------*/

    std::ostream & m_o;

    int m_level;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif // _FILESYSTEM_XML_DUMPER_HPP_