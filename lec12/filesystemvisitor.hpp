// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _FILESYSTEMVISITOR_HPP_
#define _FILESYSTEMVISITOR_HPP_

/*****************************************************************************/

class File;
class Directory;

/*****************************************************************************/


class FilesystemVisitor
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	virtual ~ FilesystemVisitor () = default;

	virtual void visit ( File const & _file ) = 0;

	virtual void visit ( Directory const & _directory ) = 0;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif //  _FILESYSTEMVISITOR_HPP_
