#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	void ChangeParentTo(Entity* new_parent);

public:
	EntityType type;
	string name;
	string description;

	Entity* parent;
	list<Entity*> contains;
};

#endif __Entity__