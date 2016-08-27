// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _HELICOPTER_ESCADRILLE_HPP_
#define _HELICOPTER_ESCADRILLE_HPP_

/*****************************************************************************/

class Helicopter;

/*****************************************************************************/


class HelicopterEscadrille
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	HelicopterEscadrille ( int _nMaxUnits );

	HelicopterEscadrille ( const HelicopterEscadrille & ) = delete;
	HelicopterEscadrille & operator = ( const HelicopterEscadrille & ) = delete;

	~HelicopterEscadrille ();

	int getMaxUnitsCount () const;

	int getJoinedUnitsCount () const;

	Helicopter * getHelicopter ( int _index ) const;

	int findHelicopter ( const Helicopter & _helicopter ) const;

	void join ( Helicopter & _helicopter );

	void leave ( Helicopter & _helicopter );

	void onUnitDestroyed ( Helicopter * _pHelicopter );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	int findFreeUnitPosition () const;

/*-----------------------------------------------------------------*/

	const int m_nMaxUnits;

	Helicopter ** m_pUnits;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline int
HelicopterEscadrille::getMaxUnitsCount () const
{
	return m_nMaxUnits;
}


/*****************************************************************************/

#endif // _HELICOPTER_ESCADRILLE_HPP_
