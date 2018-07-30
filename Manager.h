#pragma once
#include "Task.h"
#include "Processor.h"
#include <memory>
#include <string>

class Manager : public Task {
public:
	static std::shared_ptr< class Manager > getTask( );
	static std::string getTag( ) { return "MANAGER"; }

public:
	Manager( );
	virtual ~Manager( );

public:
	void update( );

private:
	std::shared_ptr< class Processor > _processor;
};

