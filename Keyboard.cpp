#include "Keyboard.h"
#include <conio.h>

Keyboard::Keyboard( ) {
}

Keyboard::~Keyboard( ) {
}

char Keyboard::getKey( ) const {
	return _getch( );
}