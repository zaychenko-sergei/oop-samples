#include <cstdio>
#include <memory>
#include <functional>

class FileDeleter
{
public:
	void operator () ( FILE * f )
	{
		fclose( f );
	}
};

int main ()
{
	std::unique_ptr< FILE, FileDeleter > pFile( fopen( "test.txt", "wt" ) );
	fprintf( pFile.get(), "Hello managed file!\n" );

	auto pFile2 = std::unique_ptr< FILE, std::function< void ( FILE * ) > >(
			fopen( "test2.txt", "wt" )
		,	[] ( FILE * f )
			{
				fclose( f );
			}
	);
	fprintf( pFile2.get(), "Hello another managed file!\n" );

	std::unique_ptr< int[] > pArray( new int[ 100 ] );
	for ( int i = 0; i < 100; i++ )
		pArray[ i ] = rand();
}