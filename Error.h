#pragma once
#include "Task.h"
#include <vector>
#include <memory>
#include <string>

class Error : public Task {
public:
	static std::shared_ptr< Error > getTask( );
	static std::string getTag( ) { return "ERROR"; }

public:
	Error( );
	virtual ~Error( );

public:
	void update( ) { }
	void addErrorLog( std::string error_message );
};

