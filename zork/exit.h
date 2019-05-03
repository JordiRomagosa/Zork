#ifndef __Exit__
#define __Exit__

#include "entity.h"
#include "room.h"

class Room;

enum ExitDirection
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

class Exit : public Entity
{
public:
	Exit(const char* name, const char* description, ExitDirection direction, Room* source, Room* destination);
	~Exit();

	void Describe() const;

public:
	ExitDirection direction;
	Room* destination;
};

#endif //__Exit__