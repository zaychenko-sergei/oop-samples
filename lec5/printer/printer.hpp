// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _PRINTER_HPP_
#define _PRINTER_HPP_

/*****************************************************************************/


class Printer
{

/*-----------------------------------------------------------------*/

	// ����������� ����������-����, ������ ��������� �� ��������� ������-��������
	static Printer * ms_Instance;

/*-----------------------------------------------------------------*/

	// �������� ����������� �� ���������
	Printer ();

	// �������� ����������
	~Printer ();

/*-----------------------------------------------------------------*/

public:

	// ����������� ����� ������� � �������-��������
	static Printer * GetInstance ();

	// ��������� ����������� ����� � �������� ���������� (���������� �� �����)
	Printer ( const Printer & ) = delete;
	Printer& operator = ( const Printer & ) = delete;

	// ������� �������� �����
	void Print ( const char * _filePath );

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/


#endif // _PRINTER_HPP_
