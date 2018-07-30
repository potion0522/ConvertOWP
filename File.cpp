#include "File.h"

File::File( ) {
}

File::~File( ) {
}

void File::setName( std::string name ) {
	_name = name;
}

int File::getSize( ) const {
	return ( int )_data.size( );
}

std::string File::getName( ) const {
	return _name;
}

std::string File::getConvertName( ) const {
	std::string name = _name;
	// �g���q��ς���
	int pos = ( int )name.find_last_of( '.' );
	name = name.substr( 0, pos );
	name += ".ogg";

	// �t�@�C���������ɂ���
	pos = ( int )name.find_last_of( '/' );
	name = name.substr( pos + 1, name.length( ) - pos - 1 );

	return name;
}

File::ReadData File::getData( int idx ) const {
	return _data[ idx ];
}
