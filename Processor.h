#pragma once
#include <memory>
#include "Phase.h"

class Processor {
public:
	Processor( );
	virtual ~Processor( );

public:
	void update( );

private:
	void changePhase( );

public:
	bool isFin( ) const;

private:
	std::shared_ptr< class Phase > _phase;
	std::shared_ptr< class FindFile > _find_file;

	bool _fin;
};

