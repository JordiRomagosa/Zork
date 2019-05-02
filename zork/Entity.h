#ifndef __Entity__
#define __Entity__

#include <iostream>
#include <list>
#include <string>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	virtual void Describe();
	virtual void Update();

	void ChangeParentTo(Entity* new_parent);

public:
	EntityType type;
	string name;
	string description;

	Entity* parent;
	list<Entity*> contains;
};

#endif __Entity__