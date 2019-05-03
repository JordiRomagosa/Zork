#include "exit.h"

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
	cout << "there's a " << name << " that connects";
	cout << parent->name << " with " << destination->name;
}
