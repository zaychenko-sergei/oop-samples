// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _POWEREDDEVICE_HPP_
#define _POWEREDDEVICE_HPP_

/*****************************************************************************/


class PoweredDevice
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	PoweredDevice ( const PoweredDevice & ) = delete;

	PoweredDevice & operator = ( const PoweredDevice & ) = delete;

	virtual ~PoweredDevice () = default;
	
/*-----------------------------------------------------------------*/

	int getNominalPower () const;

	bool isTurned () const;

	void turnOn ();

	void turnOff ();

/*-----------------------------------------------------------------*/

protected:

/*-----------------------------------------------------------------*/

	PoweredDevice ( int _nominalPower );

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	const int m_nominalPower;

	bool m_turned;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/


inline int 
PoweredDevice::getNominalPower () const 
{
    return m_nominalPower; 
}


/*****************************************************************************/


inline bool
PoweredDevice::isTurned () const
{
    return m_turned;
}


/*****************************************************************************/

#endif //  _POWEREDDEVICE_HPP_

