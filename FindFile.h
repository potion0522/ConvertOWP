#pragma once
#include <vector>
#include <string>

class FindFile {
public:
	FindFile( );
	virtual ~FindFile( );

public:
	void load( );

private:
	void findFile( std::string path );

public:
	int getFileNum( ) const;
	std::string getFileName( int idx ) const;

private:
	std::vector< std::string > _file;
};

