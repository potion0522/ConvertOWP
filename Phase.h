#pragma once

class Phase {
public:
	Phase( ) { };
	virtual ~Phase( ) { };

public:
	virtual void update( ) = 0;
};

