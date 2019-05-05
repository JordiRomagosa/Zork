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
				case NORTH: cout << "north "; break;
				case SOUTH: cout << "south "; break;
				case EAST: cout << "east "; break;
				case WEST: cout << "west "; break;
			}
			exit->Describe();
			cout << endl;
		}

		else if ((*it)->type == ITEM)
		{
			Item* item = (Item*)*it;
			cout << "You can see a ";
			item->Describe();
			cout << " on the floor." << endl;
		}
	}
}

Exit * Room::GetExit(ExitDirection direction)
{
	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
	{
		if ((*it)->type == EXIT)
		{
			Exit* exit = (Exit*)*it;
			if (exit->direction == direction)
				return exit;
		}
	}

	return NULL;
}


