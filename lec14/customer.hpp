// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _CUSTOMER_HPP_
#define _CUSTOMER_HPP_

/*****************************************************************************/

#include <string>

/*****************************************************************************/


class Customer
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Customer ( std::string const & _name, std::string const & _phone );

	Customer ( const Customer & ) = delete;

	Customer & operator = ( const Customer & ) = delete;

	std::string const & getName () const;

	std::string const & getPhone () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::string m_name;

	std::string m_phone;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline 
Customer::Customer ( std::string const & _name, std::string const & _phone )
	:	m_name( _name )
	,	m_phone( _phone )
{}


/*****************************************************************************/


inline std::string const & 
Customer::getName () const 
{ 
	return m_name; 
}


/*****************************************************************************/


inline std::string const & 
Customer::getPhone () const 
{ 
	return m_phone; 
}


/*****************************************************************************/

#endif // _CUSTOMER_HPP_
