#ifndef __Creature__
#define __Creature__

#include "entity.h"

enum ExitDirection : int;
class Room;
class Exit;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	virtual ~Creature();

	virtual bool MoveDirection(ExitDirection direction);

	Room* GetRoom() const;
	bool IsAlive() const;

public:
};

#endif //__Creature__