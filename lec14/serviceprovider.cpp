// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "serviceprovider.hpp"
#include "vipcustomer.hpp"
#include "smshub.hpp"

/*****************************************************************************/

ServiceProvider::ServiceProvider () = default;

ServiceProvider::~ServiceProvider () = default;

/*****************************************************************************/


void 
ServiceProvider::addCustomer (
		std::string const & _name
	,	std::string const & _phone
	,	bool _vipStatus 
)
{
	if ( findCustomer( _name ) )
		throw std::logic_error( "Duplicate customer record" );

	Customer * pCustomer = nullptr;
	if ( _vipStatus )
	{
		VIPCustomer * pVIPCustomer = new VIPCustomer( _name, _phone );
		m_vipCustomers.push_back( pVIPCustomer );

		pCustomer = pVIPCustomer;
	}
	else
		pCustomer = new Customer( _name, _phone );

	m_customers[ _name ] = std::unique_ptr< Customer >( pCustomer );
}


/*****************************************************************************/


Customer * 
ServiceProvider::findCustomer ( std::string const & _name ) const
{
	auto it = m_customers.find( _name );
	return ( it == m_customers.end() ) ? nullptr : it->second.get();
}


/*****************************************************************************/


void 
ServiceProvider::notifyVIPCustomers ( std::string const & _body ) const
{
	for ( VIPCustomer * pVIPCustomer : m_vipCustomers )
		SMSHub::sendSMS(
				pVIPCustomer->getPhone()
			,	"Dear " + pVIPCustomer->getName() + ", " + _body
		);
}


/*****************************************************************************/
