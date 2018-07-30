#pragma once
#include <string>
#include <vector>

class File {
public:
	static const int BUF_SIZE = 0xffff;

private:
	struct ReadData {
		int read_size;
		unsigned char data[ BUF_SIZE ];
	};

public:
	File( );
	virtual ~File( );

public:
	void setName( std::string name );
	void addData( unsigned char *buf, int size ) {
		ReadData read_data = ReadData( );
		read_data.read_size = size;

		for ( int i = 0; i < size; i++ ) {
			read_data.data[ i ] = *( buf + i );
		}

		_data.push_back( read_data );
	}

public:
	int getSize( ) const; 
	std::string getName( ) const;
	std::string getConvertName( ) const;
	ReadData getData( int idx ) const;

private:
	std::string _name;
	std::vector< ReadData > _data;
};

