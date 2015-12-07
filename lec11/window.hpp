// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

/*****************************************************************************/

#include "graphicslibrary.hpp"
#include <string>

/*****************************************************************************/


class Window
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Window ( const std::string & _title );

	Window ( const Window & ) = delete;

	Window & operator = ( const Window & ) = delete;

	virtual ~Window () = default;

/*-----------------------------------------------------------------*/

	virtual void draw ();

	int getWidth () const;

	int getHeight () const;

	void resize ( int _width, int _height );

	int getLeftTopX () const;

	int getLeftTopY () const;

	void relocate ( int _leftTopX, int _leftTopY );

	const std::string & getTitle () const;

	void updateTitle ( const std::string & _title );

	bool isClosed () const;

	void show ();

	void close ();

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::string m_title;

	int m_width, m_height;

	int m_leftTopX, m_leftTopY;

	bool m_closed;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline int
Window::getWidth () const
{
	return m_width;
}


/*****************************************************************************/


inline int
Window::getHeight () const
{
	return m_height;
}


/*****************************************************************************/


inline int
Window::getLeftTopX () const
{
	return m_leftTopX;
}


/*****************************************************************************/


inline int
Window::getLeftTopY () const
{
	return m_leftTopY;
}


/*****************************************************************************/


inline void
Window::relocate ( int _leftTopX, int _leftTopY )
{
	m_leftTopX = _leftTopX;
	m_leftTopY = _leftTopY;
}


/*****************************************************************************/


inline
const std::string &
Window::getTitle () const
{
	return m_title;
}


/*****************************************************************************/


inline void
Window::updateTitle ( const std::string & _title )
{
	m_title = _title;;
}


/*****************************************************************************/


inline bool
Window::isClosed () const
{
	return m_closed;
}


/*****************************************************************************/

#endif // _WINDOW_HPP_
