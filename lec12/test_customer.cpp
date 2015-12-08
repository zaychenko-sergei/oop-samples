// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "serviceprovider.hpp"

/*****************************************************************************/


int main ()
{
	ServiceProvider provider;
	provider.addCustomer( "Ivan",  "12345", false );
	provider.addCustomer( "Petr",  "23456", true );
	provider.addCustomer( "Sidor", "34567", false );
	provider.addCustomer( "Fedor", "45678", true );
	provider.addCustomer( "Wasya", "56789", false );

	provider.notifyVIPCustomers( "don't miss our latest promotion!" );
}


/*****************************************************************************/
