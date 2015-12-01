// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _DIRECTORY_HPP_
#define _DIRECTORY_HPP_

/*****************************************************************************/

#include "filesystementry.hpp"

#include <vector>
#include <memory>
#include <unordered_map>

/*****************************************************************************/


class Directory
	:	public FilesystemEntry
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Directory ( const std::string & _name );

	virtual ~Directory ();

	Directory * clone () const override;

	bool isEmpty () const;

	int getChildEntriesCount () const;

	FilesystemEntry & getChildEntry ( int _index ) const;

	void addChildEntry ( std::unique_ptr< FilesystemEntry > _entry );

	void removeChildEntry ( FilesystemEntry * _pEntry );

	virtual int getSize () const;

	virtual void show ( std::ostream & _o, int _level ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::vector< std::unique_ptr< FilesystemEntry > > m_childEntries;

	std::unordered_map< const char *, int > m_childEntriesByName;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/


inline bool
Directory::isEmpty () const
{
	return m_childEntries.empty();
}


/*****************************************************************************/


inline int
Directory::getChildEntriesCount () const
{
	return m_childEntries.size();
}


/*****************************************************************************/


inline
FilesystemEntry &
Directory::getChildEntry ( int _index ) const
{
	return *m_childEntries.at( _index );
}


/*****************************************************************************/

#endif //  _DIRECTORY_HPP_
