#include "room.h"

Room::Room(const char * name, const char * description) :
	Entity(name, description, NULL)
{
	type = ROOM;
}

Room::~Room()
{
}

void Room::Describe() const
{
	cout << "You are in " << name << ". " << description << endl;


	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
	{
		// List Exits
		if ((*it)->type == EXIT)
		{
			Exit* exit = (Exit*)*it;
			cout << "To the ";
			switch (exit->direction) {
				case NORTH: cout << " north ";
				case SOUTH: cout << " south ";
				case EAST: cout << "east ";
				case WEST: cout << "west ";
			}
			exit->Describe();
		}
	}
}


