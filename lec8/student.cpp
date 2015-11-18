// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "student.hpp"

/*****************************************************************************/


Student::Student ( std::string const & _name )
	:	m_name( _name )
{}


/*****************************************************************************/


bool Student::hasScolarship () const
{
	return m_scolarship.get() != nullptr;
}


/*****************************************************************************/


Scolarship const & Student::getScolarship () const
{
	if ( hasScolarship() )
		return * m_scolarship;

	else
		throw std::logic_error( "Student has no scolarship" );
}


/*****************************************************************************/


void
Student::assignScolarship ( std::unique_ptr< Scolarship > _scolarship )
{
	m_scolarship = std::move( _scolarship );
}


/*****************************************************************************/


void 
Student::scolarshipRulesViolated ()
{
	m_scolarship.reset();
}


/*****************************************************************************/
