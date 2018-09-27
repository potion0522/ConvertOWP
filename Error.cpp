#include "Error.h"

#include "Application.h"
#include <conio.h>

std::shared_ptr< Error > Error::getTask( ) {
	return std::dynamic_pointer_cast< Error >( Application::getInstance( )->getTask( getTag( ) ) );
}

Error::Error( ) {
}

Error::~Error( ) {
}

void Error::addErrorLog( std::string error_message ) {
	system( "cls" );
	printf( "%s", error_message.c_str( ) );

	getchar( );

	exit( 0 );
}