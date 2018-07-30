#include "Keyboard.h"
#include "Application.h"
#include <conio.h>

std::shared_ptr< class Keyboard > Keyboard::getTask( ) {
	return std::dynamic_pointer_cast< class Keyboard >( Application::getInstance( )->getTask( getTag( ) ) );
}

Keyboard::Keyboard( ) :
_key( '\0' ) {
}

Keyboard::~Keyboard( ) {
}

void Keyboard::update( ) {
	if ( _kbhit( ) ) {
		_key = _getch( );
	} else {
		_key = '\0';
	}
}

char Keyboard::getKey( ) const {
	return _key;
}