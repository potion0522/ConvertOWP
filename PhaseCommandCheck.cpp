#include "PhaseCommandCheck.h"
#include "Keyboard.h"

const char ENTER = 0x0d;
const char YES = 'y';

PhaseCommandCheck::PhaseCommandCheck( std::shared_ptr< class FindFile > find_file ) :
Phase( PHASE_COMMAND_CHECK ),
_find_file( find_file ),
_past_key( '\0' ) {
	_find_file->load( );
}

PhaseCommandCheck::~PhaseCommandCheck( ) {
}

void PhaseCommandCheck::update( ) {
	std::shared_ptr< class Keyboard > keyboard = Keyboard::getTask( );
	char key = keyboard->getKey( );

	if ( key == '\0' ) {
		return;
	}

	if ( key == ENTER ) {
		if ( !command( ) ) {
		}
	}

	_past_key = key;
}

bool PhaseCommandCheck::command( ) {
	if ( _past_key != YES ) {
		return false;
	}

	if ( _find_file->getFileNum( ) < 1 ) {
		return false;	
	}

	setNextPhase( PHASE_FILE_READ );
	return true;
}