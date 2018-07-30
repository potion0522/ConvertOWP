#include "PhaseFileRead.h"
#include "FindFile.h"
#include "File.h"

PhaseFileRead::PhaseFileRead( std::shared_ptr< const class FindFile > find_file ) :
Phase( PHASE_FILE_READ ),
_find_file( find_file ) {
}

PhaseFileRead::~PhaseFileRead( ) {
}

void PhaseFileRead::update( ) {
	int size = _find_file->getFileNum( );

	for ( int i = 0; i < size; i++ ) {
		readFile( i );
	}

	setNextPhase( PHASE_FILE_WRITE );
}

void PhaseFileRead::readFile( int read_idx ) {

	std::shared_ptr< class File > file( new File( ) );
	std::string file_name = _find_file->getFileName( read_idx );

	file->setName( file_name );
	FILE *fp;
	if ( fopen_s( &fp, file_name.c_str( ), "rb" ) != 0 ) {
		return;
	}

	unsigned char buf[ File::BUF_SIZE ] = { };
	while ( true ) {
		int size = ( int )fread_s( buf, File::BUF_SIZE, sizeof( unsigned char ), File::BUF_SIZE, fp );
		if ( size == 0 ) {
			break;
		}

		file->addData( buf, size );
		memset( buf, 0, File::BUF_SIZE );
	}

	_file.push_back( file );
	fclose( fp );
}

std::vector< std::shared_ptr< class File > > &PhaseFileRead::getFileRef( ) {
	return _file;
}
