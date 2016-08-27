// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _MANAGED_ARRAY_HPP_
#define _MANAGED_ARRAY_HPP_
 
/*****************************************************************************/


class ManagedArray
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

    struct IndexOutOfRange
    {
        const int m_violatingIndex;
        const int m_minIndex;
        const int m_maxIndex;
    
        IndexOutOfRange ( int _violatingIndex, int _minIndex, int _maxIndex )
            :    m_violatingIndex( _violatingIndex )
            ,    m_minIndex( _minIndex )
            ,    m_maxIndex( _maxIndex )
        {}
    };

/*-----------------------------------------------------------------*/

    struct NonPositiveArraySize
    {
        const int m_violatingSize;

        NonPositiveArraySize ( int _violatingSize )
            :    m_violatingSize( _violatingSize )
        {}
    };

/*-----------------------------------------------------------------*/

	ManagedArray ( int _size );

	ManagedArray ( const ManagedArray & ) = delete;

	ManagedArray & operator = ( const ManagedArray & ) = delete;

	~ManagedArray ();

/*-----------------------------------------------------------------*/

	int size () const;

	int & operator[] ( int _index );

	int operator[] ( int _index ) const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	int * m_pData;

	const int m_size;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline int 
ManagedArray::size () const
{
	return m_size;
}


/*****************************************************************************/


#endif // _MANAGED_ARRAY_HPP_
