// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _SERVICEPROVIDER_HPP_
#define _SERVICEPROVIDER_HPP_

/*****************************************************************************/

#include <string>
#include <vector>
#include <map>
#include <memory>

/*****************************************************************************/

class Customer;
class VIPCustomer;

/*****************************************************************************/


class ServiceProvider
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	ServiceProvider ();

	ServiceProvider ( const ServiceProvider & ) = delete;

	ServiceProvider & operator = ( const ServiceProvider & ) = delete;

	~ ServiceProvider ();

/*-----------------------------------------------------------------*/

	void addCustomer ( std::string const & _name, std::string const & _phone, bool _vipStatus );

	Customer * findCustomer ( std::string const & _name ) const;

	void notifyVIPCustomers ( std::string const & _body ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::map< std::string, std::unique_ptr< Customer > > m_customers;

	std::vector< VIPCustomer * > m_vipCustomers;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif // _SERVICEPROVIDER_HPP_
