#ifndef __World__
#define __World__

#include <list>
#include "entity.h"
#include "exit.h"
#include "item.h"
#include "player.h"
#include "room.h"

class Entity;
class Player;

class World
{
public:
	World();
	~World();

	bool Command(vector<string>& args);
	void Help();

public:
	list<Entity*> entities;
	Player* player;
};

#endif //__World__