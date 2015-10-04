// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _CAR_HPP_
#define _CAR_HPP_

/*****************************************************************************/

#include "engine.hpp"

#include <string>
#include <iostream>

/*****************************************************************************/


class Car
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Car ( const std::string & _model, float _engineHorsePower );

	const Engine & getEngine () const;

	const std::string & getModel () const;

	void describe ( std::ostream & _o ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::string m_model;

	Engine m_engine;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline const Engine & 
Car::getEngine () const
{
	return m_engine;
}


/*****************************************************************************/


inline const std::string & 
Car::getModel () const
{
	return m_model;
}


/*****************************************************************************/

#endif // _CAR_HPP_
