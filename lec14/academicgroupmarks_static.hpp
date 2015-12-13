// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ACADEMICGROUPMARKS_STATIC_HPP_
#define _ACADEMICGROUPMARKS_STATIC_HPP_

/*****************************************************************************/

#include <map>
#include <string>

/*****************************************************************************/


template< typename _MarkSystem >
class AcademicGroupMarks
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

    void trackStudentMark ( const std::string & _studentFullname, int _mark );

    double getScolarshipPercentage () const;

    int getFailedStudentsCount () const;

/*-----------------------------------------------------------------*/
	
private:

/*-----------------------------------------------------------------*/

    typedef std::map< std::string, int > StudentMarks;
    StudentMarks m_studentMarks;

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/

#endif //  _ACADEMICGROUPMARKS_STATIC_HPP_
