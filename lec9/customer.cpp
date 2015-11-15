// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "customer.hpp"

#include <stdexcept>

/*****************************************************************************/


const float Customer::DISCOUNT_LIMIT_STEP = 1000.0f;
const float Customer::MAX_DISCOUNT_PERCENT = 10.0f;


/*****************************************************************************/


Customer::Customer (
		const std::string & _fullName
	,	const std::string & _email
	,	unsigned int _passwordHash
	,	float _totalPurchaseSum
)
	:	Account( _fullName, _email, _passwordHash )
	,	m_totalPurchaseSum( _totalPurchaseSum )
{
	if ( m_totalPurchaseSum < 0.0f )
		throw std::logic_error( "Total cannot be negative" );

	updateDiscountPercent();
}


/*****************************************************************************/


void Customer::updateDiscountPercent ()
{
	m_discountPercent = m_totalPurchaseSum / DISCOUNT_LIMIT_STEP;

	if ( m_discountPercent > MAX_DISCOUNT_PERCENT )
		m_discountPercent = MAX_DISCOUNT_PERCENT;
}


/*****************************************************************************/


void Customer::purchase ( float _sum, const std::string & _password )
{
	if ( _sum <= 0.0 )
		throw std::logic_error( "Purchase sum must be positive" );

	if ( ! isAuthorized() )
		authorize( _password );

	m_totalPurchaseSum += _sum;
	updateDiscountPercent();
}


/*****************************************************************************/

