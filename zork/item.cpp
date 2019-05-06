#include "item.h"

Item::Item(const char * name, const char * description, ItemType iType, Entity * parent) :
	Entity(name, description, parent)
{
	type = ITEM;
	itemType = iType;
}

Item::~Item()
{
}

void Item::Describe() const
{
	cout << name;
}
