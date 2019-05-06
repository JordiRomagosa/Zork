#include "creature.h"
#include "room.h"
#include "exit.h"


Creature::Creature(const char* name, const char* description, Room* room) :
	Entity(name, description, room)
{
	type = CREATURE;
}

Creature::~Creature()
{}

bool Creature::MoveDirection(ExitDirection direction)
{
	Exit* exit = GetRoom()->GetExit(direction);

	if (exit == NULL)
		return false;

	ChangeParentTo(exit->destination);

	return true;
}

Room * Creature::GetRoom() const
{
	return (Room*)parent;
}

bool Creature::IsAlive() const
{
	return true;
}
