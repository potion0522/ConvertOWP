#pragma once
#include <memory>
#include "Processor.h"

class Manager {
public:
	Manager( );
	virtual ~Manager( );

public:
	void update( );
	
public:
	bool isFin( ) const;

private:
	bool _fin;

	std::shared_ptr< class Processor > _processor;
};

