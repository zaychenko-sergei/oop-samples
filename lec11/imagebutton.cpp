// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "imagebutton.hpp"

/*****************************************************************************/


ImageButton::ImageButton ( const std::string & _text, const std::string & _imageFilename )
	:	Button( _text )
	,	ImageControl( _imageFilename )
{
}


/*****************************************************************************/


void ImageButton::draw ( int _x, int _y )
{
	std::pair< int, int > dimensions = calculateTextSize();

	dimensions.first += getImageWidth() + 3 * PADDING;

	if ( getImageHeight() > dimensions.second )
		dimensions.second = getImageHeight();
	dimensions.second += 2 * PADDING;

	drawRectangle( _x, _y, dimensions.first, dimensions.second );
	drawImage( _x + PADDING, _y + PADDING );
	drawText( _x + getImageWidth() + 2 * PADDING, _y + PADDING );
}


/*****************************************************************************/
