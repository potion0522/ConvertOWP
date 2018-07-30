#pragma once

class Task {
public:
	Task( ) { };
	virtual ~Task( ) { };

public:
	virtual void finalize( ) { };
	virtual void initialize( ) { };
	virtual void update( ) = 0;
};

