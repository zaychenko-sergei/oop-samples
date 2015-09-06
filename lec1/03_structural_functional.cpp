// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include <iostream>

/*****************************************************************************/


// Структура для последовательности
struct IntegerSequence
{
	int * m_pData;
	int m_nAllocated;
	int m_nUsed;
};


/*****************************************************************************/


// Функция инициализации последовательности
void IntegerSequenceInit ( IntegerSequence & s, int nAllocated = 10 )
{
	s.m_nUsed = 0;
	s.m_nAllocated = nAllocated;
	s.m_pData = new int[ s.m_nAllocated ];
}


/*****************************************************************************/


// Функция уничтожения последовательности
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


int main ()
{
	IntegerSequence s1, s2;
	IntegerSequenceInit( s1 );
	IntegerSequenceInit( s2 );

	// Вводим последовательности
	IntegerSequenceReadTillZero( s1 );
	IntegerSequenceReadTillZero( s2 );

	// Подсчитываем суммы элементов
	int sum1 = IntegerSequenceAccumulate( s1 );
	int sum2 = IntegerSequenceAccumulate( s2 );

	// Сравниваем суммы и выводим результат
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

	// Освобождаем ресурсы обеих последовательностей
	IntegerSequenceDestroy( s1 );
	IntegerSequenceDestroy( s2 );
}


/*****************************************************************************/
