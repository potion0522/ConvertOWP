#include "PhaseFileWrite.h"
#include "File.h"

const char EXPORT_DIRECTORY[ ] = "Export/";

PhaseFileWrite::PhaseFileWrite( std::vector< std::shared_ptr< class File > > &file ) :
Phase( PHASE_FILE_WRITE ),
_file( file ) {
}

PhaseFileWrite::~PhaseFileWrite( ) {
}

void PhaseFileWrite::update( ) {
	for ( std::shared_ptr< class File > file : _file ) {
		writeFile( file );
	}

	setNextPhase( PHASE_END );
}

void PhaseFileWrite::writeFile( std::shared_ptr< class File > file ) {
	FILE *fp;
	std::string path;
	path = path + EXPORT_DIRECTORY + file->getConvertName( ).c_str( );
	if ( fopen_s( &fp, path.c_str( ), "wb" ) != 0 ) {
		if ( fopen_s( &fp, ( "../" + path ).c_str( ), "wb" ) ) {
			return;
		}
	}

	const int CHANGE = 0x39;
	int size = file->getSize( );
	for ( int i = 0; i < size; i++ ) {
		int size = file->getData( i ).read_size;
		unsigned char *buf = file->getData( i ).data;

		unsigned char conv[ File::BUF_SIZE ] = { };
		for ( int j = 0; j < size; j++ ) {
			conv[ j ] = ( ( *( buf + j ) ) ^ CHANGE );
		}

		fwrite( conv, sizeof( unsigned char ), size, fp );
	}

	fclose( fp );
}