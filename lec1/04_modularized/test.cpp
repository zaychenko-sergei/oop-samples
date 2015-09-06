// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "integer_sequence.hpp"

#include <iostream>

/*****************************************************************************/


int main ()
{
	// ��������� � �������������� 2 ������������������
	IntegerSequence s1, s2;
	IntegerSequenceInit( s1 );
	IntegerSequenceInit( s2 );

	// ������ ������������������
	IntegerSequenceReadTillZero( s1 );
	IntegerSequenceReadTillZero( s2 );

	// ������������ ����� ���������
	int sum1 = IntegerSequenceAccumulate( s1 );
	int sum2 = IntegerSequenceAccumulate( s2 );

	// ���������� ����� � ������� ���������
	if ( sum1 > sum2 )
		std::cout << "First sequence {" << sum1 <<
		"} has bigger sum than the second {" <<
		sum2 << "}" << std::endl;
	else if ( sum1 < sum2 )
		std::cout << "Second sequence {" << sum2 <<
		"} has bigger sum than the first {" <<
		sum1 << "}" << std::endl;
	else
		std::cout << "Sequences have equal sum {" << sum1 << "}" << std::endl;

	// ����������� ������� ����� �������������������
	IntegerSequenceDestroy( s1 );
	IntegerSequenceDestroy( s2 );
}


/*****************************************************************************/
