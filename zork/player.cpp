#include "player.h"



Player::Player(const char* name, const char* description, Room* room) :
	Creature(name, description, 10, 1, 0, room)
{
	type = PLAYER;
}


Player::~Player()
{
}

bool Player::Take(const vector<string>& args)
{
	if(!IsAlive())
		return false;

	Item* item = (Item*)parent->Find(args[1], ITEM);
	if (item == NULL)
	{
		cout << "There is no item with that name in this room." << endl;
		return false;
	}

	cout << "You take ";
	item->Describe();
	cout << "." << endl;

	item->ChangeParentTo(this);

	return true;
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
