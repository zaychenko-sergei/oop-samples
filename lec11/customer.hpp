// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _CUSTOMER_HPP_
#define _CUSTOMER_HPP_

/*****************************************************************************/

#include "account.hpp"

/*****************************************************************************/


class Customer
	:	public Account
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Customer (
			const std::string & _fullName
		,	const std::string & _email
		,	unsigned int _passwordHash
		,	float _totalPurchasesSum
	);

	float getTotalPurchaseSum () const;

	float getDiscountPercent () const;

	void purchase ( float _sum, const std::string & _password );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	void updateDiscountPercent ();

/*-----------------------------------------------------------------*/

	static const float DISCOUNT_LIMIT_STEP;

	static const float MAX_DISCOUNT_PERCENT;

	float m_discountPercent;

	float m_totalPurchaseSum;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline float
Customer::getTotalPurchaseSum () const
{
	return m_totalPurchaseSum;
}


/*****************************************************************************/


inline float
Customer::getDiscountPercent () const
{
	return m_discountPercent;
}


/*****************************************************************************/

#endif //  _CUSTOMER_HPP_
