// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ACCOUNT_HPP_
#define _ACCOUNT_HPP_

/*****************************************************************************/

#include <string>

/*****************************************************************************/


class Account
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Account ( const Account & ) = delete;
	Account & operator = ( const Account & ) = delete;

	const std::string & getFullName () const;

	const std::string & getEmail () const;

	bool isAuthorized () const;

/*-----------------------------------------------------------------*/

protected:

/*-----------------------------------------------------------------*/

	Account (
			const std::string & _fullName
		,	const std::string & _email
		,	unsigned int _passwordHash
	);


	void authorize ( const std::string & _enteredPassword );

	void clearAuthorization ();

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const std::string m_fullName;

	const std::string m_email;

	const unsigned int m_passwordHash;

	bool m_isAuthorized;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline
const std::string &
Account::getFullName () const
{
	return m_fullName;
}


/*****************************************************************************/


inline
const std::string &
Account::getEmail () const
{
	return m_email;
}


/*****************************************************************************/


inline bool
Account::isAuthorized () const
{
	return m_isAuthorized;
}


/*****************************************************************************/

#endif // _ACCOUNT_HPP_