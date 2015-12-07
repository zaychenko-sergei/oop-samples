// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "button.hpp"
#include "graphicslibrary.hpp"

/*****************************************************************************/


Button::Button ( const std::string & _text )
	: m_text( _text )
{
}


/*****************************************************************************/


void Button::addClickHandler ( ClickHandler & _handler )
{
	m_clickHandlers.push_back( &_handler );
}


/*****************************************************************************/


void Button::generateClick ()
{
	for ( ClickHandler * pHandler : m_clickHandlers )
		pHandler->onClicked( * this );
}


/*****************************************************************************/


void Button::draw ( int _x, int _y )
{
	std::pair< int, int > dimensions = calculateTextSize();

	drawRectangle( _x, _y, dimensions.first + 2 * PADDING, dimensions.second + 2 * PADDING );
	drawText( _x + PADDING, _y + PADDING );
}


/*****************************************************************************/


std::pair< int, int >
Button::calculateTextSize () const
{
	return GraphicsLibrary::calculateTextSize( m_text );
}


/*****************************************************************************/


void Button::drawRectangle ( int _x, int _y, int _width, int _height )
{
	GraphicsLibrary::drawRectangle( _x, _y, _width, _height, "black", "grey" );
}


/*****************************************************************************/


void Button::drawText ( int _x, int _y )
{
	GraphicsLibrary::drawText( _x, _y, m_text, "grey" );
}


/*****************************************************************************/
