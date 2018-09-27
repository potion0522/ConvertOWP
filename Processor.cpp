#include "Processor.h"
#include "FindFile.h"
#include "PhaseCommandCheck.h"
#include "PhaseFileRead.h"
#include "PhaseFileWrite.h"

#include "Application.h"

std::shared_ptr< class Processor > Processor::getTask( ) {
	return std::dynamic_pointer_cast< Processor >( Application::getInstance( )->getTask( getTag( ) ) );
}

Processor::Processor( ) {
}

Processor::~Processor( ) {
}

void Processor::initialize( ) {
	_find_file = std::shared_ptr< class FindFile >( new FindFile );
	_phase = std::shared_ptr< class Phase >( new PhaseCommandCheck( _find_file ) );
}

void Processor::update( ) {
	_phase->update( );

	if ( _phase->getNextPhase( ) != Phase::PHASE_CONTINUE ) {
		changePhase( );
	}
}

void Processor::changePhase( ) {
	switch ( _phase->getNextPhase( ) ) {
	case Phase::PHASE_COMMAND_CHECK:
		_phase = std::shared_ptr< class Phase >( new PhaseCommandCheck( _find_file ) );
		break;

	case Phase::PHASE_FILE_READ:
		_phase = std::shared_ptr< class Phase >( new PhaseFileRead( _find_file ) );
		break;

	case Phase::PHASE_FILE_WRITE: {
			std::shared_ptr< class PhaseFileRead > read = std::dynamic_pointer_cast< PhaseFileRead >( _phase );
			_phase = std::shared_ptr< class Phase >( new PhaseFileWrite( read->getFileRef( ) ) );
		} break;

	case Phase::PHASE_END:
		std::shared_ptr< class Application > app = Application::getInstance( );
		app->fin( );
		break;
	}
}