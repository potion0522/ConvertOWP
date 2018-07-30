#include "Manager.h"
#include "Application.h"

std::shared_ptr< class Manager > Manager::getTask( ) {
	return std::dynamic_pointer_cast< Manager >( Application::getInstance( )->getTask( getTag( ) ) );
}

Manager::Manager( ) {
	_processor = std::shared_ptr< class Processor >( new Processor );
}

Manager::~Manager( ) {
}

void Manager::update( ) {
	_processor->update( );

	if ( _processor->isFin( ) ) {
		std::shared_ptr< class Application > app = Application::getInstance( );
		app->fin( );
	}
}