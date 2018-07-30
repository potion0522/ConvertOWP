#pragma once
#include "Phase.h"
#include <memory>
#include <vector>
#include <string>

class PhaseFileRead : public Phase {
public:
	PhaseFileRead( std::shared_ptr< const class FindFile > find_file );
	virtual ~PhaseFileRead( );

public:
	void update( );

private:
	void readFile( int read_idx );

public:
	std::vector< std::shared_ptr< class File > > &getFileRef( );

private:
	std::vector< std::shared_ptr< class File > > _file;
	std::shared_ptr< const class FindFile > _find_file;
};

