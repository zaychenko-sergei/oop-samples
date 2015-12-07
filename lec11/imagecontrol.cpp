// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "imagecontrol.hpp"

#include "imagelibrary.hpp"
#include "graphicslibrary.hpp"

/*****************************************************************************/


ImageControl::ImageControl ( const std::string & _imageFilename )
{
	m_hImage = ImageLibrary::loadImage( _imageFilename );
	if ( ! m_hImage )
		throw std::runtime_error( "Failed to load image" );

	std::pair< int, int > dimensions = ImageLibrary::getImageDimensions( m_hImage );
	m_imageWidth  = dimensions.first;
	m_imageHeight = dimensions.second;
}


/*****************************************************************************/


ImageControl::~ImageControl ()
{
	ImageLibrary::releaseImage( m_hImage );
}


/*****************************************************************************/


void ImageControl::drawImage ( int _x, int _y ) const
{
	GraphicsLibrary::drawImage( _x, _y, m_hImage );
}


/*****************************************************************************/

