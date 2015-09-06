// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include <iostream>

/*****************************************************************************/


// Функция увеличения объема памяти последовательности вдвое с переносом данных
void IntegerSequenceGrow ( int *& pData, int & nAllocated, int & nUsed )
{
	// Предел объема хранения достигнут. Выделяем вдвое больший массив
	int newAllocated = nAllocated << 1;
	int * pTemp = new int[ newAllocated ];

	// Копируем данные из прежнего массива в новый.
	memcpy( pTemp, pData, sizeof( int ) * nUsed );

	// Освобождаем прежний блок
	delete[] pData;

	// Подменяем указатель на блок и размер в массиве на новые
	pData = pTemp;
	nAllocated = newAllocated;
}


/*****************************************************************************/


// Функция добавления значения в конец последовательности
void IntegerSequencePushBack ( int *& pData, int & nAllocated, int & nUsed, int value )
{
	// Достиг ли массив пределов выделенного объема памяти?
	if ( nAllocated == nUsed )
		// Увеличиваем объем блока вдвое
		IntegerSequenceGrow ( pData, nAllocated, nUsed );

	// В данной точке места для хранения достаточно.
	// Помещаем новое данное в массив и увеличиваем счетчик хранящихся элементов
	pData[ nUsed++ ] = value;
}


/*****************************************************************************/


// Функция ввода последовательности
void IntegerSequenceReadTillZero ( int *& pData, int & nAllocated, int & nUsed )
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
		IntegerSequencePushBack( pData, nAllocated, nUsed, value );
	}
}


/*****************************************************************************/


// Функция подсчета суммы последовательности чисел
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
	// Создаем первую последовательность
	int nAllocated1 = 10;
	int nUsed1 = 0;
	int * pData1 = new int[ nAllocated1 ];

	// Создаем вторую последовательность
	int nAllocated2 = 10;
	int nUsed2 = 0;
	int * pData2 = new int[ nAllocated2 ];

	// Вводим последовательности
	IntegerSequenceReadTillZero( pData1, nAllocated1, nUsed1 );
	IntegerSequenceReadTillZero( pData2, nAllocated2, nUsed2 );

	// Подсчитываем суммы элементов
	int sum1 = IntegerSequenceAccumulate( pData1, nUsed1 );
	int sum2 = IntegerSequenceAccumulate( pData2, nUsed2 );

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
	delete[] pData1;
	delete[] pData2;
}


/*****************************************************************************/
