//************************************************************************

#include "serveradministrator.hpp"

/*****************************************************************************/


ServerAdministrator::ServerAdministrator (
		const std::string & _fullName
	,	const std::string & _email
	,	unsigned int _passwordHash
)
	:	Account( _fullName, _email, _passwordHash )
{
}


/*****************************************************************************/



void ServerAdministrator::restartServer ( const std::string & _password )
{
	if ( ! isAuthorized() )
		authorize( _password );

	// Restart the machine ...

	clearAuthorization();
}


/*****************************************************************************/


// ���������� ������ ������� ����������� �������
void ServerAdministrator::runServerDiagnostics ( const std::string & _password )
{
	if ( !isAuthorized() )
		authorize( _password );

	// Run diagnostic procedures ...
}


/*****************************************************************************/
