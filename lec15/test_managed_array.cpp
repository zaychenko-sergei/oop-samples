// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "managed_array.hpp"

#include <iostream>

/*****************************************************************************/


int main ()
{
    try
    {
        ManagedArray a( 10 );
        for ( int i = 0; i < 10; i++ )
            a[ i ] = rand();

        int index;
        std::cout << "Input index: ";
        std::cin >> index;

        std::cout << "Array value is: " << a[ index ] << std::endl;;
    }

    catch ( ManagedArray::IndexOutOfRange & e )
    {
        std::cout << "Specified index " << e.m_violatingIndex 
                  << " is out of array range [" 
                  << e.m_minIndex << ":" << e.m_maxIndex << "]" << std::endl;
    }
}


/*****************************************************************************/
