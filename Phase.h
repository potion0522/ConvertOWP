#pragma once

class Phase {
public:
	enum PHASE {
		PHASE_COMMAND_CHECK,
		PHASE_FILE_READ,
		PHASE_FILE_WRITE,
		PHASE_END,
		PHASE_MAX,
		PHASE_CONTINUE,
	};

public:
	Phase( PHASE my_phase ) :
	_run_phase( my_phase ),
	_next_phase( PHASE_CONTINUE ) {
	};

	virtual ~Phase( ) { };

public:
	virtual void update( ) = 0;

public:
	void setNextPhase( PHASE phase ) {
		_next_phase = phase;
	}

public:
	PHASE getNowPhase( ) const {
		return _run_phase;
	}

	PHASE getNextPhase( ) const {
		return _next_phase;
	}

private:
	PHASE _run_phase;
	PHASE _next_phase;
};

