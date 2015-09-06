// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

// ����� ���������
#ifndef _INTEGER_SEQUENCE_HPP_
#define _INTEGER_SEQUENCE_HPP_

/*****************************************************************************/


// ��������� ��� ������������������
struct IntegerSequence
{
	int * m_pData;
	int m_nAllocated;
	int m_nUsed;
};


// ������� ������������� ������������������
void IntegerSequenceInit ( IntegerSequence & s, int nAllocated = 10 );

// ������� ������������ ������������������
void IntegerSequenceDestroy ( IntegerSequence & s );

// ������� ���������� �������� � ����� ������������������
void IntegerSequencePushBack ( IntegerSequence & s, int value );

// ������� ����� ������������������
void IntegerSequenceReadTillZero ( IntegerSequence & s );

// ������� �������� ����� ������������������ �����
int IntegerSequenceAccumulate ( const IntegerSequence & s );


/*****************************************************************************/

// ����� ������ ���������
#endif // _INTEGER_SEQUENCE_HPP_