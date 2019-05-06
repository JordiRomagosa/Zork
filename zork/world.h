#ifndef __World__
#define __World__

#include <list>
#include "entity.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include "creature.h"
#include "npc.h"
#include "player.h"

class Entity;
class Player;

class World
{
public:
	World();
	~World();

	bool Command(vector<string>& args);
	void MovePlayer(ExitDirection direction);
	void Help();

public:
	list<Entity*> entities;
	Player* player;
};

#endif //__World__