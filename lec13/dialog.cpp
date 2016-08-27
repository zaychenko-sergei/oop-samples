// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "dialog.hpp"

/*****************************************************************************/


Dialog::Dialog ( const std::string & _title )
	:	Window( _title )
	,	m_okButton( "OK" )
	,	m_cancelButton( "Cancel" )
	,	m_result( false )
{
	m_okButton.addClickHandler( * this );
	m_cancelButton.addClickHandler( * this );
}


/*****************************************************************************/


void
Dialog::draw ()
{
	Window::draw();

	int buttonsVerticalLine = getLeftTopY() + getHeight() * 9 / 10;
	m_okButton.draw( getLeftTopX() + getWidth() / 3, buttonsVerticalLine );
	m_cancelButton.draw( getLeftTopX() + getWidth() * 2 / 3, buttonsVerticalLine );
}


/*****************************************************************************/


void 
Dialog::onClicked ( Button & _b )
{
	if ( &_b == &m_okButton )
	{
		m_result = true;
		close();
	}

	else if ( &_b == &m_cancelButton )
	{
		m_result = false;
		close();
	}

	else
		throw std::logic_error( "Unexpected button click" );
}


/*****************************************************************************/
