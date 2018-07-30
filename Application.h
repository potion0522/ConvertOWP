#pragma once
#include <memory>
#include <string>
#include <map>

class Application {
public:
	Application( );
	virtual ~Application( );

public:
	static void finalize( );
	static void initialize( );
	static std::shared_ptr< class Application > getInstance( );

public:
	void run( );

public:
	void fin( );
	void addTask( std::string tag, std::shared_ptr< class Task > task );
	std::shared_ptr< class Task > getTask( std::string tag );

private:
	static std::shared_ptr< class Application > _instance;
	std::map< std::string, std::shared_ptr< class Task > > _task;

	bool _fin;
};

