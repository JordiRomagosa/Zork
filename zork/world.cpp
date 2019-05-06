#include "world.h"



World::World()
{
	//Rooms
	Room* village = new Room("the village", "You are inside the village. There are a few houses and an inn.");
	Room* forest = new Room("a forest", "You are surrounded by trees in all directions. You feel like it is easy to get lost here.");
	Room* clearing = new Room("a clearing", "You are in a clearing inside the forest. The grass is short here.");

	entities.push_back(village);
	entities.push_back(forest);
	entities.push_back(clearing);

	//Exits
	entities.push_back(new Exit("path", "small path that goes inside the forest", SOUTH, village, forest));
	entities.push_back(new Exit("path", "small path that goes to the village", NORTH, forest, village));
	entities.push_back(new Exit("animal path", "passage wide enough to pass through the forest", SOUTH, forest, clearing));
	entities.push_back(new Exit("animal path", "passage wide enough to pass through the forest", NORTH, clearing, forest));

	//Creatures
	player = new Player("Player", "A legendary hero", village);
	entities.push_back(player);

	//Items
	entities.push_back(new Item("sword", "a rusty but sturdy sword", GENERAL, clearing));
	entities.push_back(new Item("branch", "simple branch", GENERAL, clearing));
	entities.push_back(new Item("bag", "a bag to carry other items", BAG, player));
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
		return player->MoveDirection(NORTH);
	else if (Same(args[0], "south"))
		return player->MoveDirection(SOUTH);
	else if (Same(args[0], "east"))
		return player->MoveDirection(EAST);
	else if (Same(args[0], "west"))
		return player->MoveDirection(WEST);

	else if (Same(args[0], "pick") || Same(args[0], "take"))
		player->Take(args);
	else if (Same(args[0], "drop"))
		player->Drop(args);
	else if (Same(args[0], "put") && (Same(args[2], "into") || (Same(args[2], "in"))))
		player->Put(args);
	else if (Same(args[0], "inventory"))
		player->Inventory();

	else if (Same(args[0], "help"))
		Help();

	else
		success = false;


	return success;
}

void World::Help()
{
	cout << "This is a list of the possible commands:" << endl;

	cout << " - LOOK: get a description of your surroundings." << endl;
	cout << " - NORTH, SOUTH, EAST or WEST: move in that direction." << endl;
	cout << " - INVENTORY: get the list of the items you are carrying." << endl;

	cout << " - PICK or TAKE (+ item name): put the item into your inventory." << endl;
	cout << " - PUT (+ item name) IN or INTO (+ item name): put the item inside another item. Only works on bags." << endl;
	cout << " - DROP (+ item name): drop the item. If it is in a bag you are carrying, it will also drop." << endl;
}
