#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_

//************************************************************************

#include "scolarship.hpp"

#include <memory>

//************************************************************************


class Student
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Student ( std::string const & _name );

	std::string const & getName () const;

	bool hasScolarship () const;

	Scolarship const & getScolarship () const;

	void assignScolarship ( std::unique_ptr< Scolarship > _scolarship );

	void scolarshipRulesViolated ();

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

    std::string m_name;

    std::unique_ptr< Scolarship > m_scolarship;

/*-----------------------------------------------------------------*/

};

//************************************************************************


inline std::string const & 
Student::getName () const 
{ 
	return m_name; 
}


//************************************************************************


#endif //  _STUDENT_HPP_
