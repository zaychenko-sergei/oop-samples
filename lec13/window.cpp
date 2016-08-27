// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "window.hpp"

/*****************************************************************************/


Window::Window ( const std::string & _title )
	:	m_title( _title )
	,	m_leftTopX( 0 )
	,	m_leftTopY( 0 )
	,	m_width( 800 )
	,	m_height( 600 )
	,	m_closed( true )
{
}


/*****************************************************************************/


void 
Window::draw ()
{
	if ( isClosed() )
		throw std::logic_error( "Attempting to draw a closed window" );

	GraphicsLibrary::drawRectangle(
			m_leftTopX
		,	m_leftTopY
		,	m_width
		,	m_height
		,	"black"
		,	"white"
	);

	GraphicsLibrary::drawText( m_leftTopX + 2, m_leftTopY + 2, m_title, "black" );
}


/*****************************************************************************/


void 
Window::resize ( int _width, int _height )
{
	if ( _width <= 0 || _height <= 0 )
		throw std::logic_error( "Dimensions must be positive" );

	m_width = _width;
	m_height = _height;
}


/*****************************************************************************/


void 
Window::show ()
{
	if ( ! isClosed() )
		throw std::logic_error( "Window is already shown" );
	
	m_closed = false;
}


/*****************************************************************************/


void 
Window::close ()
{
	if ( isClosed() )
		throw std::logic_error( "Window is already closed" );

	m_closed = true;
}


/*****************************************************************************/
