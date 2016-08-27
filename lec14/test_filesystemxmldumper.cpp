// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "filesystemxmldumper.hpp"

#include "file.hpp"
#include "directory.hpp"

#include <iostream>

/*****************************************************************************/


std::unique_ptr< FilesystemEntry >
generateFilesystem ()
{
	auto pRootDir = std::make_unique< Directory >( "parent_dir" );

	pRootDir->addChildEntry( std::make_unique< File >( "1.txt", 150 ) );

	Directory * pSubDir = new Directory( "sub_dir" );
	pRootDir->addChildEntry( std::unique_ptr< Directory >( pSubDir ) );

	pSubDir->addChildEntry( std::make_unique< File >( "2.txt", 230 ) );
	pSubDir->addChildEntry( std::make_unique< File >( "3.txt", 115 ) );

	return pRootDir;
}


/*****************************************************************************/


int main ()
{
	auto entry = generateFilesystem();

	FilesystemXMLDumper dumper( std::cout );
	entry->accept( dumper );
}


/*****************************************************************************/
