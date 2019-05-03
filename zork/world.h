#ifndef __World__
#define __World__

#include <list>
#include "entity.h"
#include "exit.h"
#include "room.h"

class Entity;

class World
{
public:
	World();
	~World();

public:
	list<Entity*> entities;
};

#endif //__World__