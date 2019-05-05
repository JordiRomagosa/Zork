#include "world.h"



World::World()
{
	//Rooms
	Room* village = new Room("Village", "You are inside the village. There are a few houses and an inn.");
	Room* forest = new Room("Forest", "You are surrounded by trees in all directions. You feel like it is easy to get lost here.");
	Room* clearing = new Room("Clearing", "You are in a clearing inside the forest. The grass is short here.");

	entities.push_back(village);
	entities.push_back(forest);
	entities.push_back(clearing);

	//Exits
	entities.push_back(new Exit("path", "small path that goes inside the forest", SOUTH, village, forest));
	entities.push_back(new Exit("path", "small path that comes from the forest", NORTH, forest, village));
	entities.push_back(new Exit("animal path", "passage wide enough to pass through the forest", SOUTH, forest, clearing));
	entities.push_back(new Exit("animal path", "passage wide enough to pass through the forest", NORTH, clearing, forest));

	//Creatures
	player = new Player("Player", "A legendary hero", village);
	entities.push_back(player);

	//Items
	entities.push_back(new Item("sword", "a rusty but sturdy sword", clearing));
}


World::~World()
{
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete *it;

	entities.clear();
}

bool World::Command(vector<string>& args)
{
	bool success = true;

	if (Same(args[0], "look"))
		player->Look();
	else if (Same(args[0], "north"))
		player->MoveDirection(NORTH);
	else if (Same(args[0], "south"))
		player->MoveDirection(SOUTH);
	else if (Same(args[0], "east"))
		player->MoveDirection(EAST);
	else if (Same(args[0], "west"))
		player->MoveDirection(WEST);

	else
		success = false;


	return success;
}
