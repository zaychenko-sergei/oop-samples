// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

/*****************************************************************************/

#include <string>
#include <vector>

/*****************************************************************************/


class Button
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	class ClickHandler
	{
	public:
		virtual void onClicked ( Button & _b ) = 0;
	};

/*-----------------------------------------------------------------*/

	Button ( const std::string & _text );

	Button ( const Button & ) = delete;

	Button operator = ( const Button & ) = delete;

	virtual ~Button () = default;

/*-----------------------------------------------------------------*/

	const std::string & getText () const;

	void updateText ( const std::string & _text );

	void addClickHandler ( ClickHandler & _handler );

	void generateClick ();

	virtual void draw ( int _x, int _y );

/*-----------------------------------------------------------------*/

protected:
	
/*-----------------------------------------------------------------*/

	std::pair< int, int > calculateTextSize () const;

	void drawRectangle ( int _x, int _y, int _width, int _height );

	void drawText ( int _x, int _y );

/*-----------------------------------------------------------------*/

	static const int PADDING = 5;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::string m_text;

	std::vector< ClickHandler * > m_clickHandlers;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline const std::string &
Button::getText () const
{
	return m_text;
}


/*****************************************************************************/


inline void
Button::updateText ( const std::string & _text )
{
	m_text = _text;
}


/*****************************************************************************/

#endif //  _BUTTON_HPP_
