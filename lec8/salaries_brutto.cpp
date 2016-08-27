#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>


int main ()
{
	typedef std::unordered_map< std::string, double > Salaries;

	Salaries salaries;
	salaries[ "Ivanov" ] = 1000.0;
	salaries[ "Petrov" ] = 1200.0;
	salaries[ "Sidorov" ] = 800.0;

	const double personalIncomeTax = 0.18;
	const double salarySocialTax = 0.22;
	const double militaryTax = 0.015;

	double totalSalaryWithTaxes = 0.0;
	std::for_each(
		salaries.cbegin(), salaries.cend(),
		[ =, &totalSalaryWithTaxes ] ( const Salaries::value_type & v )
	{
		double netto = v.second;
		double personalBrutto = netto /
			( 1.0 - personalIncomeTax - militaryTax );
		double totalBrutto = personalBrutto * ( 1 + salarySocialTax );
		totalSalaryWithTaxes += totalBrutto;
	}
	);

	std::cout << "Total salary + taxes to pay: " << totalSalaryWithTaxes << std::endl;
}
