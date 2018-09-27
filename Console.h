#pragma once
#include <string>
#include <memory>
#include "Task.h"

class Console : public Task {
public:
	static std::shared_ptr< class Console > getTask( );
	static std::string getTag( ) { return "CONSOLE"; }

public:
	Console( );
	virtual ~Console( );

public:
	void update( );
};

