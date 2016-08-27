#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>


/*****************************************************************************/


class Employee
{

/*-----------------------------------------------------------------*/

public:


/*-----------------------------------------------------------------*/

	Employee ( const std::string & _name, int _age, double _salary )
		:    m_name( _name ),
             m_age( _age ),
            m_salary( _salary )
	{}

	const std::string & getName () const { return m_name; }

	int getAge () const { return m_age; }

	double getSalary () const { return m_salary; }

/*-----------------------------------------------------------------*/

private:


/*-----------------------------------------------------------------*/

	std::string m_name;

	int m_age;

	double m_salary;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


void printEmployees ( const std::vector< Employee * > & _employees )
{
	for ( auto it = _employees.begin(); it != _employees.end(); ++it )
		std::cout << ( *it )->getName()
		<< " age=" << ( *it )->getAge()
		<< " salary=" << ( *it )->getSalary()
		<< std::endl;
}


/*****************************************************************************/


enum class EmployeeSortMode
{
	Alphabetical,
	Salaries,
	Age
};


/*****************************************************************************/


std::function< bool ( const Employee *, const Employee * ) >
getEmployeeSortingPredicate ( EmployeeSortMode _sortMode )
{
	switch ( _sortMode )
	{
		case EmployeeSortMode::Alphabetical:
			return [] ( const Employee * _pEmployee1, const Employee * _pEmployee2 )
					  {
						  return _pEmployee1->getName() < _pEmployee2->getName();
					  };

		case EmployeeSortMode::Age:
			return [] ( const Employee * _pEmployee1, const Employee * _pEmployee2 )
					  {
						  return _pEmployee1->getAge() > _pEmployee2->getAge();
					  };

		case EmployeeSortMode::Salaries:
			return [] ( const Employee * _pEmployee1, const Employee * _pEmployee2 )
					  {
						  return _pEmployee1->getSalary() > _pEmployee2->getSalary();
					  };

		default:
			throw std::logic_error( "Unexpected sort mode" );
	}
}


/*****************************************************************************/


void sortEmployees ( std::vector< Employee * > & _employees, EmployeeSortMode _sortMode )
{
	std::sort(
		_employees.begin(),
		_employees.end(),
		getEmployeeSortingPredicate( _sortMode )
	);
}


/*****************************************************************************/


int main ()
{
	std::vector< Employee * > employees;
	employees.push_back( new Employee( "Ivanov", 25, 1000.0 ) );
	employees.push_back( new Employee( "Ivanov", 45, 2000.0 ) );
	employees.push_back( new Employee( "Petrov", 50, 750.0 ) );
	employees.push_back( new Employee( "Sidorov", 34, 1200.0 ) );

	std::cout << "===== By Age ===== " << std::endl;
	sortEmployees( employees, EmployeeSortMode::Age );
	printEmployees( employees );

	std::cout << "===== By Salary ===== " << std::endl;
	sortEmployees( employees, EmployeeSortMode::Salaries );
	printEmployees( employees );

	std::cout << "===== By Name ===== " << std::endl;
	sortEmployees( employees, EmployeeSortMode::Alphabetical );
	printEmployees( employees );

	std::for_each( employees.begin(), employees.end(), [] ( Employee * pE ) { delete pE; } );
}


/*****************************************************************************/

