// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _IMAGECONTROL_HPP_
#define _IMAGECONTROL_HPP_

/*****************************************************************************/

#include <string>

/*****************************************************************************/


class ImageControl
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	ImageControl ( const std::string & _imageFilename );

	~ ImageControl ();

	void drawImage ( int _x, int _y ) const;

	int getImageWidth () const;

	int getImageHeight () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	void * m_hImage;

	int m_imageWidth, m_imageHeight;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline int
ImageControl::getImageWidth () const
{
	return m_imageWidth;
}


/*****************************************************************************/


inline int
ImageControl::getImageHeight () const
{
	return m_imageHeight;
}


/*****************************************************************************/

#endif //  _IMAGECONTROL_HPP_

