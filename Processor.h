#pragma once
#include "Phase.h"
#include "Task.h"
#include <memory>
#include <string>

class Processor : public Task {
public:
	static std::shared_ptr< class Processor > getTask( );
	static std::string getTag( ) { return "PROCESSOR"; }

public:
	Processor( );
	virtual ~Processor( );

public:
	void initialize( );
	void update( );

private:
	void changePhase( );

private:
	std::shared_ptr< class Phase > _phase;
	std::shared_ptr< class FindFile > _find_file;
};

