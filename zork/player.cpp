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

bool Player::Drop(const vector<string>& args)
{
	if (!IsAlive())
		return false;

	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL)
	{
		cout << "You don't have an item with that name";
		return false;
	}

	cout << "You drop ";
	item->Describe();
	cout << "." << endl;
	item->ChangeParentTo(parent);

	return true;
}

bool Player::Put(const vector<string>& args)
{
	if (!IsAlive())
		return false;

	Item* bag = (Item*)Find(args[3], ITEM);
	Item* item = (Item*)parent->Find(args[1], ITEM);

	if (item == NULL || bag == NULL)
	{
		cout << "It is not possible to put the" << args[1] << " inside " << args[3] << "." << endl;
		return false;
	}

	cout << "You take ";
	item->Describe();
	cout << " and put it inside ";
	bag->Describe();
	cout << "." << endl;
	item->ChangeParentTo(bag);

	return true;

	return false;
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
