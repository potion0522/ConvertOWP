#pragma once
#include "Phase.h"
#include <memory>
#include <vector>

class PhaseFileWrite : public Phase {
public:
	PhaseFileWrite( std::vector< std::shared_ptr< class File > > &file );
	virtual ~PhaseFileWrite( );

public:
	void update( );

private:
	void writeFile( std::shared_ptr< class File > file );

private:
	std::vector< std::shared_ptr< class File > > _file;
};

