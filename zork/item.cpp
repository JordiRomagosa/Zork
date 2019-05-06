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
	if (itemType == BAG)
	{
		list<Entity*> items;
		FindAll(ITEM, items);

		if (items.size() > 0)
		{
			cout << " that contains (";
			for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
			{
				Item* item = (Item*)(*it);
				item->Describe();
				cout << ", ";
			}
			cout << "\b\b)";
		}
	}
}
