#include "FindFile.h"

#include "Error.h"
#include <Windows.h>

const char DIRECTORY[ ] = "Target";
const char EXTENSION[ ] = ".owp";

FindFile::FindFile( ) {
}

FindFile::~FindFile( ) {
}

void FindFile::load( ) {
	findFile( DIRECTORY );
}

void FindFile::findFile( std::string path ) {
	HANDLE handle = HANDLE( );
	WIN32_FIND_DATA find = WIN32_FIND_DATA( );
	
	path += '/';
	handle = FindFirstFile( ( path + '*' ).c_str( ), &find );

	bool file_not_found = ( handle == INVALID_HANDLE_VALUE );
	if ( file_not_found ) {
		std::string error;
		error += "[ " + path + " ] ";
		error += "�������̃t�H���_�[��������܂���";
		Error::getTask( )->addErrorLog( error );
	}

	do {
		std::string name = find.cFileName;
		if ( ( find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) &&
			 name != "." && name != ".." ) {
			// directory �ċN
			findFile( path + name );
		}

		// �g���q���m�F
		if ( name.find( EXTENSION ) != std::string::npos ) {
			// �t�@�C������ۑ�
			_file.push_back( path + name );
		}

	} while ( FindNextFile( handle, &find ) );
}

int FindFile::getFileNum( ) const {
	return ( int )_file.size( );
}

std::string FindFile::getFileName( int idx ) const {
	return _file[ idx ];
}