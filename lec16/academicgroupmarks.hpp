// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ACADEMICGROUPMARKS_HPP_
#define _ACADEMICGROUPMARKS_HPP_

/*****************************************************************************/

#include "marksystem.hpp"

#include <map>
#include <string>
#include <memory>

/*****************************************************************************/


class AcademicGroupMarks
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

    AcademicGroupMarks ( std::unique_ptr< MarkSystem > _markSystem );

    void trackStudentMark ( const std::string & _studentFullname, int _mark );

    double getScolarshipPercentage () const;

    int getFailedStudentsCount () const;

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

    typedef std::map< std::string, int > StudentMarks;
    StudentMarks m_studentMarks;

    std::unique_ptr< MarkSystem > m_markSystem;

/*-----------------------------------------------------------------*/

};

//*****************************************************************************

#endif //  _ACADEMICGROUPMARKS_HPP_

