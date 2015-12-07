// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "imagelibrary.hpp"

#include <iostream>

/*****************************************************************************/


struct ImageLibrary::ImageInternal
{
	std::string m_fileName;
	int m_width;
	int m_height;
};


/*****************************************************************************/


void *
ImageLibrary::loadImage ( const std::string & _filename )
{
	std::cout << "Loading image '" << _filename << "'" << std::endl;
	return new ImageInternal{ _filename, 400, 300 };
}


/*****************************************************************************/


void 
ImageLibrary::releaseImage ( void * _hImage )
{
	ImageInternal * pImage = ( ImageInternal * ) ( _hImage );
	std::cout << "Unloading image '" << pImage->m_fileName << "'" << std::endl;
	delete _hImage;
}


/*****************************************************************************/


std::pair< int, int >
ImageLibrary::getImageDimensions ( void * _hImage )
{
	ImageInternal * pImage = ( ImageInternal * ) ( _hImage );
	return std::make_pair( pImage->m_width, pImage->m_height );
}


/*****************************************************************************/
