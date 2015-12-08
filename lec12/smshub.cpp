// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "smshub.hpp"

#include <iostream>

/*****************************************************************************/


void SMSHub::sendSMS ( std::string const & _phone, std::string const & _body )
{
	std::cout << "SMS to " << _phone << ": " << _body << std::endl;
}


/*****************************************************************************/
