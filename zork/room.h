#ifndef __Room__
#define __Room__

#include "entity.h"
#include "exit.h"

class Exit;
enum ExitDirection;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();

	void Describe() const;
	Exit* GetExit(ExitDirection direction);

public:
};

#endif //__Room__