// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "graphicslibrary.hpp"

#include <iostream>

/*****************************************************************************/


std::pair< int, int > 
GraphicsLibrary::calculateTextSize ( std::string const & _text )
{
	return std::make_pair( 10 * _text.length(), 10 );
}


/*****************************************************************************/


void 
GraphicsLibrary::drawText (
		int _x
	,	int _y
	,	std::string const &  _text
	,	std::string const & _color
)
{
	std::cout << "Drawing text '" << _text  << 
		"' at (" << _x << ',' << _y << ") " << 
		"using color " << _color << std::endl;
}


/*****************************************************************************/


void 
GraphicsLibrary::drawRectangle (
		int _x
	,	int _y
	,	int _width
	,	int _height
	,	std::string const & _borderColor
	,	std::string const & _fillColor
)
{
	std::cout << "Drawing rectangle at (" << _x << ',' << _y << ") " 
				<< _width << 'x' << _height << 
			    " using border color " << _borderColor
			    << " and fill color " << _fillColor << std::endl;
}


/*****************************************************************************/


void
GraphicsLibrary::drawImage ( int _x, int _y, void * _hImage )
{
	std::cout << "Drawing image at (" << _x << ',' << _y << ") " << std::endl;
}


/*****************************************************************************/
