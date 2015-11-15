// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _HELICOPTER_ESCADRILLE_HPP_
#define _HELICOPTER_ESCADRILLE_HPP_

/*****************************************************************************/

#include <vector>

/*****************************************************************************/

class Helicopter;

/*****************************************************************************/


class HelicopterEscadrille
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	HelicopterEscadrille () = default;

	HelicopterEscadrille ( const HelicopterEscadrille & ) = delete;
	HelicopterEscadrille & operator = ( const HelicopterEscadrille & ) = delete;

	~HelicopterEscadrille ();

	int getJoinedUnitsCount () const;

	Helicopter & getHelicopter ( int _index ) const;

	int findHelicopter ( const Helicopter & _helicopter ) const;

	void join ( Helicopter * _pHelicopter );

	void leave ( Helicopter & _helicopter );

	void onUnitDestroyed ( Helicopter * _pHelicopter );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::vector< Helicopter * > m_helicopters;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline int 
HelicopterEscadrille::getJoinedUnitsCount () const
{
	return m_helicopters.size();
}


/*****************************************************************************/


#endif // _HELICOPTER_ESCADRILLE_HPP_
