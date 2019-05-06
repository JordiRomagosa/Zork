#include "npc.h"
#include "exit.h"


Npc::Npc(const char * name, const char * description, Room * room) :
	Creature(name, description, room)
{
	type = NPC;
}

Npc::~Npc()
{
}

void Npc::Update()
{
	if (Random(0, 2) == 0) {
		int direction = Random(0, 3);
		switch (direction)
		{
			case 0: MoveDirection(NORTH);  break;
			case 1: MoveDirection(SOUTH);  break;
			case 2: MoveDirection(EAST);  break;
			case 3: MoveDirection(WEST);  break;
		}
	}
}

void Npc::Describe() const
{
	cout << "a " << name << " that is " << description << ".";
}
