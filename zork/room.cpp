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

}


