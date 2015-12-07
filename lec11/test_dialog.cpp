// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "dialog.hpp"
#include "button.hpp"

#include <cassert>

/*****************************************************************************/


int main ()
{
	Dialog d( "Confirm?" );
	d.show();
	assert( ! d.isClosed() );
	
	d.getOKButton().generateClick();
	assert( d.isClosed() );
	assert( d.getResult() );
}


/*****************************************************************************/
