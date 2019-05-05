#ifndef __Item__
#define __Item__

#include "entity.h"

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent);
	~Item();

	void Describe() const;

public:
};

#endif //__Item__