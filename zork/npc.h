#ifndef __Npc__
#define __Npc__

#include "creature.h"

class Npc : public Creature
{
public:
	Npc(const char* name, const char* description, Room* room);
	~Npc();

	void Update();
	void Describe() const;
public:
};

#endif //__Npc__