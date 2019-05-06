#ifndef __Player__
#define __Player__

#include "creature.h"

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	bool Take(const vector<string>& args);
	bool Drop(const vector<string>& args);

	void Look();
	bool MoveDirection(ExitDirection direction);

public:
};

#endif //__Player__