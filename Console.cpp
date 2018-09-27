#include "Console.h"
#include "Application.h"

std::shared_ptr< class Console > Console::getTask( ) {
	return std::dynamic_pointer_cast< Console >( Application::getInstance( )->getTask( getTag( ) ) );
}

Console::Console( ) {
}

Console::~Console( ) {
}

void Console::update( ) {
	system( "cls" );

}