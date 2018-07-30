#pragma once
#include <memory>
#include "Phase.h"
#include "FindFile.h"

class PhaseCommandCheck : public Phase {
public:
	PhaseCommandCheck( std::shared_ptr< class FindFile > find_file );
	virtual ~PhaseCommandCheck( );

public:
	void update( );

private:
	bool command( );

private:
	char _past_key;

	std::shared_ptr< class FindFile > _find_file;
};

