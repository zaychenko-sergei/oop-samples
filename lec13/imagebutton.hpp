// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _IMAGEBUTTON_HPP_
#define _IMAGEBUTTON_HPP_

/*****************************************************************************/

#include "button.hpp"
#include "imagecontrol.hpp"

/*****************************************************************************/


class ImageButton
    :    public Button, public ImageControl
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	ImageButton ( const std::string & _text, const std::string & _imageFilename );

	void draw ( int _x, int _y ) override;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif //  _IMAGEBUTTON_HPP_