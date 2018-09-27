#include "Application.h"
#include "Task.h"
#include "Keyboard.h"
#include <conio.h>

std::shared_ptr< Application > Application::_instance;

const int ESCAPE = 0x1b;

Application::Application( ) :
_fin( false ) {
}

Application::~Application( ) {
}

std::shared_ptr< class Application > Application::getInstance( ) {
	return _instance;
}

void Application::finalize( ) {
	if ( _instance ) {
		_instance.reset( );
	}
}

void Application::initialize( ) {
	if ( !_instance ) {
		_instance = std::shared_ptr< Application >( new Application );
	}
}

void Application::run( ) {
	// initialize
	for ( std::pair< std::string, std::shared_ptr< class Task > > task : _task ) {
		task.second->initialize( );
	}

	// keyborad
	std::shared_ptr< class Keyboard > keyboard;
	if ( _task.count( Keyboard::getTag( ) ) < 1 ) {
		keyboard = std::shared_ptr< Keyboard >( new Keyboard );
	} else {
		keyboard = std::dynamic_pointer_cast< Keyboard >( getTask( Keyboard::getTag( ) ) );
	}


	// run process 
	while ( !_fin ) {
		for ( std::pair< std::string, std::shared_ptr< class Task > > task : _task ) {
			task.second->update( );
		}

		if ( keyboard->getKey( ) == ESCAPE ) {
			break;
		}
	}
}

void Application::fin( ) {
	_fin = true;
}

void Application::addTask( std::string tag, std::shared_ptr< class Task > task ) {
	_task[ tag ] = task;
}

std::shared_ptr< class Task > Application::getTask( std::string tag ) {
	std::shared_ptr< class Task > task;
	if ( _task.find( tag ) != _task.end( ) ) {
		task = _task[ tag ];
	}

	return task;
}
