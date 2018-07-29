#pragma once
#include <memory>
#include "Phase.h"

class Processor {
public:
	enum PHASE {
		PHASE_WAIT,
		PHASE_FILE_READ,
		PAHSE_FILE_WRITE,
		PHASE_END,
		PHASE_MAX
	};

public:
	Processor( );
	virtual ~Processor( );

public:
	void update( );

public:
	bool isFin( ) const;

private:
	std::shared_ptr< class Phase > _phase;
};

