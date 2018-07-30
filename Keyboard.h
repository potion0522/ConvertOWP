#pragma once
#include "Task.h"
#include <memory>
#include <string>

class Keyboard : public Task {
public:
	static std::shared_ptr< class Keyboard > getTask( );
	static std::string getTag( ) { return "KEYBOARD"; }

public:
	Keyboard( );
	virtual ~Keyboard( );

public:
	void update( );

public:
	char getKey( ) const;

private:
	char _key;
};

