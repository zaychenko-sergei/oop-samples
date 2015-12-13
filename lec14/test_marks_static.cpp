// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "academicgroupmarks_static.hpp"
#include "sovietmarksystem_static.hpp"
#include "bolognamarksystem_static.hpp"

#include <iostream>

/*****************************************************************************/


int main ()
{
    AcademicGroupMarks< SovietMarkSystem > marks1;
    marks1.trackStudentMark( "Ivanov",  2 );
    marks1.trackStudentMark( "Petrov",  3 );
    marks1.trackStudentMark( "Sidorov", 4 );
    marks1.trackStudentMark( "Fedorov", 5 );

    AcademicGroupMarks< BolognaMarkSystem > marks2;
    marks2.trackStudentMark( "Ivanov",  42 );
    marks2.trackStudentMark( "Petrov",  64 );
    marks2.trackStudentMark( "Sidorov", 80 );
    marks2.trackStudentMark( "Fedorov", 94 );

    std::cout << marks1.getScolarshipPercentage() << "% "
              << marks2.getScolarshipPercentage() << "%" << std::endl;

    std::cout << marks1.getFailedStudentsCount() << ' ' 
              << marks2.getFailedStudentsCount() << ' ' << std::endl;
}


/*****************************************************************************/
