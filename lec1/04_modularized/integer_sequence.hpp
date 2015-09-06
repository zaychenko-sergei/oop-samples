// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

// Страж включения
#ifndef _INTEGER_SEQUENCE_HPP_
#define _INTEGER_SEQUENCE_HPP_

/*****************************************************************************/


// Структура для последовательности
struct IntegerSequence
{
	int * m_pData;
	int m_nAllocated;
	int m_nUsed;
};


// Функция инициализации последовательности
void IntegerSequenceInit ( IntegerSequence & s, int nAllocated = 10 );

// Функция освобождения последовательности
void IntegerSequenceDestroy ( IntegerSequence & s );

// Функция добавления значения в конец последовательности
void IntegerSequencePushBack ( IntegerSequence & s, int value );

// Функция ввода последовательности
void IntegerSequenceReadTillZero ( IntegerSequence & s );

// Функция подсчета суммы последовательности чисел
int IntegerSequenceAccumulate ( const IntegerSequence & s );


/*****************************************************************************/

// Конец стража включения
#endif // _INTEGER_SEQUENCE_HPP_