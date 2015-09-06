// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "integer_sequence.hpp"
#include <iostream>

/*****************************************************************************/


// Функция инициализации последовательности
void IntegerSequenceInit ( IntegerSequence & s, int nAllocated )
{
	s.m_nUsed = 0;
	s.m_nAllocated = nAllocated;
	s.m_pData = new int[ s.m_nAllocated ];
}


/*****************************************************************************/


// Функция освобождения последовательности
void IntegerSequenceDestroy ( IntegerSequence & s )
{
	delete[] s.m_pData;
}


/*****************************************************************************/


// Функция увеличения объема памяти последовательности вдвое с переносом данных
void IntegerSequenceGrow ( IntegerSequence & s )
{
	// Предел объема хранения достигнут. Выделяем вдвое больший массив
	int newAllocated = s.m_nAllocated << 1;
	int * pTemp = new int[ newAllocated ];

	// Копируем данные из прежнего массива в новый.
	memcpy( pTemp, s.m_pData, sizeof( int ) * s.m_nUsed );

	// Освобождаем прежний блок
	delete[] s.m_pData;

	// Подменяем указатель на блок и размер в массиве на новые
	s.m_pData = pTemp;
	s.m_nAllocated = newAllocated;
}


/*****************************************************************************/


// Функция добавления значения в конец последовательности
void IntegerSequencePushBack ( IntegerSequence & s, int value )
{
	// Достиг ли массив пределов выделенного объема памяти?
	if ( s.m_nAllocated == s.m_nUsed )
		// Увеличиваем объем блока вдвое
		IntegerSequenceGrow ( s );

	// В данной точке места для хранения достаточно.
	// Помещаем новое данное в массив и увеличиваем счетчик хранящихся элементов
	s.m_pData[ s.m_nUsed++ ] = value;
}


/*****************************************************************************/


// Функция ввода последовательности
void IntegerSequenceReadTillZero ( IntegerSequence & s )
{
	// Цикл ввода
	while ( true )
	{
		// Вводим очередное число с клавиатуры
		int value;
		std::cin >> value;

		// Если число не является положительным, выходим из цикла
		if ( value <= 0 )
			break;

		// Помещаем число в конец последовательности
		IntegerSequencePushBack( s, value );
	}
}


/*****************************************************************************/


// Функция подсчета суммы последовательности чисел
int IntegerSequenceAccumulate ( const IntegerSequence & s )
{
	int sum = 0;
	for ( int i = 0; i < s.m_nUsed; i++ )
		sum += s.m_pData[ i ];

	return sum;
}


/*****************************************************************************/
