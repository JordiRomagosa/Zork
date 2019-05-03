#include "creature.h"


Creature::Creature(const char* title, const char* description, int endurance, int damage, int protection, Room* room) :
	Entity(title, description, room),
	endurance(endurance), damage(damage), protection(protection)
{
	type = CREATURE;
}

Creature::~Creature()
{}

Room * Creature::GetRoom() const
{
	return (Room*)parent;
}

bool Creature::IsAlive() const
{
	return endurance > 0;
}
