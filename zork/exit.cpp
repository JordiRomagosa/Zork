#include "exit.h"
#include "room.h"

Exit::Exit(const char * name, const char * description, ExitDirection direction, Room * source, Room * destination) :
	Entity(name, description, source),
	direction(direction), destination(destination)
{
	type = EXIT;
}

Exit::~Exit()
{
}

void Exit::Describe() const
{
	cout << description << ".";
}
