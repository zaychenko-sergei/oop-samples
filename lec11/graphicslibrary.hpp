// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _GRAPHICSLIBRARY_HPP_
#define _GRAPHICSLIBRARY_HPP_

/*****************************************************************************/

#include <string>
#include <iostream>

/*****************************************************************************/


class GraphicsLibrary
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	static std::pair< int, int > calculateTextSize ( std::string const & _text );

	static void drawText (
			int _x
		,	int _y
		,	std::string const &  _text
		,	std::string const & _color
	);

	static void drawRectangle (
			int _x
		,	int _y
		,	int _width
		,	int _height
		,	std::string const & _borderColor
		,	std::string const & _fillColor
	);

	static void drawImage ( int _x, int _y, void * _hImage );

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif //  _GRAPHICSLIBRARY_HPP_
