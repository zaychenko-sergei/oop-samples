// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _SERVERADMINISTRATOR_HPP_
#define _SERVERADMINISTRATOR_HPP_

/*****************************************************************************/

#include "account.hpp"

/*****************************************************************************/


class ServerAdministrator
	:	public Account
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	ServerAdministrator (
			const std::string & _fullName
		,	const std::string & _email
		,	unsigned int _passwordHash
	);


	void restartServer ( const std::string & _password );


	void runServerDiagnostics ( const std::string & _password );

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif // _SERVERADMINISTRATOR_HPP_
