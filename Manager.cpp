#include "Manager.h"

Manager::Manager( ) :
_fin( false ) {
	_processor = std::shared_ptr< class Processor >( new Processor );
}

Manager::~Manager( ) {
}

void Manager::update( ) {
	_processor->update( );

	if ( _processor->isFin( ) ) {
		_fin = true;
	}
}

bool Manager::isFin( ) const {
	return _fin;
}