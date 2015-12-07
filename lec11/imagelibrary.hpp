// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _IMAGELIBRARY_HPP_
#define _IMAGELIBRARY_HPP_

/*****************************************************************************/

#include <string>

/*****************************************************************************/


class ImageLibrary
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	static void * loadImage ( const std::string & _filename );

	static void releaseImage ( void * _hImage );

	static std::pair< int, int > getImageDimensions ( void * _hImage );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	struct ImageInternal;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif //  _IMAGELIBRARY_HPP_
