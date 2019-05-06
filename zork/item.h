#ifndef __Item__
#define __Item__

#include "entity.h"

enum ItemType
{
	GENERAL,
	BAG
};

class Item : public Entity
{
public:
	Item(const char* name, const char* description, ItemType iType, Entity* parent);
	~Item();

	void Describe() const;

public:
	ItemType itemType;
};

#endif //__Item__