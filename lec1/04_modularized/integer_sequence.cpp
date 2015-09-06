// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "integer_sequence.hpp"
#include <iostream>

/*****************************************************************************/


// ������� ������������� ������������������
void IntegerSequenceInit ( IntegerSequence & s, int nAllocated )
{
	s.m_nUsed = 0;
	s.m_nAllocated = nAllocated;
	s.m_pData = new int[ s.m_nAllocated ];
}


/*****************************************************************************/


// ������� ������������ ������������������
void IntegerSequenceDestroy ( IntegerSequence & s )
{
	delete[] s.m_pData;
}


/*****************************************************************************/


// ������� ���������� ������ ������ ������������������ ����� � ��������� ������
void IntegerSequenceGrow ( IntegerSequence & s )
{
	// ������ ������ �������� ���������. �������� ����� ������� ������
	int newAllocated = s.m_nAllocated << 1;
	int * pTemp = new int[ newAllocated ];

	// �������� ������ �� �������� ������� � �����.
	memcpy( pTemp, s.m_pData, sizeof( int ) * s.m_nUsed );

	// ����������� ������� ����
	delete[] s.m_pData;

	// ��������� ��������� �� ���� � ������ � ������� �� �����
	s.m_pData = pTemp;
	s.m_nAllocated = newAllocated;
}


/*****************************************************************************/


// ������� ���������� �������� � ����� ������������������
void IntegerSequencePushBack ( IntegerSequence & s, int value )
{
	// ������ �� ������ �������� ����������� ������ ������?
	if ( s.m_nAllocated == s.m_nUsed )
		// ����������� ����� ����� �����
		IntegerSequenceGrow ( s );

	// � ������ ����� ����� ��� �������� ����������.
	// �������� ����� ������ � ������ � ����������� ������� ���������� ���������
	s.m_pData[ s.m_nUsed++ ] = value;
}


/*****************************************************************************/


// ������� ����� ������������������
void IntegerSequenceReadTillZero ( IntegerSequence & s )
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
		IntegerSequencePushBack( s, value );
	}
}


/*****************************************************************************/


// ������� �������� ����� ������������������ �����
int IntegerSequenceAccumulate ( const IntegerSequence & s )
{
	int sum = 0;
	for ( int i = 0; i < s.m_nUsed; i++ )
		sum += s.m_pData[ i ];

	return sum;
}


/*****************************************************************************/
