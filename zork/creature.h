#ifndef __Creature__
#define __Creature__

#include "entity.h"
#include "room.h"

class Room;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, int endurance, int damage, int protection, Room* room);
	~Creature();

	Room* GetRoom() const;
	bool IsAlive() const;

public:
	int endurance;
	int damage;
	int protection;
};

#endif //__Creature__