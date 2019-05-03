#ifndef __Player__
#define __Player__

#include "creature.h"

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	void Look();
	bool MoveDirection(ExitDirection direction);

public:
};

#endif //__Player__