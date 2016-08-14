#ifndef _FLIGHTHJOURNAL_V2_HPP_
#define _FLIGHTHJOURNAL_V2_HPP_

//************************************************************************

#include "point3d.hpp"
#include <vector>

//************************************************************************

class Helicopter;

//************************************************************************

class FlightJournalV2
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

    FlightJournalV2 ( const Helicopter & _helicopter );

    const Helicopter & getHelicopter () const;

    int getPositionsCount () const;

    Point3D getPosition ( int _index ) const;

    void trackPosition ();

    double totalDistance () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

    const Helicopter & m_helicopter;

    std::vector< Point3D > m_positions;

/*-----------------------------------------------------------------*/

};

//************************************************************************


inline const Helicopter &
FlightJournalV2::getHelicopter () const
{
    return m_helicopter;
}


//************************************************************************


inline int
FlightJournalV2::getPositionsCount () const
{
    return m_positions.size();
}


//************************************************************************

#endif // _FLIGHTHJOURNAL_V2_HPP_
