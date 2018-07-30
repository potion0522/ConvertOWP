#include <memory>
#include "Application.h"
#include "Manager.h"

int main( ) {
	Application::initialize( );
	std::shared_ptr< class Application > app = Application::getInstance( );

	app->addTask( Manager::getTag( ), std::shared_ptr< class Task >( new Manager ) );

	app->run( );
	Application::finalize( );
    return 0;
}