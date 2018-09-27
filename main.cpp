#include <memory>
#include "Application.h"
#include "Error.h"
#include "Processor.h"
#include "Keyboard.h"

int main( ) {
	Application::initialize( );
	std::shared_ptr< class Application > app = Application::getInstance( );

	app->addTask( Processor::getTag( ), std::shared_ptr< class Task >( new Processor ) );
	app->addTask( Error::getTag( )  , std::shared_ptr< class Task >( new Error ) );
	app->addTask( Keyboard::getTag( ), std::shared_ptr< class Task >( new Keyboard ) );

	app->run( );
	Application::finalize( );
    return 0;
}