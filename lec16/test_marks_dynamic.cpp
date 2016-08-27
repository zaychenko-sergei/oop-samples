// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "academicgroupmarks.hpp"
#include "sovietmarksystem.hpp"
#include "bolognamarksystem.hpp"

#include <iostream>

/*****************************************************************************/


int main ()
{
    AcademicGroupMarks marks1( std::unique_ptr< MarkSystem >( new SovietMarkSystem() ) );
    marks1.trackStudentMark( "Ivanov",  2 );
    marks1.trackStudentMark( "Petrov",  3 );
    marks1.trackStudentMark( "Sidorov", 4 );
    marks1.trackStudentMark( "Fedorov", 5 );

    AcademicGroupMarks marks2( std::unique_ptr< MarkSystem >( new BolognaMarkSystem() ) );
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


