// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _SMSHUB_HPP_
#define _SMSHUB_HPP_

/*****************************************************************************/

#include <string>

/*****************************************************************************/


class SMSHub
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	static void sendSMS ( std::string const & _phone, std::string const & _body );

/*-----------------------------------------------------------------*/

};



/*****************************************************************************/

#endif // _SMSHUB_HPP_