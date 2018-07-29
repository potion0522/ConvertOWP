#include <memory>
#include "Manager.h"

int main( ) {
	std::shared_ptr< class Manager > manager( new Manager( ) );

	while ( true ) {
		manager->update( );

		if ( manager->isFin( ) ) {
			break;
		}
	}

    return 0;
}