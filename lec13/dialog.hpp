// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _DIALOG_HPP_
#define _DIALOG_HPP_

/*****************************************************************************/

#include "window.hpp"
#include "button.hpp"

/*****************************************************************************/


class Dialog
	:	public Window
	,	protected Button::ClickHandler
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Dialog ( const std::string & _title );

	bool getResult () const;

	void draw () override;

	Button & getOKButton ();

	Button & getCancelButton ();

/*-----------------------------------------------------------------*/

protected:

/*-----------------------------------------------------------------*/

	void onClicked ( Button & _b ) override;


/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	Button m_okButton;
	Button m_cancelButton;

	bool m_result;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


inline bool
Dialog::getResult () const
{
	return m_result;
}


/*****************************************************************************/


inline Button &
Dialog::getOKButton ()
{
	return m_okButton;
}


/*****************************************************************************/


inline Button &
Dialog::getCancelButton ()
{
	return m_cancelButton;
}


/*****************************************************************************/

#endif //  _DIALOG_HPP_
