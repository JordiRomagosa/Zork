#include "world.h"


World::World()
{
	//Rooms
	Room* village = new Room("the village", "You are inside the village. There are a few houses and an inn.");
	Room* clearing = new Room("a clearing", "You are in a clearing inside the forest. The grass is short here.");
	Room* forest1 = new Room("a forest", "You are surrounded by trees in all directions. You feel like it is easy to get lost here.");
	Room* forest2 = new Room("a forest", "You are surrounded by trees in all directions. You feel like it is easy to get lost here.");
	Room* forest3 = new Room("a forest", "You are surrounded by trees in all directions. You feel like it is easy to get lost here.");
	Room* forest4 = new Room("a forest", "You are surrounded by trees in all directions. You feel like it is easy to get lost here.");
	Room* forest5 = new Room("a forest", "You are surrounded by trees in all directions. You feel like it is easy to get lost here.");
	Room* cave = new Room("front of a cave", "The inside is too dark to see anything, but you feel like something staring at you from inside.");


	entities.push_back(village);
	entities.push_back(clearing);
	entities.push_back(forest1);
	entities.push_back(forest2);
	entities.push_back(forest3);
	entities.push_back(forest4);
	entities.push_back(forest5);
	entities.push_back(cave);

	//Exits
	entities.push_back(new Exit("path", "a small path that goes inside the forest", SOUTH, village, forest1));
	entities.push_back(new Exit("path", "a small path that goes to the village", NORTH, forest1, village));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", SOUTH, forest1, clearing));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", NORTH, clearing, forest1));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", WEST, clearing, forest2));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", EAST, forest2, clearing));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", EAST, clearing, forest5));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", WEST, forest5, clearing));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", NORTH, forest5, forest4));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", SOUTH, forest4, forest5));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", WEST, forest4, forest1));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", EAST, forest1, forest4));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", EAST, forest3, forest1));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", WEST, forest1, forest3));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", SOUTH, forest3, forest2));
	entities.push_back(new Exit("animal path", "a passage wide enough to pass through the trees", NORTH, forest2, forest3));
	entities.push_back(new Exit("steep slope", "the side of a mountain, with a steep slope, that leads to a cave", EAST, forest5, cave));
	entities.push_back(new Exit("steep slope", "the side of a mountain, with a steep slope, that leads to the forest", WEST, cave, forest5));

	//Creatures
	entities.push_back(new Npc("rabit", "eating grass calmly", clearing));
	entities.push_back(new Npc("rabit", "eating grass calmly", forest3));
	entities.push_back(new Npc("deer", "looks at you and keeps the distance", forest2));
	entities.push_back(new Npc("wolf", "searching for pray to hunt. Better stay away", cave));

	//Player
	player = new Player("Player", "A legendary hero", village);
	entities.push_back(player);

	//Items
	entities.push_back(new Item("sword", "a rusty but sturdy sword", GENERAL, clearing));
	entities.push_back(new Item("branch", "simple branch", GENERAL, forest1));
	entities.push_back(new Item("branch", "simple branch", GENERAL, forest5));
	entities.push_back(new Item("branch", "simple branch", GENERAL, forest3));
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
		MovePlayer(NORTH);
	else if (Same(args[0], "south"))
		MovePlayer(SOUTH);
	else if (Same(args[0], "east"))
		MovePlayer(EAST);
	else if (Same(args[0], "west"))
		MovePlayer(WEST);

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

void World::MovePlayer(ExitDirection direction)
{
	if (player->MoveDirection(direction))
	{
		//move creatures
		for (list<Entity*>::const_iterator it = entities.begin(); it != entities.cend(); ++it)
		{
			if ((*it)->type == NPC)
			{
				Npc* npc = (Npc*)(*it);
				npc->Update();
			}
		}
		player->Look();
	}
	else
		cout << "You can't move in this direction." << endl;
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
