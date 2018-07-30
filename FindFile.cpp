#include "FindFile.h"
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

int FindFile::getFileNum( ) const {
	return ( int )_file.size( );
}

std::string FindFile::getFileName( int idx ) const {
	return _file[ idx ];
}