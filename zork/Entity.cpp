#include "Entity.h"

Entity::Entity(const char * name, const char * description, Entity * parent = NULL) :
	name(name), description(description), parent(parent)
{
	type = ENTITY;

	if (parent != NULL)
		parent->contains.push_back(this);
}

Entity::~Entity()
{
}

void Entity::Describe()
{
	cout << name << ": " << description << endl;
}

void Entity::Update()
{
}

void Entity::ChangeParentTo(Entity * new_parent)
{
	if (parent != NULL)
		parent->contains.remove(this);

	if (new_parent != NULL)
		new_parent->contains.push_back(this);

	parent = new_parent;
}

Entity * Entity::Find(const string & name, EntityType type) const
{
	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
	{
		if ((*it)->type == type)
		{
			if (Same((*it)->name, name))
				return *it;
		}
	}

	return NULL;
}
