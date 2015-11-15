// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "account.hpp"

#include <functional>
#include <stdexcept>

/*****************************************************************************/


Account::Account (
		const std::string & _fullName
	,	const std::string & _email
	,	unsigned int _passwordHash
)
	:	m_fullName( _fullName )
	,	m_email( _email )
	,	m_passwordHash( _passwordHash )
	,	m_isAuthorized( false )
{
}


/*****************************************************************************/


void Account::authorize ( const std::string & _password )
{
	static std::hash< std::string > hasher;

	if ( m_passwordHash == hasher( _password ) )
		m_isAuthorized = true;

	else
		throw std::runtime_error( "Incorrect password." );
}


/*****************************************************************************/


void Account::clearAuthorization ()
{
	m_isAuthorized = false;
}


/*****************************************************************************/
