// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include <iostream>

/*****************************************************************************/


// ������� ���������� ������ ������ ������������������ ����� � ��������� ������
void IntegerSequenceGrow ( int *& pData, int & nAllocated, int & nUsed )
{
	// ������ ������ �������� ���������. �������� ����� ������� ������
	int newAllocated = nAllocated << 1;
	int * pTemp = new int[ newAllocated ];

	// �������� ������ �� �������� ������� � �����.
	memcpy( pTemp, pData, sizeof( int ) * nUsed );

	// ����������� ������� ����
	delete[] pData;

	// ��������� ��������� �� ���� � ������ � ������� �� �����
	pData = pTemp;
	nAllocated = newAllocated;
}


/*****************************************************************************/


// ������� ���������� �������� � ����� ������������������
void IntegerSequencePushBack ( int *& pData, int & nAllocated, int & nUsed, int value )
{
	// ������ �� ������ �������� ����������� ������ ������?
	if ( nAllocated == nUsed )
		// ����������� ����� ����� �����
		IntegerSequenceGrow ( pData, nAllocated, nUsed );

	// � ������ ����� ����� ��� �������� ����������.
	// �������� ����� ������ � ������ � ����������� ������� ���������� ���������
	pData[ nUsed++ ] = value;
}


/*****************************************************************************/


// ������� ����� ������������������
void IntegerSequenceReadTillZero ( int *& pData, int & nAllocated, int & nUsed )
{
	// ���� �����
	while ( true )
	{
		// ������ ��������� ����� � ����������
		int value;
		std::cin >> value;

		// ���� ����� �� �������� �������������, ������� �� �����
		if ( value <= 0 )
			break;

		// �������� ����� � ����� ������������������
		IntegerSequencePushBack( pData, nAllocated, nUsed, value );
	}
}


/*****************************************************************************/


// ������� �������� ����� ������������������ �����
int IntegerSequenceAccumulate ( const int * pData, int nElements )
{
	int sum = 0;
	for ( int i = 0; i < nElements; i++ )
		sum += pData[ i ];

	return sum;
}


/*****************************************************************************/


int main ()
{
	// ������� ������ ������������������
	int nAllocated1 = 10;
	int nUsed1 = 0;
	int * pData1 = new int[ nAllocated1 ];

	// ������� ������ ������������������
	int nAllocated2 = 10;
	int nUsed2 = 0;
	int * pData2 = new int[ nAllocated2 ];

	// ������ ������������������
	IntegerSequenceReadTillZero( pData1, nAllocated1, nUsed1 );
	IntegerSequenceReadTillZero( pData2, nAllocated2, nUsed2 );

	// ������������ ����� ���������
	int sum1 = IntegerSequenceAccumulate( pData1, nUsed1 );
	int sum2 = IntegerSequenceAccumulate( pData2, nUsed2 );

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
	delete[] pData1;
	delete[] pData2;
}


/*****************************************************************************/
