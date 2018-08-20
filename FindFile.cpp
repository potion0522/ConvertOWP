#include "FindFile.h"
#include <Windows.h>
#include <errno.h>
#include <assert.h>

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

	bool file_not_found = ( handle != INVALID_HANDLE_VALUE );
	if ( !file_not_found ) {
		error( path, "not found" );
	}
	assert( file_not_found );

	do {
		std::string name = find.cFileName;
		if ( ( find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) &&
			 name != "." && name != ".." ) {
			// directory 再起
			findFile( path + name );
		}

		// 拡張子を確認
		if ( name.find( EXTENSION ) != std::string::npos ) {
			// ファイル名を保存
			_file.push_back( path + name );
		}

	} while ( FindNextFile( handle, &find ) );
}

void FindFile::error( std::string error, std::string message ) {
	FILE *fp;
	fopen_s( &fp, "error.txt", "w" );
	fprintf_s( fp, "[ %s ] is %s", error.c_str( ), message.c_str( ) );

	fclose( fp );
}

int FindFile::getFileNum( ) const {
	return ( int )_file.size( );
}

std::string FindFile::getFileName( int idx ) const {
	return _file[ idx ];
}