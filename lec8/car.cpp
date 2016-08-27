// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "car.hpp"

/*****************************************************************************/


Car::Car ( const std::string & _model, float _engineHorsePower  )
	:	m_engine( _engineHorsePower ),
		m_model( _model )
{}


/*****************************************************************************/


void Car::describe ( std::ostream & _o ) const
{
	_o  << "Model: " << getModel()
		<< ", horse power: " << m_engine.getHorsePower()
		<< std::endl;
}


/*****************************************************************************/

