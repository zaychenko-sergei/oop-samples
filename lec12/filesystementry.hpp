// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _FILESYSTEMENTRY_HPP_
#define _FILESYSTEMENTRY_HPP_

/*****************************************************************************/

#include <string>
#include <ostream>

/*****************************************************************************/


class FilesystemEntry
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	FilesystemEntry ( const FilesystemEntry & ) = delete;
	FilesystemEntry & operator = ( const FilesystemEntry & ) = delete;

	virtual ~FilesystemEntry () = default;

	virtual FilesystemEntry * clone () const = 0;

	const std::string & getName () const;

	void rename ( const std::string & _newName );

	virtual int getSize () const = 0;

	virtual void show ( std::ostream & _o, int _level ) const;

/*-----------------------------------------------------------------*/

protected:

/*-----------------------------------------------------------------*/

	FilesystemEntry ( const std::string & _name );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	void ensureValidName ( const std::string & _name );

/*-----------------------------------------------------------------*/

	std::string m_name;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/


inline
const std::string &
FilesystemEntry::getName () const
{
	return m_name;
}


/*****************************************************************************/

#endif //  _FILESYSTEMENTRY_HPP_
