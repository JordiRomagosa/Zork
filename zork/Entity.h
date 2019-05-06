#ifndef __Entity__
#define __Entity__

#include <iostream>
#include <list>
#include <string>
#include "globals.h"

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	CREATURE,
	PLAYER,
	ITEM,
	NPC
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	virtual void Describe();
	virtual void Update();

	void ChangeParentTo(Entity* new_parent);
	Entity* Find(const string& name, EntityType type) const;
	void FindAll(EntityType type, list<Entity*>& list_to_fill) const;

public:
	EntityType type;
	string name;
	string description;

	Entity* parent;
	list<Entity*> contains;
};

#endif //__Entity__