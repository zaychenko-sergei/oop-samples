// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "academicgroupmarks.hpp"

/*****************************************************************************/


AcademicGroupMarks::AcademicGroupMarks ( std::unique_ptr< MarkSystem > _markSystem )
    :    m_markSystem( std::move( _markSystem ) )
{}
 

/*****************************************************************************/


void AcademicGroupMarks::trackStudentMark ( 
        const std::string & _studentFullname
    ,   int _mark 
)
{
    if ( m_markSystem->isValidMark( _mark ) )
        m_studentMarks[ _studentFullname ] = _mark;

    else
        throw std::logic_error( "Invalid student mark was specified" );
}


/*****************************************************************************/


double AcademicGroupMarks::getScolarshipPercentage () const
{
    int nStudentsWithScolarship = 0;
        
    auto itMarks = m_studentMarks.begin();
    while ( itMarks != m_studentMarks.end() )
    {
        int mark = itMarks->second;

        if ( m_markSystem->analyzeMark( mark ) == MarkConclusion::Pass_WithScolarship )
            ++ nStudentsWithScolarship;

        ++ itMarks;
    }

    return static_cast< double >( nStudentsWithScolarship ) /
           static_cast< double >( m_studentMarks.size() ) * 100.0;
}


/*****************************************************************************/


int AcademicGroupMarks::getFailedStudentsCount () const
{
    int nFailed = 0;

    auto itMarks = m_studentMarks.begin();
    while ( itMarks != m_studentMarks.end() )
    {
        int mark = itMarks->second;

        if ( m_markSystem->analyzeMark( mark ) == MarkConclusion::Fail )
            ++ nFailed;

        ++ itMarks;
    }

    return nFailed;
}


/*****************************************************************************/
