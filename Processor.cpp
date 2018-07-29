#include "Processor.h"
#include "PhaseActionCheck.h"

Processor::Processor( ) {
	_phase = std::shared_ptr< class Phase >( new PhaseActionCheck );
}

Processor::~Processor( ) {
}

void Processor::update( ) {
	_phase->update( );
}

bool Processor::isFin( ) const {
	return false;
}