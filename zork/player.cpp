#include "player.h"



Player::Player(const char* name, const char* description, Room* room) :
	Creature(name, description, 10, 1, 0, room)
{
	type = PLAYER;
}


Player::~Player()
{
}

void Player::Look()
{
	GetRoom()->Describe();
}

bool Player::MoveDirection(ExitDirection direction)
{
	Exit* exit = GetRoom()->GetExit(direction);

	if (exit == NULL)
		return false;

	ChangeParentTo(exit->destination);
	Look();

	return true;
}
