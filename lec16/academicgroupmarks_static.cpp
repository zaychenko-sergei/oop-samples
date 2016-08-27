// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "academicgroupmarks_static.hpp"

#include "bolognamarksystem_static.hpp"
#include "sovietmarksystem_static.hpp"

/*****************************************************************************/


template< typename _MarkSystem >
void AcademicGroupMarks< _MarkSystem >::trackStudentMark ( 
        const std::string & _studentFullname
    ,   int _mark 
)
{
    if ( _MarkSystem::isValidMark( _mark ) )
        m_studentMarks[ _studentFullname ] = _mark;

    else
        throw std::logic_error( "Invalid student mark was specified" );
}


/*****************************************************************************/


template< typename _MarkSystem >
double AcademicGroupMarks< _MarkSystem >::getScolarshipPercentage () const
{
    int nStudentsWithScolarship = 0;
        
    auto itMarks = m_studentMarks.begin();
    while ( itMarks != m_studentMarks.end() )
    {
        int mark = itMarks->second;

		if ( _MarkSystem::analyzeMark( mark ) == MarkConclusion::Pass_WithScolarship )
            ++ nStudentsWithScolarship;

        ++ itMarks;
    }

    return static_cast< double >( nStudentsWithScolarship ) /
           static_cast< double >( m_studentMarks.size() ) * 100.0;
}


/*****************************************************************************/


template< typename _MarkSystem >
int AcademicGroupMarks< _MarkSystem >::getFailedStudentsCount () const
{
    int nFailed = 0;

    auto itMarks = m_studentMarks.begin();
    while ( itMarks != m_studentMarks.end() )
    {
        int mark = itMarks->second;

        if ( _MarkSystem::analyzeMark( mark ) == MarkConclusion::Fail )
            ++ nFailed;

        ++ itMarks;
    }

    return nFailed;
}


/*****************************************************************************/

template class AcademicGroupMarks< SovietMarkSystem >;
template class AcademicGroupMarks< BolognaMarkSystem >;

/*****************************************************************************/

